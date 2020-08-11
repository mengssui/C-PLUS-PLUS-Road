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