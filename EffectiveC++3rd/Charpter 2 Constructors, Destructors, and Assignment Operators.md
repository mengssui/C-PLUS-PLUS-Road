- [Charpter 2 Constructors, Destructors, and Assignment Operators](#charpter-2-constructors-destructors-and-assignment-operators)
  - [Item 5: Know what functions C++ silently write and calls](#item-5-know-what-functions-c-silently-write-and-calls)
  - [Item 6: Explicitly disallow the use of compiler-generated functions if you don't want.](#item-6-explicitly-disallow-the-use-of-compiler-generated-functions-if-you-dont-want)
  - [Item 7: Declare destructors virtual in polymorphic base classes](#item-7-declare-destructors-virtual-in-polymorphic-base-classes)
  - [Item 8: Prevent exceptions from leaving destructors.](#item-8-prevent-exceptions-from-leaving-destructors)
  - [Item 9: Never call virtual functions during construction or destruction.](#item-9-never-call-virtual-functions-during-construction-or-destruction)
  - [Item 10: Have assignment operators return a reference to *this](#item-10-have-assignment-operators-return-a-reference-to-this)
  - [Item 11: Handle assignment to self in operator = .](#item-11-handle-assignment-to-self-in-operator--)
  - [Item 12: Copy all parts of an object](#item-12-copy-all-parts-of-an-object)
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


## Item 9: Never call virtual functions during construction or destruction.
- Due to base class construction is executed early than derived class, when base class executing construction derived class have not initialized.
- Destruction is the same.
  
> **REMEMBER**: 
> 1. Do not call virtual funtions during construction or destruction, because such calls will never go to a more derived class than that of the currently executing.

## Item 10: Have assignment operators return a reference to *this
```cpp
class Widget {
public:
  Widget& operator=(const Widget& rhs) {
    ...
    return *this;
  } 
}
```
> **REMEMBER**：
>
> 1.Have assignment operators return a reference to *this

## Item 11: Handle assignment to self in operator = .
- tradition way: use identity test, but it's not exception-safe.
```cpp
Widget& Widget::operator=(const Widget& rhs) {
  if (this == &rhs) return *this;
  delete pb;
  pb = new Bitmap(*rhs.pb); //not exveption-safe if destruction fail.
  return *this;
}
```
```cpp
//better way: focus on exception safe not 
Widget& Widget::operator=(const Widget& rhs) {
  Bitmap* pOrig = pb;
  pb = new Bitmap(*rhs.pb);
  delete pOrig;
  return *this;
}
```
- The best way is use copy and swap. (See Item 29)

> **REMEMBER**:
> 1. Make sure operator= is well-behaved when an object is assigned to itself.Techniques include coparing addresses of source and target objects, careful statement ordering ,and copy-and-swap
> 2. Make sure that any function operating on more than one object behaves correctly if two or more of the objects are the same.

## Item 12: Copy all parts of an object

- In this book, call copy assignemt and copy construction COPYING FUNCTIONS.
- 
> **REMEMBER**:
> 1. Copying funtions should be sure to copy all of an object's data members and all of its base class parts
> 2. Do not try to implement one of the copying funtions in terms of the other. Instead, put common functionality in a third funtion that both call.