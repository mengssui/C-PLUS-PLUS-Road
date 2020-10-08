# Charpter 3 Resource Manangement

---

[toc]

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

> **REMEMBER**: 
> 1. Copy an RAII object entails copying the resource it manages, so the copying behavior of the resource determines the copying behavior of the RAII object.
> 2. Common RAII class copying behaviors are disallowing copying and performing reference counting, but other behaviors are possible.

## Item 15: Provide access to raw resources in resource-management classes
- share_ptr provide get() member function to get the raw resource.
- It also reload pointer dereferenceing and operator-> and operator*.

> **REMEMBER**:
>
> 1. Access may be via explict conversion or implict conversion. In general, explict conversion is safer, but implict conversion is more convenient for clients.

## Item 16: Use the same form in corresponding uses of new and delete.
- use new  then use delete
- use new [] then use delete []

## Item 17: Store newed obejects in smart pointers in standalone statements
```cpp
int priority();
processWidget(std::share_ptr<Widget> pw, int priority);
//BAD
//the function have three step with unsure order:
//maybe one order is:
// 1. Execute new widget
// 2. call priority();
// 3. call share_ptr constructor
// if step is failed, then the pointer will be lost.
processWidget(std::share_ptr<Widget>(new Widget), priority());

// GOOD
//a solution to the problem above: use a separate statement to create the Widget.
std::share_ptr<Widget> pw(new Widget);
processWidget(pw, priority());
```
> **REMEMBER**:
>
> 1. Store newed objects in smart pointers in standalone statement. Failure to do this can lead to subtle resource leaks when exceptions are thrown.