# Charpter 6 Inheritance and Object-Oriented Design

---

[toc]

## Item 32: make sure public inheritance models "is - a"

> **REMEMBER:**
>
> 1. Public inheritance means "is-a". Everything that applies to base classes must also apply to derived classes, because every derived class object is a base class  object.



## Item 33: Avoid hiding inherited names

> **REMEMBERS:**
>
> 1. Names in derived classes hide names in base classes. Under public inheritance, this is never desirable.
> 2. To make hidden names visible again, employ using declarations or forwarding functions.



## Item 34: Differentiate between inheritance of interface and inheritance of implementation

> **REMEMBER:**
>
> 1. Inheritance of interface is different from inheritance of implementation. Under public inheritance, derived classes always inherit base class interfaces.
> 2. Pure virtual functions specify inheritance of interface only. 
> 3. Simple (impure) virtual functions specify inheritance of interface plus inheritance of a default implementation. 
> 4.  Non-virtual functions specify inheritance of interface plus inheritance of a mandatory implementation.



## Item 35: Consider alternatives to virtual functions.

> **REMEMBER:**
>
> 1. Alternatives to virtual functions include the NVI idiom and various forms of the Strategy design pattern. The NVI idiom is itself an example of the Template Method design pattern. 
> 2. A disadvantage of moving functionality from a member function to a function outside the class is that the non-member function lacks access to the class's non-public members. 
> 3. tr1::function objects act like generalized function pointers. Such objects support all callable entities compatible with a given target signature.



## Item 36: Never redefine an inherited non-virtual function

> **REMEMBER THE TITLE**



## Item 37: Never redefine a function's inherited default parameter value

> **REMEMBER:**
>
> 1. Never redefine an inherited default parameter value, because default parameter values are statically bound, while virtual functions  the only functions you should be overriding  are dynamically bound. 



## Item 38: Model "has a" or "is-implemented-in-terms-of" through composition

> **REMEMBER:**
>
> 1. Composition has meanings completely different from that of public inheritance. 
> 2. In the application domain, composition means has-a. In the implementation domain, it means is-implemented-in-terms-of.



## Item 39: Use private inheritance judiciously

> **REMEMBER:**
>
> 1. Private inheritance means is-implemented-in-terms of. It's usually inferior to composition, but it makes sense when a derived class needs access to protected base class members or needs to redefine inherited virtual functions. 
> 2.  Unlike composition, private inheritance can enable the empty base optimization. This can be important for library developers who strive to minimize object sizes.



