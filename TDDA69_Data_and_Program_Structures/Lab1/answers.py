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
            iter(successor(lower), term(lower) + result)
    return iter(lower, 0)

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

# TODO: Work needed
def product(lower, upper):
    def product_iter(lower, result):
        if lower > upper:
            return result
        else:
            return product_iter(lower + 1, result * lower)
    return product_iter(lower, 1)

