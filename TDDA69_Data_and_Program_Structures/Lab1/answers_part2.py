""" 2.1 Consider the following code:

    def f():
        f()

    def test(x, y):
        return 0 if x == 0 else y

    What would happen if we evaluated the call test(0, f()) in a language with
    normal order evaluation or a general lazy language (such as Haskell)? Why?
    In a language with applicative-order evaluation?

    Answer here: """

x = 10
def f():
    print("In f: ", x)
def g(x):
    print("In g: ", x)
    f()
def keep_val(value):
    def f():
        print("--- x={0}, value={1}\n".format(x, value))
    return f

print_mess = keep_val("Stored")
value = "New and updated."
print_mess()
g(5000)
x = 0
g(5000)
