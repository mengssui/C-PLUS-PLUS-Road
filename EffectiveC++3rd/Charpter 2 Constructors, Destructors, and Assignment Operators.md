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