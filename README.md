# LearningCPP
LearnCpp
For：To Learn C++ ，not well for LV0，but Im OG,

# 6.30
增加仿函数，map容器，lambda表达式，函数指针在数组中的运用等知识点。

# 7.04
增加system函数使用和一种lambda表达式

# 7.07
增加类的初始化列的相关知识  
增加线程以及promise/future用于跟踪线程内变量的相关知识

# 7.08
增加main参数传入相关知识 仍存在遗留问题  
遗留问题一： 关于copy函数和argv变量的嵌套使用  
遗留问题二： list的地址不连续，为何可以用iterator迭代器累加求值（猜测与迭代器适配器有关）

# 7.16
增加std::move() 右值赋值表达式相关知识  
遗留问题三：调用move(int)时，原值依旧保持，而调用move(std::string)时，原值被清空，为什么int会保留？  
解答问题二：list的迭代器类型为双向迭代器类型，list的iterator为类之中，其中有对++进行操作符重载，所以地址不是简单的累加。  

# 7.18
增加static_cast相关知识，以及小数常量一般被定义为double，若需要说明则在数字后加上F.  
解答问题三：std::move()源码只返回输入形参的右值引用，即static_cast<std::string&&>(param).string为类,与int等有本质上的区别.在string的移动构造函数中，变量交换后则原来将指向空指针,导致变量为空,但仍有size.  

# 7.28  
增加类构造函数重载中相关注意的事项，构造函数中初始列和默认传参冲突等相关内容  

# 9.07  
增加了二级指针的内容，实现对类私有成员的地址赋值和返回使用。  
增加了对deque和queue的大小说明。

# 11.14
增加NVI(Non-Virtual-Interface)技术,通过接口与实现隔离的方式，**将具体实现的函数设置为private形式，而接口函数继续保持public**，子类通过自己去写具体实现的方式，同样设置为private，那么当实例化子类时，可以调用到子类的pritva具体实现函数。是除了使用Virtual技术的继承方式，牛逼!  
增加不应重新定义继承而来的缺省参数值，因为缺省参数值是**静态绑定**的，当某基类指针实例化子类时，该参数仍旧是使用**基类**的缺省参数值。  

# 11.15  
增加模板基类相关知识  

# 11.20  
增加bitset相关知识和typedef相关内容  
增加list中splice库函数的使用方式（从一个list中转移变量至另一个list中）  
增加advance库函数的使用(移动指针)  

# 11.21  
增加C++环境中函数类型强制转换方式的相关知识  
增加类大小的计算方式等相关知识  

# 11.22  
增加**多态与数组不要共用**的知识点，因为若数组类型为基类时存放子类，在对数组进行delete时，仍会调用其基类的析构函数。  
增加**对带有参数传入的构造函数对应的类的数组进行统一实例化**的方法，思路为创建类指针的数组，通过循环依次初始化。另一种方法是直接向内存分配目标数量的类的内存，通过强制转换为类数组变量类型，之后再通过new的方式进行实例化。(此方法不进行编写)

