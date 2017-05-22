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

# 第2章 构造函数语意学（The Semantics of Constructor）

编译器背着程序员做了太多事情

explicit之所以被导入这个语言，就是为了给程序员提供一种方法，使他们能够

制止“单一参数的constructor”被当作一个conversion运算符

## 2.1 Default Constructor的构造操作

C++ Annotated Reference Manual（ARM），，，中的Section 12.1,，，：“default constructions。。。。。。在需要的时候被编译器产生出来”

一个是程序的需要，，，一个是编译器的需要，，，

C++ Standard已经修改了ARM的中的说法，，，Section 12.1,，，：

对于class X，如果没有任何user-declared constructor，那么会有一个default constructor被隐式（implicity）声明出来......一个被隐式声明出来的default constructor将是一个trivial（浅薄而无能的，没啥用的）constructor......

**"带有 Default Constructor" 的 Member Class Object**

编译器如何避免合成出多个default constructor，，，解决方法是把合成的，，，都以inline方式完成

被合成的default constructor只满足编译器的需要

如果有多个class member objects都要求constructor初始化操作，，，

C++语言要求以“member object在class中的声明顺序”来调用各个constructors

**"带有 Default Constructor" 的 Base Class**

**"带有一个Virtual Function" 的 Class**

另有两种情况，也需要合成default constructor：

1. class声明（或继承）一个virtual function
2. class派生自一个继承串链，其中有一个或更多的virtual base classes

下面两个扩张行动会在编译期间发生：

1. ，，，vtbl，，，
2. ，，，vptr，，，

**"带有一个 Virtual Base Class" 的 Class**

必须使virtual base class在其每一个derived class object中的位置，能够于执行期间准备妥当

**总结**

有4种情况，会造成“编译器必须为未声明constructor的classes合成一个default constructor”

至于没有存在那4种情况而又没有声明任何constructor的classes，我们说它们拥有的是implicit trivial default constructors，它们实际上并不会被合成出来

在合成的default constructor中，只有base class subobjects和member class objects会被初始化

，，，两个常见的误解：

1. 任何class如果没有定义的default constructor，就会被合成出一个来，，，错
2. 编译器合成出来的default constructor会显式设定“class内部每一个data member的默认值”，，，错

## 2.2 Copy Constructor的构造操作

有三种情况，会以一个object的内容作为另一个class object的初值。

最明显的一种情况当然就是对一个object做显式的初始化操作，

另两种情况是当object被当做参数交给某个函数时，

以及当函数传回一个class object时

**Default Memberwise Initialization**

把每一个内建的或派生的data member的值，从某个object拷贝一份到另一个object身上

**Bitwise Copy Semantics（位逐次拷贝）**

char *

String

**不要Bitwise Copy Semantics！**

4种情况：

1. 当class内含一个member object而后者的class声明有一个copy constructor时
2. 当class继承自一个base class而后者存在一个copy constructor时
3. 当class声明了一个或多个virtual functions时
4. 当class派生自一个继承串链，其中有一个或多个virtual base classes时

**重新设定Virtual Table的指针**

当编译器导入一个vptr到class之中时，该class就不再展现bitwise semantics了。现在，编译器需要合成一个copy constructor以求将vptr适当地初始化

**处理Virtaul Base Class Subobject**

维护“位置的完整性”是编译器的责任。“Bitwise copy semantics”可能会破坏这个位置，所以编译器必须在它合成出来的copy constructor中作出仲裁

## 2.3 程序转化语意学（Program Transformation Semantics）

**显示的初始化操作（Explicit Initialization）**

在严谨的C++用词中，“定义”是指“占用内存”的行为

**参数的初始化（Argument Initialization）**

在编译器实现技术上，有一种策略是导入所谓的临时性object，，，

另一种实现方法是以“拷贝建构”（copy construct）的方式，，，

**返回值的初始化（Return Value Initialization）**

Stroustrup在cfront中的解决方法是一个双阶段转化：

1. 首先加上一个额外参数，类型是class object的一个reference
2. 在return指令之前安插一个copy constructor调用操作

**在使用者层面做优化（Optimization at the User Level）**

定义一个“计算用”的constructor

不过，这种解决方法受到某种批评，怕那些特殊计算用途的constructor可能会大量扩散。

在这个层面上，class的设计是以效率考虑居多，而不是以“支持抽象化”为优先

**在编译器层面做优化（Optimization at the Compiler Level）**

Named Return Value（NRV）优化

饱受批评，，，其中一个原因是，

优化由编译器默默完成，而它是否真的被完成，并不十分清楚

第二个原因是，一旦函数变得比较复杂，优化也就变得比较难以施行

一般而言，面对“以一个class object作为另一个class object的初值”的情形，语言允许编译器有大量的自由发挥空间。

其利益当然是导致机器码产生时有明显的效率提升。缺点是你不能够安全地规划你的copy constructor的副作用，必须视其执行而定。

**Copy Constructor：要还是不要？**

是否预见class需要大量的memberwise初始化操作，，，如果答案是yes，那么提供一个copy constructor的explicit inline函数实例就非常合理---在“你的编译器提供NRV优化”的前提下。

然而不管使用memcpy()还是memset()，都只有在“classes不含任何由编译器产生的内部members”时才能有效运行。

**摘要**

Copy Constructor的应用，迫使编译器多多少少对你的程序代码做部分转化。

## 2.4 成员们的初始化队伍（Member Initialization List）

要不是经由member initialization list，就是在constructor函数本体之内

在下列情况下，为了让你的程序能够被顺利编译，你必须使用member initialization list：

1. 当初始化一个reference member时;
2. 当初始化一个const member时;
3. 当调用一个base class的constructor，而它拥有一组参数时;
4. 当调用一个member class的constructor，而它拥有一组参数时。

list中项目顺序是由class中的members声明顺序决定的，不是initialization list中的排列顺序决定的。

initialization list的项目被放在explicit user code之前

编译器会对initialization list一一处理并可能重新排序，以反映出members的声明顺序。

它会安插一些代码到constructor体内，并置于任何explicit user code之前

# 第3章 Data语意学（The Semantics of Data）

“永恒的”library，，，准备工作，，，

class X{};

它有一个隐藏的 1 byte 大小，那是被编译器安插进去的一个char。

这使得这一class的两个objects得以在内存中配置独一无二的地址

事实上Y和Z的大小受到三个因素的影响：

1. 语言本身所造成的额外负担
2. 编译器对特殊情况所提供的优化处理
3. Alignment的限制

*在32位计算机上，通常alignment为4bytes（32位），以使bus的“运输量”达到最高效率*

Empty virtual base class，，，virtual interface，，，

，，，在这个策略中，一个empty ，，，被视为derived class object最开头的一部分，，，

编译器之间的潜在差异正说明了C++ 对象模型的演化，，，

，，，种种启发（尝试错误）法于是被引入，提供优化的处理。如果成功，启发法于是就提升为普遍的策略

一个virtual base class subobject只会在derived class中存在一份实例

如果我们在virtual base class X中放置一个（以上）的data members，两种编译器（，，，）就会产生除完全相同的对象布局

C++ Standard并不强制规定如“base class subobjects”或“不同存取层级的data members的排列顺序”这种琐碎细节，，，

每一个class object因此必须有足够的大小以容纳它所有的nonstatic data members。有时候其值可能令你吃惊（，，，），因为它可能比你想象的还大，原因是：

1. 由编译器自动加上的额外data members，用以支持某些语言特性（主要是各种virtaul特性）
2. 因为alignment（边界调整）的需要

## 3.1 Data Member的绑定（The Binding of a Data Member）

C++的两种防御性程序设计风格：

1. 把所有的data members放在class声明起头处，以确保正确的绑定
2. 把所有的inline functions，不管大小都放在class声明之外

C++ Standard以“member scope resolution rules”来精炼这个“rewriting rule”

然而，这对于member function的argument list并不为真。

Argument list中的名称还是会在它们第一次遭遇时被适当地决议（resolved）完成。因此在extern和nested type name之间的非直觉绑定操作还是会发生

上述这个语言状况，仍然需要某种防御性程序风格：请总是把“nested type声明”放在class的起始处。

## 3.2 Data Member的布局（Data Member Layout）

Nonstatic data members在class object中的排列顺序将和其被声明的顺序一样，任何中间介入的static data members，，，都不会被放进对象布局之中

C++ Standard要求，在同一个access section（，，，）中，members的排列只需符合“较晚出现的members在class object中有较高的地址”这一条件即可

目前各家编译器都是把一个以上的access section连锁在一起，依照声明的顺序，成为一个连续区块。Access sections的多寡并不会招来额外负担。

## 3.3 Data Member的存取

**Static Data Members**

每一个member的存取许可，以及与class的关联，并不会导致任何空间上或执行时间上的额外负担

，，，名称冲突，，，编译器的解决方法是暗中对每一个static data member编码（name-mangline）

任何name-mangling做法都有两个要点：

1. 一种算法，推导出独一无二的名称
2. 万一编译系统（或环境工具）必须和使用者交谈，那些独一无二的名称可以轻易被推导回到原来的名称

**Nonstatic Data Members**

只要程序员在一个member functions中直接处理一个nonstatic data member，所谓“implicit class object”（由this指针表达）就会发生

欲对一个nonstatic data member进行存取操作，编译器需要把class object的起始地址加上data member的偏移量（offset）

指向data member的指针，其offset值总是被加上1，这样可以使编译系统区分出“一个指向data member的指针，用以指出class的第一个member”

和“一个指向data member的指针，没有指出任何member”两种情况

每一个nonstatic data member的偏移量（offset）在编译时期即可获知

## 3.4 “继承”与Date Member

**只要继承不要多态（Inheritance without Polymorphism）**

具体继承（concrete inheritance，相对于虚拟继承 virtual inheritance）并不会增加空间或存取时间上的额外负担

经验不足的人可能会重复设计一些相同操作的函数，，，

第二个易犯的错误是，把一个class分解为两层或更多层，有可能会为了“表现class体系之抽象化”

不论是 C 或 C++ 都是这样。一般而言，边界调整（alignment）是由处理器（processor）来决定的

**加上多态（Adding Polymorphism）**

这样的弹性，当然正式面向对象程序设计的中心。支持这样的弹性势必给我们的，，，带来空间和存取时间的额外负担

*，，，最大的一个好处是，你可以把opeartor+=运用在一个Point3d对象和一个Point2d对象身上，，，*

把vptr放在class object的尾端，可以保留base class C struct的对象布局，因而允许在C程序代码中也能使用

把vptr放在class object的前端，对于“在多重继承下，通过指向class members的指针调用virtual function”，会带来一些帮助

**多重继承（Multiple Inheritance）**

单一继承提供了一种“自然多态（natural polymorphism）”形式，，，

base class和derived class的objects都是从相同的地址开始，其间差异只在于derived object比较大，用以多容纳它自己的nonstatic data members

对一个多重派生对象，将其地址指定给“最左端（也就是第一个）base class 的指针”，

情况将和单一继承时相同，因为二者都指向相同的起始地址。

至于第二个或后继的base class的地址指定操作，则需要将地址修改过

，，，对于指针，内部转换操作需要有一个条件测试：，，，

至于reference，则不需要针对可能的 0 值做防卫，因为reference不可能参考到“无物”（no object）

**虚拟继承（Virtual Inheritance）**

要在编译器中支持虚拟继承，，，实现技术的挑战在于，要找到一个足够有效的方法，

将istream和ostream各自维护的一个ios subobject，折叠成一个由iostream维护的单一ios subobject，

并且还可以保存base class和derived class的指针（以及reference）之间的多态指定操作（polymorphism assignments）

在cfront实现模型之下，，，

有两个主要的缺点：

1. 每一个对象必须针对每一个virtual base class背负一个额外的指针
2. 由于虚拟继承串链的加长，导致间接存取层次的增加

，，，第二个问题，，，

MetaWare，，，解决，，，双重指针

，，，第一个问题，，，

Microsoft，，，virtual base class table，，，

Bajarne，，，在virtual function table中放置virtual base class的offset

一般而言，virtual base class最有效的一种运用形式就是：一个抽象的virtual base class，没有任何data members

## 3.5 对象成员的效率（Object Member Efficiency）

assembly语言，，，

在你开始“程序代码层面的优化操作”以加速程序的运行之前，你应该先确实地测试效率，而不是靠着推论与常识判断

单一继承应该不会影响测试的效率

程序员如果关心其程序效率，应该实际测试，不要光凭推论或常识判断或假设。

另一个需要注意的是，优化操作并不一定总是能够有效运行

“间接性”压抑了“把所有运算都移往缓存器执行”的优化能力，但是间接性并不会严重影响非优化程序的执行效率

## 3.6 指向Data Members的指针（Pointer of Data Members）

指向data members的指针，是一个优点神秘但颇有用处的语言特性

C++ Standard允许vptr被放在对象中的任何位置

实际上vptr不是放在对象的头部，就是放在对象的尾部

，，，然而你若去取data members的地址，传回的值总是多1，，，

，，，Visual C++ 做了特殊处理，，，

在多重继承之下，若要将第二个（或后继）base class的指针和一个“与derived class object绑定”之member结合起来，那么将会因为“需要加入offset值”而变得相当复杂

**“指向Members的指针”的效率问题**

为每一个“member存取操作”加上一层间接性（经由已绑定的指针），会使执行时间多出一倍不止，

以“指向member的指针”来存取数据，再一次几乎用掉了双倍时间

虚拟继承所带来的主要冲击是，它妨碍了优化的有效性

额外的间接性会降低“把所有的处理都搬移到缓存器中执行”的优化能力

# 第4章 Function语意学

C++ 支持三种类型的member functions: static、nonstatic和virtual，每一种类型被调用的方式都不相同

，，，可以确定它一定不是static，原因有二：

（1）它直接存取nonstatic数据；
（2）它被声明为const，，，

## 4.1 Member的各种调用方式

原始的“C with Classes”只支持nonstatic member functions

Virtual函数时在20世纪80年代中期被加进来的，，，

Static member functions是最后被引入的一种函数类型，，，1987年，，，

**Nonstatic Member Functions（非静态成员函数）**

C++ 的设计准则之一就是：nonstatic member function至少必须和一般的nonmember function有相同的效率

，，，实际上member function被内化为nonmember的形式。下面就是转换步骤：

1. 改写函数的signature，，，this指针
2. 将每一个“对nonstatic data member的存取操作”改为经由this指针来存取
3. 将member function重新写成一个外部函数，对函数名称进行“mangling”处理，使它在程序中称为独一无二的词汇

*名称的特殊处理（Name Mangling）*

一般而言，member的名称前面会被加上class名称，形成独一无二的命名。

,,,参数链表，，，参数类型，，，

（但如果你声明extern “C”，就会压抑nonmember functions的“mangling”效果）

两个实体如果拥有独一无二的name mangling，那么任何不正确的调用操作在链接时期就因无法决议（resolved）而失败，，，“确保类型安全的链接行为（type-safe linkage）”

如果“返回类型”声明错误，就没办法检查出来

当前的编译系统中，有一种所谓的demangling工具，用来拦截名称并将其转换回去

**Virtual Member Functions（虚拟成员函数）**

明确地调用“Point3d实体”会比较有效率，并因此压制由于虚拟机制而产生的不必要的重复调用操作

如果，，，声明为inline函数会更有效率

“经由一个class object调用一个virtual function”，这种操作应该总是被编译器像对待一般的nonstatic member function一样地加以决议（resolved）

，，，这项优化工程的另一利益是，virtual function的一个inline函数实体可以被扩展（expanded）开来，因而提供极大的效率利益

**Static Member Functions（静态成员函数）**

在引入static member functions之前，C++ 语言要求所有的member functions都必须经由该class的object来调用

“member selection”语法的使用是一种符号上的便利

Static member function由于缺乏this指针，因此差不多等同于nonmember function。它提供了一个意想不到的好处：成为一个callback函数，使我们得以将C++和C-based X Window系统结合，，，

它们也可以成功地应用在线程（threads）函数身上，，，

## 4.2 Virtual Member Functions（虚拟成员函数）

“执行期类型判断法（runtime type resolution）”

或许最直接了当但是成本最高的解决方法就是把必要的信息加载ptr身上，

在这样的策略之下，一个指针（或是一个reference）含有两项信息：

1. 它所参考到的对象的地址
2. 对象类型的某种编码，或是某个结构的地址

在C++中，多态（polymorphism）表示“以一个public base class的指针（或reference），寻址出一个derived class object”的意思

，，，这种多态形式被称为消极的（passive），可以在编译时期完成---virtual base class的情况除外

当被指出的对象真正被使用时，多态也就变成积极的（active）了

runtime type identification（RTTI），，，就能够在执行期查询一个多态的pointer或多态的reference了

识别一个class是否支持多态，唯一适当的方法就是看看它是否有任何virtual function。只要class拥有一个virtual function，它就需要这份额外的执行期信息

，，，需要知道：

*ptr所指对象的真实类型，这可使我们选择正确的z()实体*

*z()实体位置，以便我能够调用它*

在C++中，virtual functions可以在编译时期获知，此外，这一组地址是固定不变的

，，，执行期要做的，只是在特定的virtual table slot中激活virtual function

每一个virtual function都被指派一个固定的索引值

唯一一个在执行期才能知道的东西是：slot4所指的到底是哪一个z()函数实体

### 多重继承下的Virtual Functions

在多重继承中支持virtual function，其复杂度围绕在第二个及后继的base classes身上，以及“必须在执行期调整this指针”这一点

一般规则是，经由指向“第二或后继之base class”的指针（或reference）来调用derived class virtual function

所谓thunk是一小段assembly码，用来（1）以适当的offset值调整指针，（2）跳到virtual function去

用以支持“一个class拥有多个virtual tables”的传统方法是，将每一个tables以外部对象的形式产生出来，并给予独一无二的名称

为了调节执行期链接器的效率，Sun的编译器将多个virtual tables连锁为一个：指向次要表格的指针，可由主要表格名称加上一个offset获得

当函数被认为“足够小”的时候，Sun编译器会提供一个所谓的“split functions”技术：以相同算法产生出两个函数，其中第二个在返回之前，为指针加上必要的offset

，，，OO程序员都会尽量使用小规模的virtual function将操作“局部化”。通常，virtual function的平均大小是 8 行

，，，IBM就是把thunk搂抱在真正被调用的virtual function中，函数一开始先（1）调整this指针，然后才（2）执行程序员所写的函数码

Microsoft以所谓的“address points”来取代thunk策略，即将用来改写别人的那个函数（也就是overriding function）期待获得的是“引入该virtual function之class”（而非derived class）的地址，这就是该函数的“address point”

### 虚拟继承下的Virtual FUnctions

在虚拟继承的情况下要消除thunks，一般而言已经被证明是一项高难度技术

建议，不要再一个virtual base class中声明nonstatic data members

## 4.3 函数的效能

inline函数不只能够节省一般函数调用所带来的额外负担，也提供程序优化的额外机会

每多一层继承，virtual function的执行时间就有明显的增加

局部性的pC class object即使未被我们使用，它还是需要一个constructor---但是我们可以经由消除对局部对象的使用，而消除其constructor的调用操作

## 4.4 指向Member Function的指针（Pointer-to-Member Functions）

指向member function的指针的声明语法，以及指向“member selection运算符”的指针，其作用是作为this指针的空间保留者

使用一个“member function指针”，如果并不用于virtual function、多重继承、virtual base class等情况的话，并不会比使用一个“nonmember function指针”的成本更高

### 支持“指向Virtual Member Functions”的指针

对一个nonstatic member function取其地址，将获得该函数在内存中的地址。

然而面对一个virtual function，其地址在编译时期是未知的，所能知道的仅是virtual function在其相关之virtual table中的索引值

### 在多重继承下，指向Member Functions的指针

有许多编译器在自身内部根据不同的classes特性提供多种指向member functions的指针形式

### “指向Member Functions之指针”的效率

## 4.5 Inline Functions

### 形式参数（Formal Arguments）

### 局部变量（Local Variable）

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
