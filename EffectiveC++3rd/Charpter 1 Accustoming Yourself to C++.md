# Charpter 1:  Accustoming yourself to C++

## Item 1: View C++ as a federation of languages
- there are four sublanguages: 
  - C : blocks, statements, preprocessor, built-in data type, arrays, pointers ...
  - Objected-Oriented C++ : classes, encapsulation, inheritance, polymorphism, virtual ...
  - Template C++ : This is the generic programming part. 
  - STL : containers, iterators, algrithms, function objects...
- for different sublanguages, the effective programming requires maybe changed, don't be surprised.
> **REMEMBER**: Rules for effective C++ programming vary depending on the part you are using.

## Item 2: Prefer const, enum and inline to #define
- It can be also called "prefer the complier to the processor" , because the $#define$ maybe treated as if it's not part of the language.
```cpp
/*BAD*/
//when use this:
#define ASPECT_RATIO 1.23
//when use it but get an error during compilation, you may  get error message about 1.23 rather ASPECT_RATIO. if it's not define in local file ,you maybe confused about that.

/*GOOD*/
//solution is to replace the macro with constant.
const double AspectRatio = 1.23;
//it will enter the symbol table.
```
### two sepcial cases:
> 1.define constant pointers. Usually constant definitons are put in header files. 
```cpp
const char* const author_name = "Mengbw_";
//it's more better to use :
const std:string author_name("Mengbw_");
```
> 2.class-specific constant, we need to make it a member of the class to limit the scope of a constant. Besides, make it a static to ensure existing at most one copy of the constant.  
```cpp
class GamePlayer {
 private:
  static const int n = 5; //const declaration not definition. for integral type can only have declaration if not get it's address
  int score[n];
  ...
}
const int GamePlayer:: n; //definition . put it in an implementation file not a header file.

//OR

class GamePlayer {
 private:
  static const double n; //const declaration not definition

  ...
}
const double GamePlayer:: n = 3;

//if compiler frobid to use static integral class constants for initial values for in-class specification, use enum
class GamePlayer {
 private:
  static const int n = 5; //if not support
  enum { n = 5 };         //you can use enum
  int score[n];
  ...
}
const int GamePlayer:: n;
```
- misuse #define to implement macro that look like functions to reduce overhead of function call
```cpp
/*BAD BAD BAD */
#define CALL(a, b) f(((a > b) ? a : b))  // parenthesize all the arguments in the macro body

/*GOOD GOOD GOOD*/
template <typename T>
inline void call(const T& a, const T& b) {
  f(a > b ? a : b);
}

//inline function obeys scope and access rules but macro can't in general.
```

> **REMEMBER**: 
> - for simple constants, prefer const objects or enums to #define
> - for function-like macro, prefer inline function to #define.

## Item 3: Use const whenever possible.

