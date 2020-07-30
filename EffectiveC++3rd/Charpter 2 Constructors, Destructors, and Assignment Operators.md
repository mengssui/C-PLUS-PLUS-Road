# Charpter 2 Constructors, Destructors, and Assignment Operators

## Item 5: Know what functions C++ silently write and calls
- After process of C++, compiler will declare their own version of copy constructor, copy assignment operator, a destructor and constructors if you don't declare them yourself. All of them are public and inline.
> **REMEMBER**:
> 1. if class have reference member or const members, compilers can't declare copy operator.

## Item 6: Explicitly disallow the use of compiler-generated functions if you don't want.

- if you don't want a class support a funcition, just do not declare the function. but it's not work for the copy constructor and copy assignment operator.
- The solution is declare them yourself and make them private.

```cpp
//not declare in your class, but declare in a base class.
class Uncopyable {
 protected:
  Uncopyable() { }
  ~Uncopyable() { }
 private:
  Uncopyable(const Uncopyable&);
  Uncopyalbe& operator=(const Uncopyable&);
}
//your class
class Myclass : private Uncopyalbe {...};
```

> **REMEMBER**:
> 1. if you don't want use them ,make them private. but in this way ,you friend can also use them and appear error in Linking period.
> 2. Or you can declare a base class with private functions like class Uncopyable. you can know the error in compiling period.
> 
> **NOTE:C11 supprot use delete**:
> 
```cpp
//This is better
Leaf(const Leaf&) = delete;
Leaf& operator=(const Leaf&) = delete;
```

## Item 7: Declare destructors virtual in polymorphic base classes
- When a derived class object is deleted through a pointer to a base class with a non-virtual destructor, It's typically destroy the derived part. (**Partially destroyed**)
- Eliminating the problem is simple: **give the base class a virtual destructor**. In this way, it will destroy the entire object includeing all its derived class parts.

```cpp
class TimeKeeper {
 public:
  TimeKeeper();
  virtual ~TimeKeeper();
  ...
};
TimeKeeper* ptk = getTimeKeeper();
...
delete ptk;
```
- Any class with virtual functions should almost certainly have a virtual destructor.
- vptr 虚指针
- vtbl 虚表
- every class with virtual functions should have relevant vtbl.
- Only a class with virtual functions should declare virtual destructor.
- if a class is not designed for polymorphic base class, they don't need virtual destructor.

> **REMEMBER**:
> 1. Polymorphic base classes should declare virtual destructors.
> 2. if a class has any virtual functions,it should also have a virtual destructor.
> 3. Classes not designed to be base classes or not designed to be used polymorphically should not declare virtual destructors.

## Item 8: Prevent exceptions from leaving destructors.
> **REMEMBER**: 
> 1. Destructors should never emit exceptions. If functions called in a destructor may throw, the destructor should catch any exceptions then swallow them or terminate the program.
> 2. If class clients need to be able to react to exception, the class should provide a regular (not destructor) function that performs the operation.