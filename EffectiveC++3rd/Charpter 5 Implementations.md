# Charpter 5 Implementations

---

[toc]

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



## Item 28: Avoid returning "handles" to object internals.

> **REMEMBER:**
>
> ​	1. Avoid return handles(including reference, pointers, iterators) which point to the internals of the objects.



##  Item 29: Strive for exception-safe code.

- Two requirements for exception safety.
  - Leak no resources
  - Don't allow data structures to become corrupted.
- Exception-safe functions offer one of three guarantees:
  - basic guarantee
  - strong guarantee
  - nothrow guarantee
- **copy and swap strategy** , means  copy one and edit it , if successfully edit then swap.



> **REMEMBER:**
>
> 1. A function can usually offer a guarantee no stronger than the weakest guarantee of the functions it calls.



## Item 30: Understand the ins and outs of inlining.

- There is no free lunch, too many inlining functions may increase the size of your object  code. But on the other hand, if an inline function body is very short, the code generated for the function body may be smaller than the code generated for a fucntion call.  if that is the case, inlining the function may actually lead to smalller object code and a higher instruction cache hit rate!
-  Inlining in most C++ programs is a compile-time activity.

> **REMREMBER:**
>
>  	1. Limit most inlining to small, frequently called functions. This facilitates debugging and binary upgradability, minimizes potential code bloat, and maximizes the chances of greater program speed. 
>  	2. Don't declare function templates inline just because they appear in header files

## Item 31: Minimize compilation dependencies between files

> **REMEMBER:**
>
>  	1. The general idea behind minimizing compilation dependencies is to depend on declarations instead of definitions. Two approaches based on this idea are Handle classes and Interface classes.
>  	2. Library header files should exist in full and declaration-only forms. This applies regardless of whether templates are involved.

