
empty = 'empty'
def is_link(s):
    """ s is a linked list if it is empty or a (first, rest) pair. """
    return s == empty or (len(s) == 2 and is_link(s[1]))

def link(first, rest):
    """ Construct a linked list from tis first element and the rest. """
    assert is_link(rest), "rest must be a linked list."
    return [first, rest]

def first(s):
    """ Returns the first element of a linked list s. """
    assert is_link(s), "first only applies to linked lists."
    assert s != empty, "empty linked list has no first element."
    return s[0]

def rest(s):
    """ Return the rest of the elements of a linked list s."""
    assert is_link(s), "rest only applies to linked lists."
    assert s != empty, "empty linked list has no rest."
    return s[1]


def len_link(s):
    """ Returns the length of likned list s. """
    length = 0
    while s != empty:
        s, length = rest(s), length + 1
    return length

def getitem_link(s, i):
    """ Returns the element at index i of linked list s. """
    while i > 0:
        s, i = rest(s), i - 1
    return first(s)

def join_link(s, separator):
    """ Returns a string of all elements in s separated by separator. """
    if s == empty:
        return ""
    elif rest(s) == empty:
        return str(first(s))
    else:
        return str(first(s)) + separator + join_link(rest(s), separator)

if __name__ == '__main__':
    four = link(1, link(2, link(3, link(4, empty))))
    print(first(four))
    print(rest(four))
    
    print(len_link(four))
    print(getitem_link(four, 1))
