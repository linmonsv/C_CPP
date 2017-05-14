# 前言（Stanley B. Lippman）

管理一个软件团队，就像放牧一群骄傲的猫

有三种转换风味是任何对象模型都需要的：

1. 与编译器相关的转换
2. 语言语意转换
3. 程序代码和对象模型的转换

**什么是C++对象模型**

有两个概念可以解释C++对象模型：

1. 语言中直接支持面向对象程序设计的部分
2. 对于各种支持的底层实现机制

完整的virtual functions在编译时期就固定下来了

virtual function calls，一般而言是通过一个表格的索引而决议得知

目前所有编译器对于virtual function的实现法都是使用各个class专属的virtual tabls，大小固定，并且在程序执行前就构造好了

如果一个程序员了解底层实现模型，他就能够写出效率较高的代码，自信心也比较高

“它在你的背后做事情”，，，在抽象性和实际性之间找出平衡点

定位在中级以上的C++程序员

# 第0章 导读

**读者对象**

C++老手分两类：

一种人把语言用的烂熟，OO观念也有;

另一个人不但如此，还对台面下的机制，如编译合成的default constructor、object的内存布局等有莫大的兴趣

了解C++对象模型，绝对有助于你在语言本身以及面向对象观念两方面的层次提升

**推荐**

对象模型是深层结构的知识，关系到“与语言无关、与平台无关、跨网络可执行”软件组件（software component）的基础原理。

也因此，了解C++对象模型，是学习目前软件组件三大规格（COM、CORBA、SOM）的技术基础

如果对COM有兴趣，，，推荐看另一本书：Essential COM， Don Box著，《COM本质论》

# 第1章 关于对象（Object Lessons）

语言本身并没有支持“数据和函数”之间的关联性，，，程序性的（procedural），

由一组“分布在各个以功能为导向的函数中”的算法所驱动，它们所处理的是共同的外部数据

“抽象数据类型（abstract data type，ADT）

从一个软件工程的眼光来看，，，“一个ADT或class hierarchy的数据封装”比“在C程序中程序性地使用全局数据”好

C的吸引力就在于它的精瘦和简易

**加上封装后的布局成本（Layout Costs for Adding Encapsulation）**

C++在布局以及存取时间上的主要额外负担是由virtual引起的

## 1.1 C++ 对象模式（The C++ Object Model）

在C++中，有两种class data members: static 和 nonstatic，以及三种class member functions：static、nonstatic和virtual

**简单对象模型（A Simple Object Model）**

可能是为了尽量减低C++编译器的设计复杂度而开发出来的，陪上的则是空间和执行其的效率

**表格驱动对象模型（A Table-driven Object Model）**

为了对所有的classes的所有objects都有一致的表达方式，另一种对象模型是把所有与memmder相关的信息抽出来，

放在一个data member table和一个member function table之中，class object本身则内含指向这两个表格的指针

**C++ 对象模型（The C++ Object Model）**

Nonstatic，，，static，，，则被存放在个别的，，，

Virtual functions则以两个步骤支持之：

1. 每一个class产生出一堆指向virtual functions的指针，放在表格之中，，，virtual table（vtbl）
2. 每一个class object被安插一个指针，指向相关的virtual table，，，vptr

*加上继承（Adding Inheritance）*

**对象模型如何影响程序（How the Object Model Effects Programs）**

## 1.2 关键词所带来的差异（A Keyword Distinction）

如果不是为了努力维护与C之间的兼容性，C++远可以比现在更简单些

当语言无法区分那是一个声明还是一个表达式（expression）时，我们需要一个超越语言范围的规则，而该规则会将上述式子判断为一个“声明”

，，，，，，

## 1.3 对象的差异（An Object Distinction）

C++程序设计模型直接支持三种programming paradigms（程序设计范式）

1. 程序模型（procedural model）
2. 抽象数据类型模块（abstract data type model， ADT)
3. 面向对象模型（object-oriented model）

**指针的类型（The Type of a Pointer）**

”指针类型“会教导编译器如何解释某个特定地址中的内存内容及其大小

**加上多态之后（Adding Polymorphism）**

弹性（OO）和效率（OB）

# 第2章 构造函数语意学

## 2.1 Default Constructor的构造操作
## 2.2 Copy Constructor的构造操作
## 2.3 程序转化语意学
## 2.4 成员们的初始化队伍

# 第3章 Data语意学

## 3.1 Data Member的绑定
## 3.2 Data Member的布局
## 3.3 Data Member的存取
## 3.4 “继承”与Date Member
## 3.5 对象成员的效率
## 3.6 指向Data Members的指针

# 第4章 Function语意学

## 4.1 Member的各种调用方式
## 4.2 Virtual Member Functions
## 4.3 函数的效能
## 4.4 指向Member Function的指针
## 4.5 Inline Functions

# 第5章 构造、析构、拷贝语意学

## 5.1 “无继承”情况下的对象构造
## 5.2 继承体系下的对象构造
## 5.3 对象复制语意学
## 5.4 对象的效能
## 5.5 析构语意学

# 第6章 执行期语意学

## 6.1 对象的构造和析构
## 6.2 new和delete运算符
## 6.3 临时性对象

# 第7章 站在对象模型的尖端

## 7.1 Template
## 7.2 异常处理
## 7.3 执行期类型识别
## 7.4 效率有了，弹性呢？
