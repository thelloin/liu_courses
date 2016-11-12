README Container Design, Step 3
-------------------------------
From step 2 we have an exception-safe and exception-neutral version of special
member functions for initializing, copying, moving and destroying Container objects.

Here we added clear() and swap() functions, the latter in both a member and a non-member version. The non-member overloading will be a better match for Containers than the generic std::swap(). We use these functions to simplify the implementation of the move constructors, the copy assignment operator and the move assignment operator.

The member swap is implemented using the standard library swap.
The standard library swap guaranteed not to throw if the argument type, T, is nothrow move constructible and nothrow move assignable. Here we can swap pointers and their "copy constructor" and copy assignment operator" cannot throw, so the member swap fulfills the nothrow guarantee. The non-member swap is implemented using the member swap so also this fulfills the nothrow guarantee.