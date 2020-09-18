# 第一章 STL概论

![STL六大部件](C:\Users\MengSansui\AppData\Roaming\Typora\typora-user-images\image-20200902170310728.png)

1. **containers :** 容器，各种数据结构
2. **algorithms :** 算法，函数模板
3. **Iterators : ** 迭代器，实现角度来说，迭代器是一种将*，->，--, ++ 重载的类模板
4. **functors : ** 仿函数，重载了（）调用运算符
5. **adapters ：** 适配器，修饰容器，仿函数，迭代器
6. **allocators ：** 配置器，负责空间配置管理，实现动态空间配置，空间管理，空间释放的类模板



![六大组件关系](C:\Users\MengSansui\AppData\Roaming\Typora\typora-user-images\image-20200902173132786.png)





## 前闭后开空间表示法

任何一个STL算法都遵守前闭后开的准则

