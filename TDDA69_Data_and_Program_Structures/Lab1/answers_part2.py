""" 2.1 Consider the following code:

    def f():
        f()

    def test(x, y):
        return 0 if x == 0 else y

    What would happen if we evaluated the call test(0, f()) in a language with
    normal order evaluation or a general lazy language (such as Haskell)? Why?
    In a language with applicative-order evaluation?

    Answer here: In a normal order evaluation language the call test(0, f()) would
    return 0 because arguments are passed as they are, without evaluation, and
    because the arguments f() never are used it will not be evaluated.
    
    In a language with applicative-order evaluation however the arguments are
    evaluated just before the procedure are applied, like in python. This result
    in that the call f() are evaluated and replaced with the function body, in this
    case f() which are evaluated again. So the evaluation process are caught in a 
    loop and will not terminate. """


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

""" 2.2 a) The output of the above sequence is: 

    --- x=10, value=Stored

    In g:  5000
    In f:  10
    In g:  5000
    In f:  0

    When the function pointer print_mess is created a closure of variable value is
    created where value = "Stored", so when print_mess is called it uses that
    variable and the global value of x.

    When calling g(5000), the first print statement print the value of the parameter
    x which is 5000 and then calls f(). In this function body x refers to the global
    variable x which is 10.

    We then change the global variable x to 0 and calls g(5000) which result in the
    same output except that in the function body of f, x is now 0. """

""" 2.2 b) TODO """

""" 2.2 c) If python had dynamic scoping the output that would change would be 
           In f: 10 --> In f: 5000
           In f: 0  --> In f: 5000

    The reason for this is that in dynamic scoping an identifier is associated with
    the most recent environment. So in out case when we refer to x in f we will not
    look in the global namespace first but instead in the environment of g() and in
    that environment there is a variable x that in both calls is 5000. """

""" 2.3 a) Look at account.py. """

""" 2.3 b) TODO: draw a environment diagram.

    
