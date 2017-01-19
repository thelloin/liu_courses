def compose1(f, g):
    return lambda x: f(g(x))

f = compose1(lambda x: x * x, lambda y: y + 1)

compose2 = lambda f,g: lambda x: f(g(x))

f2 = compose2(lambda x: x * x, lambda y: y + 1)

print(f(12))
print(f2(12))

################################

def trace(fn):
    def wrapped(x):
        print('->', fn, '(', x, ')')
        return fn(x)
    return wrapped

@trace
def triple(x):
    return 3 * x

""" With the decorator @trace the name triple is bound to the returned
    function value of calling trace on the newly defined triple function,
    i.e.
        triple = trace(triple)
"""

print(triple(12))

# Mutual recursion

def is_even(n):
    if n == 0:
        return True
    else:
        return is_odd(n - 1)

def is_odd(n):
    if n == 0:
        return False
    else:
        return is_even(n - 1)

print(is_even(2), is_even(4), is_even(11), is_odd(100))
