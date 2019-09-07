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

