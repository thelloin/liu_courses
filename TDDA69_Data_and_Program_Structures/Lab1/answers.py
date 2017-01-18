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

# TODO

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
print("Call accumulate and accumulate with subtraction as combiner.")
print( accumulate( lambda x, y: x - y, 0, lambda x: x, 1, lambda x: x+1, 5) )
print( accumulate_iter( lambda x, y: x - y, 0, lambda x: x, 1, lambda x: x+1, 5) )

