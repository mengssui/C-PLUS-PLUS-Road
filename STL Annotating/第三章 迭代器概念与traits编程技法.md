# 第三章 迭代器概念与traits编程技法

### 迭代器是一种smart pointer

- 迭代器是行为类似指针的对象，因此最重要的就是重载 operator* 和operator ->

### Traits编程技法

- 理解偏特化：对template参数进行更进一步的条件限制所设计出来的特化版本。

```c++
//类模板
template<typename T>
class C {
    //TODO
};
//对class C 的偏特化,适用于T的原生指针
template<typename T>
class C<T*> {
    //TODO
};
```

萃取（Traits）

```c++
template<typename T>
struct iterator_traits{
    typedef typename T::value_type value_type;
};
//偏特化版本
template<typename T>
struct iterator_traits<T*>{  
	typedef T value_type;
};
```

### 迭代器五个常见的型别

​	要对pointer和pointer-to-const者设计特化版本

- value_type

    表示迭代器所指对象的类型

```c++
template<typename T>
struct iterator_traits{
    typedef typename T::value_type value_type;
};
//对于原生指针，就是最普通的指针
//对pointer的偏特化版本
template<typename T>
struct iterator_traits<T*>{  
	typedef T value_type;
};
//对const-to-pointer的偏特化版本
template<typename T>
struct iterator_traits<const T*>{  
	typedef T value_type;
};
```

- difference_type

    表示两个迭代器之间的距离

```c++
template<typename T>
struct iterator_traits{
    typedef typename T::difference_type difference_type;
};
//对原生指针pointer的偏特化版本
template<typename T>
struct iterator_traits<T*>{  
	typedef ptrdiff_t difference_type;
};
//对原生指针const-to-pointer的偏特化版本
template<typename T>
struct iterator_traits<const T*>{  
	typedef ptrdiff_t difference_type;
};
```

- reference_type

    根据迭代器指的内容是否允许改变，迭代器分为：constant iterators， mutable iterators

    对于mutable iterator解引用操作得到的 是左值（lvalue)

    对于constant iterator解引用获得的右值

```c++
template<typename T>
struct iterator_traits{
    ...
    typedef typename T::reference reference;
};
//对原生指针pointer的偏特化版本
template<typename T>
struct iterator_traits<T*>{  
	typedef T& reference;
};
//对原生指针const-to-pointer的偏特化版本
template<typename T>
struct iterator_traits<const T*>{  
	typedef const T& reference;
};
```

- pointer type

    返回一个pointer指向迭代器所指的内容

```c++
template<typename T>
struct iterator_traits{
    ...
    typedef typename T::pointer pointer;
};
//对原生指针pointer的偏特化版本
template<typename T>
struct iterator_traits<T*>{  
	typedef T* pointer;
};
//对原生指针const-to-pointer的偏特化版本
template<typename T>
struct iterator_traits<const T*>{  
	typedef const T* pointer;
};
```

- iterator_category
```c++
template<typename T>
struct iterator_traits{
    ...
    typedef typename T::iterator_category iterator_category;
};
//对原生指针pointer的偏特化版本，注意原生指针是一种随机的迭代器类型
template<typename T>
struct iterator_traits<T*>{  
    ...
	typedef random_access_interator_tag iterator_category;
};
//对原生指针const-to-pointer的偏特化版本
template<typename T>
struct iterator_traits<const T*>{ 
	...
	typedef const random_access_interator_tag iterator_category;
};
```


​    需要创建一组结构体类型，来分出各种不同的迭代器类型来实现函数重载，让编译器做出重载决议

  迭代器分类

<img src="C:\Users\MengSansui\AppData\Roaming\Typora\typora-user-images\image-20200916110046418.png" alt="image-20200916110046418" style="zoom:50%;" />

<img src="C:\Users\MengSansui\AppData\Roaming\Typora\typora-user-images\image-20200916133751902.png" alt="image-20200916133751902" style="zoom:50%;" />

最大化效率： 设计算法时候，要根据针对某种迭代器提供明确定义，并针对更强化的迭代器提供另一种定义，根据不同情况提供最大效率



在执行时期才决定使用哪一个版本， 会影响程序效率， 最好能够在编译期间就选择正确的版本， 重载函数机制可能达成这个目标。



STL算法有一个命名规则：以算法所能接受之最低阶迭代器类型，来为其迭代器类型参数命名



