README Container Design, Step 2

From step 1 we have a default constructor, a constructor creating a container with n defulat-initialized elements, and a destructor, which are all exception-safe (works properly in the presence of exceptions) and exception-neutral (propagates all exceptions to the caller, without causing any integrity problems in a Container object).

allocate_and_copy()
-------------------

- allocate() might throw, but is exception-safe and exception-neutral (Step 1)

- std::copy() use T::operator=() to copy elements. If any of the assignment fail, copy will throw. The exception is then caught, and the memory referred to by new_start is deallocated. Deallocating the array will cause the destructor to be called for all elements in new_start, copied or not.

- returning new_start, a pointer, cannot throw.

Exception-safe and exception-neutral.

Copy constructor and copy assignment operator
---------------------------------------------
The only possible exception is from allocate_and_copy(), both just propagates any exception, so both are exception-safe and exception-neutral.

Move constructor
----------------
Only pointer values involved, nothing can throw.

Move assignment operator
------------------------
deallocate() cannot throw, otherwise just pointer assignments, which cannot throw.