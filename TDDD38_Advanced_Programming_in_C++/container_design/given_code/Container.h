/*
 * Container.h
 */
#ifndef CONTAINER_H
#define CONTAINER_H

template <typename T>
class Container
{
public:
   // add default constructor to create an empty Container
   // add constructor to create a Container with size n
   // add destructor to do cleanup

private:
   T* start_;
   T* finish_;
   T* end_of_storage_;
};

#endif
