README Container Design, Step 4
-------------------------------
In this step operations for inserting, inspecting and removing elements are implemented, push_back(), back() and pop().

resize_() can fail when allocating new memory, copy x to its place, or copying objects from old storage to the new storage.

When applying copy semantics it's simple to handle problems, just deallocate the new storage and keep the current state of the container. allocate_() is fail-safe, the assignment to x is handled exception-neutral, if copy() fails we handle this in an exception-safe way - resize_() is fail-safe.

According to standard conventions, operations such as back() and pop_back() shall not throw, for example if the container is empty.

What are the requirements on the element type T?
------------------------------------------------

- Defult constructor, should be exception-safe.
- Non-throwing destructor, to be able to guarantee exception-safety.
- Copy-constructor, should be exception-safe.
- Copy assignment operator, should be exception-safe.
- Move constructor and move assignment operator, if available, should not fail.

If an operation throws, it must guarantee that the target object is still a valid T.