

def divisors(n):
    return [1] + [x for x in range(2, n) if n % x == 0]

print( divisors(12) )

# Print all perfect numbers  from 1 to 1000
print( [n for n in range(1, 1000) if sum(divisors(n)) == n] )

# Find minimum perimiter of a rectangle
def width(area, height):
    assert area % height == 0
    return area // height

def perimiter(width, height):
    return 2 * width + 2 * height

def minimum_perimiter(area):
    heights = divisors(area)
    perimiters = [perimiter(width(area, h), h) for h in heights]
    return min(perimiters)

area = 80
print( minimum_perimiter(area) )
print( [minimum_perimiter(n) for n in range(1, 10)] )

###############################
########### Trees #############
###############################

def tree(root, branches=[]):
    for branch in branches:
        assert is_tree(branch), 'branches must be trees'
    return [root] + list(branches)

def root(tree):
    return tree[0]

def branches(tree):
    return tree[1:]

def is_tree(tree):
    if type(tree) != list or len(tree) < 1:
        return False
    for branch in branches(tree):
        if not is_tree(branch):
            return False
    return True

def is_leaf(tree):
    return not branches(tree)

def partition_tree(n, m):
    """ Return a partition tree of n using parts up to m. """
    if n == 0:
        return tree(True)
    elif n < 0 or m == 0:
        return tree(False)
    else:
        left = partition_tree(n-m, m)
        right = partition_tree(n, m-1)
        return tree(m, [left, right])

print( partition_tree(2, 2) )

def print_parts(tree, partition=[]):
    if is_leaf(tree):
        if root(tree):
            print(' + '.join(partition))
    else:
        left, right = branches(tree)
        m = str(root(tree))
        print_parts(left, partition + [m])
        print_parts(right, partition)

print_parts(partition_tree(6, 4))
