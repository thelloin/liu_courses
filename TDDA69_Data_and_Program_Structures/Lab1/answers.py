""" 1.1
    Below are a given a fairly simple example of a recursion sum function:

    def sum(term, lower, successor, upper):
      if lower > upper:
        return 0
      else:
        return term(lower) + sum(term, successor(lower), successor, upper)

    a) Implement sum_iter as a tail-recursive procedure.
"""

def sum_iter(term, lower, successor, upper):
    def iter(lower, result):
        if lower > upper:
            return result
        else:
            return iter(successor(lower), term(lower) + result)
    return iter(lower, 0)

print("Testing sum-iter (expected value 10)")
print(sum_iter( lambda x: x, 1, lambda x: x+1, 4  ))

""" 1.1 b) Explain what makes this a tail recursive function.

    A tail call is when a function call is performed as the final action of a function.
    In this example the function 'iter' calls itself which makes this a tail recursive
    function. The difference from the function sum is that in that function there is a
    term + the recursive call.
    Tail recursion can often be implemented without adding a new stack frame to the call
    stack because there aren't any need for the old stack frame, all the needed information
    is given as arguments with the recursive call.
"""

""" 1.2 a) In a similar fashion, define product and product_iter which computer products.
"""

def product(term, lower, successor, upper):
    def product_iter(lower, result):
        if lower > upper:
            return result
        else:
            return product_iter(successor(lower), term(lower) * result)
    return product_iter(lower, 1)

print("Testing product (expected value 12)")
print(product( lambda x: x, 3, lambda x: x + 1, 4 ))

""" 1.2 b) Define factorial using one of the functions above """

def factorial(term, successor, n):
    return product(term, 1, successor, n)

print("Testing factorial (expected value 24)")
print(factorial(lambda x: x, lambda x: x+1, 4))

""" 1.2 c) Create a program that calculates an approximation of pi by using one of the
    product functions. """

print("Testing calculating pi using Wallis product:")
print(2*product(lambda x: (2*x/(2*x-1))*(2*x/(2*x+1)), 1, lambda x: x+1, 500))

# Testing using sum_iter as the book:
print("Testing calculating pi using sum_iter...")
print(sum_iter(lambda x: 8 / ((4*x-3) * (4*x-1)), 1, lambda x: x+1, 500 ))

""" 1.3 a) Create functions accumulate and accumulate-iter.
    Note. Because this is based on SICP 1.32 I assume that null is the base value
    and that accumulate is a recursive version and accumulate_iter is a iterative
    version. """


def accumulate(combiner, null, term, lower, succ, upper):
    if lower > upper:
        return null
    else:
        return combiner(term(lower), accumulate(combiner, null, term, succ(lower), succ, upper))

print("Testing accumulate for sum (expected value 15)")
print( accumulate( lambda x, y: x + y, 0, lambda x: x, 1, lambda x: x+1, 5) )
print("Testing accumulate for product (expected value 120)")
print( accumulate( lambda x, y: x * y, 1, lambda x: x, 1, lambda x: x+1, 5) )

def accumulate_iter(combiner, null, term, lower, succ, upper):
    def iter(lower, result):
        if lower > upper:
            return result
        else:
            return iter(succ(lower), combiner(result, term(lower)))
    return iter(lower, null)

print("Testing accumulate_iter for sum (expected value 15)")
print( accumulate_iter( lambda x, y: x + y, 0, lambda x: x, 1, lambda x: x+1, 5) )
print("Testing accumulate for product (expected value 120)")
print( accumulate_iter( lambda x, y: x * y, 1, lambda x: x, 1, lambda x: x+1, 5) )

""" 1.3 b) Define product and sum as calls to accumulate and accumulate_iter """

def sum_acc(term, lower, successor, upper):
    return accumulate(lambda x, y: x + y, 0, term, lower, successor, upper)

print("Testing sum_acc (expected value 55)")
print(sum_acc( lambda x: x, 1, lambda x: x+1, 10))

def sum_acc_iter(term, lower, successor, upper):
    return accumulate_iter(lambda x, y: x + y, 0, term, lower, successor, upper)

print("Testing sum_acc_iter (expected value 55)")
print(sum_acc_iter( lambda x: x, 1, lambda x: x+1, 10))

def product_acc(term, lower, successor, upper):
    return accumulate(lambda x, y: x * y, 1, term, lower, successor, upper)

print("Testing product_acc (expected value 6720)")
print(product_acc( lambda x: x, 4, lambda x: x+1, 8))

def product_acc_iter(term, lower, successor, upper):
    return accumulate_iter(lambda x, y: x * y, 1, term, lower, successor, upper)

print("Testing product_acc_iter (expected value 6720)")
print(product_acc_iter( lambda x: x, 4, lambda x: x+1, 8))

""" 1.3 c) Find what property the combiner must have in order for accumulate and
    accumulate_iter to work. 

    The combiner must be associative: (x + y) + z = x + (y + z) """

# Use subtraction (non-associative)
print("Call accumulate and accumulate_iter with subtraction as combiner.")
print( accumulate( lambda x, y: x - y, 0, lambda x: x, 1, lambda x: x+1, 5) )
print( accumulate_iter( lambda x, y: x - y, 0, lambda x: x, 1, lambda x: x+1, 5) )

""" 1.4 a) Create a purely functional, recursive left fold foldl that works on
    indexable sequences. """

def foldl(fn, z, xs):
    if len(xs) == 1:
        return fn(z, xs[0])
    else:
        #return fn(z, foldl(fn, xs[0], xs[1:]))
        return foldl(fn, fn(z, xs[0]), xs[1:])

print("Testing foldl")
print(foldl(lambda x, y: x - y, 0, [1,2,3]))

""" 1.4 b) Create a purely functional, recursive right fold foldr. """

def foldr(fn, z, xs):
    if len(xs) == 1:
        return fn(xs[0], z)
    else:
        return fn(xs[0], foldr(fn, z, xs[1:]))

print("Testing foldr")
print(foldr(lambda x, y: x - y, 0, [1,2,3]))

""" 1.4 c) Define my_map, reverse_r and reverse_l as calls to foldr and foldl. """

def my_map(f, seq):
    """ Returns [f(seq[0]), f(seq[1]), ...]. Uses foldr or foldl. """
    return foldl(lambda x, y: x + [f(y)], [], seq)

def reverse_r(seq):
    """ Returns seq reversed. Uses foldr. """
    return foldr(lambda x, y: y + [x], [], seq)

def reverse_l(seq):
    """ Returns seq reversed. Uses foldl. """
    return foldl(lambda x, y: [y] + x, [], seq)

print("Testing my_map (expected result: [3,4,5,6])")
print(my_map(lambda x: x + 2, [1,2,3,4]))
print("Testing reverse_r (expected result: [4,3,2,1])")
print(reverse_r([1,2,3,4]))
print("Testing reverse_l (expected result: [4,3,2,1])")
print(reverse_l([1,2,3,4]))

""" 1.5 a) Define a function repeat that takes a function f, and int n >= 0
    and returns the function f^n. """

def repeat(f, n):
    if n > 1:
        rep_func = repeat(f, n - 1)
        return lambda x: f(rep_func(x))
    return f # if return lambda x: x, then 1.6 b is working properly but not 1.5a.....

print("Testing repeat (expected value: 625)")
sq = lambda x: x*x
sq_twice = repeat(sq, 2)
print(type(sq_twice))
print(sq_twice(5))

""" 1.5 b) If you were to write a type signature for f above, what would it be? """

# TODO

""" 1.5 c) Define a function compose that takes one-parameters f and g and returns
    f(g(x)). """

def compose(f, g):
    return lambda x: f(g(x))

print("Testing compose: (expected value: 1025)")
print(compose(lambda x: x + 1000, lambda x: x*x)(5))
print("Testing compose: (expected value: 49)")
print(compose(lambda x: x*x, lambda x: x+1)(6))

""" 1.5 d) Use the higher-order function accumulate and compose to create a
    repeated_application that works as repeat. """

def repeated_application(f, n):
    return accumulate(compose, lambda x: x, lambda x: f, 1, lambda x: x+1, n)

print("Testing repeated_application: (expected value 625)")
print(repeated_application(sq, 2)(5))

""" 1.6 a) Write a procedure smooth that takes f as input and returns the smoothed
    version of f with dx = 0.01. """

def smooth(f):
    return lambda x: (f(x-0.01)+f(x)+f(x+0.01))/3

print("Testing smooth")
smoothed_sq = smooth(lambda x: x*x)
print(smoothed_sq(4))

# TODO: not working, NOW it is!!!
def n_fold_smooth(f, n):
    return repeat(smooth, n)(f)

print("Testing n_fold_smooth")
five_smoothed_square = n_fold_smooth(lambda x: x*x, 5)
print(five_smoothed_square(4))
regular_sq = n_fold_smooth(lambda x: x*x, 0)
print(regular_sq(5)) # This gives the wrong answer, probably something wrong with repeat...
