# Charpter 3 Resource Manangement
- Regardless of the resource, it's important that it be released when you're finished with it.
- Common resources:
  - file descriptors
  - mutex locks
  - fonts and brushes in GUI
  - database connections
  - network sockets
  - memory

## Item 13: Use objects to manages resources
- Two way:
  - use managing object, such as share_ptr
  - use destructors.

- share_ptr use delete rather delete[], so take care when use array 

> **REMEMBER**:
> 1. To prevent resouce leaks, use RAII objects that acquire resources in their constructors and release them in their destructors.
> 2. use share_ptr ,unique_ptr, weak_ptr


## Item 14: Think carefully about copying behavior in resouce-managing classes
