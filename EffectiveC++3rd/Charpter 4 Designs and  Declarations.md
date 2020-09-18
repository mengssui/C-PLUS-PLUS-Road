# Charpter 4 Designs and  Declarations

## Item 18: Make interfaces easy to use correctly and hard to use incorrectly

- Way to facilitate correct use include consistency in interfaces and behavioral compatibility with built-in types.
- Way to prevent errors include: creating new types, constraining object values, eliminating client resouce management resopnsibilities.

## Item 19: Treat class design as type design

- For your new type:
  - how to construct and desturct
  - what's difference between initial and assignment
  - what's mean about passed by value.
  - etc....see book.
> **REMEMBER**:
> 1. you must design your class as if you are designing a SL type.
> 2. you should think a lot of things.

## Item 20: Prefer pass-by-value-to-const to pass-by-value
> **REMEMBER**:
> 1. Prefer pass-by-reference-to-const over pass-by-value.It's typically more efficient and it avoids the slicing problem.
> 2. For built-in type and STL iterator and function object types. For them, pass-by-value is usually appropriate.

## Item 21: Don't try to return a reference when you must return an object.
- Never return a pointer or reference to a local stack object or a heap-allocated object.
- Never return a pointer or reference to a local static object because you may need more than one different object

## Item 22: Declare data members private.
```cpp
//you can implement no access, read-only access, write-only access if you use functions to get or set its value.
class AccessLevels {
  public:
    int getReadOnly() const { return readOnly; }
    void setReadWrite(int value) { readWrite = value; }
    int getReadWrite() const { return readWrite; }
    void setWriteOnly(int value) { writeOnly = value; }
  private:
    int noAccess;
    int readOnly;
    int readWrite;
    int writeOnly;
}
```
- Once you have declare a data memeber public or protected and clients have started using it, it's very hard to change anything about that data memeber. Too much code needs to be rewritten, retested, redocumented, or recompiled.
-rteOnly From an encapsulation point of view, there are really only two access levels:
  - private which offers encapsulation
  - everything else which doesn't

> **REMEMBER**:
> 1. Declare data member private. It gives clients syntactically uniform access to data, affords fine-grained access control, allows invariants to be enforced, and offer class authors implementation flexiblity.
> 2.  protected is no more encapsulation than public.

## Item 23: Prefer non-member non-friend functions to memeber functions. 
- The greater something is encapsulated, then , the greater our ability to change it. This is the reason we value encapsulation in the first place: it affords us the flexibility to change things in a way that effects only a limited number of clients.
- The more functions that can access it, the less encapsulated the data.

## Item 24: Declare non-member functions when type conversions should apply to all parameters.
```cc
result = oneHalf * 2;
result = 2 * oneHalf;

result = oneHalf.operator*(2);
result = 2.operator*(oneHalf); //XXXXXX错误XXXXX

//应该将operator*定义为non-member

```


> **REMEMBER**:
>
> 1. If you need type conversions on all parameters to a function(including the one pointed to by the this pointer),the function must be a non-member.

## Item 25：Consider support for a non-throwing swap

- if you want to swap two objects and they have the **pimpi** way ( use pointer to implementation). It's better to swap pointer rather than the object.

  


> **REMEMBER**:
>
> 1. Provide a swap member function when std::swap would be inefficient for your type. Make sure your swap doesn't throw exceptions.
> 2. if you offer a member swap, also offer a non-member swap that calls the memeber.For classes(not templates), specialize std::swap to.
> 3. When calling swap, employ using declaration for std::swap, then call swap without namespace qualification. 
> 4. It's fine to totally specialize std templates for user-defined types, but never try to add something completely new to std.

## Item 26: Postpone variable definitions as long as possible

> **REMEMBER**:
>
> 1. Postpone variable definitions as long as possible. It increases program clarity and improve program efficiency.



## Item 27: Minimize casting.

> **REMEMBER**: 
>
> 1. Avoid casts whenever practical, especially dynamic_casts in performance-sensitive code. If a design requires casting, try to develop a cast-free alternative.
> 2. When casting is necessary, try to hide it inside a function. Clients can then call the function instead of putting casts in their own code.
> 3. Prefer C++-style casts to old-style casts. They are easier to see, and they are more specific about what they do.








