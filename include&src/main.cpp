#include <iostream>
#include "iterator"
#include "vector"
#include "algorithm"
#include "string"
#include "iterator"
#include "Fun.h"
namespace test1
{
	void output(int a, int b);
	void(*ptr)(int, int) = &output;
	auto ptr2 = output;
	template<class T>
	void test(int x, int y, T fun)
	{
		fun(x, y);
	}
	void output(int a, int b)
	{
		std::cout << "output is ready!" << std::endl;
		std::cout << "a : " << a << std::endl;
		std::cout << "b : " << b << std::endl;
	}
}
#include "list"
namespace test2
{
	std::vector<int> vec(4, 4);
	std::list<char> lit1{ '1','2','3','4','5' };
	std::list<char> lit2{ '3','4','5','6','7' };
	std::list<int> lit3{ 13,42,54,12,56 };
	void *output()
	{
		std::cout << "output" <<std::endl;
		return 0;
	}
	//void (*Fun) = &output;
}
namespace test3
{
	//Add testadd;
	class Add //将类名字当成函数名字
	{
	public:
		int operator()(int a,int b)
		{
			return a + b;
		}
	};
	void fun(int a, int b, Add add)
	{
		std::cout << add(a, b) << std::endl;
	}
}

namespace test4
{
	MyStruct StrFun;
	int (*fun[])(int &a, int &b) =
	{
		First,Second,Third
	};
	std::map<Enum, int*> maptest;
	std::map<Enum, int (*)(int&,int&)> maptest2;
	std::map<Enum, int(*)(int&, int&)>::iterator itrmap;
}
namespace test5
{
	template<class T>
	class My_ptr
	{
	public:
		My_ptr(T *p) :_ptr(p) //C++类变量赋值新方法 在构造函数中使用":"可以对变量进行赋值。
		{
			std::cout << "生时获得资源" << std::endl;
		}
		T& operator *()
		{
			return *_ptr;
		}
		T* operator -> ()
		{
			return _ptr;
		}
		~My_ptr()
		{
			std::cout << "死前释放资源" << std::endl;
			//delete _ptr; //delete会发生错误。 似乎是会触发二次释放内存，表示编译器已经释放一次内存了。
		}
	private:
		T *_ptr;
	};
}

namespace test6
{
	auto fun = [](int i)
	{
		std::cout << "lambda test :" << i << std::endl;
	};
}
#include "memory"
namespace test7
{
	//std::unique_ptr<int> ptr = std::make_unique<int>;
	class Test2
	{
	public:
		Test2();

	};
	class Test1
	{
	public:
		Test1();

		Test2 test2;
	};

	Test1::Test1()
		: test2()
	{
	}
	Test2::Test2()
	{
		std::cout << "member initializer and success!" << std::endl;
	}
}
#include "thread"
#include "future"
namespace test8
{
	int num = 0;
	std::promise<int> promiseObj;
	std::future<int> futureObj = promiseObj.get_future();
	void fun(std::promise<int> *a,int *num)
	{
		std::cout << "thread1 start!" << std::endl;
		a->set_value(10);
		(*num)++;
		std::cout << "thread1 over!" << std::endl;
	}

}
namespace test9
{
	std::vector<int> vec(2,9);
	std::vector<int> vec2;
	std::vector<std::string> vec3(2, "test9");
	std::vector<std::string> vec4;
	double i = 3.14; //小常数量会被认为是double型，所以从float转换成int时会告警 “double到float被截断”
}
namespace test10 {
	class Test
	{
	public:
		Test(int x = 0, int y = 0)
			: a(x)
			, b(y)
		{};
		Test()
			: a(1)
			, b(1)
		{};
		int a; int b;
	};

}
#include "queue"
namespace test11 {
	std::queue<int> q;
	std::deque<int> d;
}
namespace test12 {
	const char *ch = "This is ch";
	class A
	{
	public:
		A();
		A(std::string p, const char** Pch)
			: a(p),
			ch(Pch)
			//ch((char *)a.c_str()) 不允许使用c_str传回的指针进行应用，若需要拷贝则使用strcpy
		{}
		std::string Ret() const { return this->a; }
		void ChangeStr() { this->a = "Changed!"; }
		const char** GetChPtr() { return ch; }
		~A() {}
	private:
		std::string a;
		const char **ch;

	};
}
namespace test13 {
    class A
    {
    public:
        int f() { f1();}
        virtual ~A() { std::cout << "~A" << std::endl;}
    private:
        virtual int f1() {std::cout << "A::f1"<< std::endl;}
    };

    class B : public A
    {
    public:
        ~B() {std::cout << "~B" << std::endl;}
    private:
        virtual int f1()  {std::cout << "B::f1" << std::endl;}
    };

}
namespace test14 {
    class A {
    public:
       enum Color {Red = 10, Blue};
       virtual  void fun(Color color = Red) {std::cout << color << std::endl;}

    };

    class B : public A {
    public:
        virtual void fun(Color color = Blue) {std::cout << color << std::endl;}
    };
}
namespace test15 {
    template <typename type>
    class A {
    public:
        type fun() {return i;}
        type i;
    };

    template <typename type>
    class B : public A<type> {
    public:
        type fun2() {return ii;}
        type ii;

    };
}
#include <bitset>
namespace test16 {
    std::bitset<20> bitset1("01011011101111011111");
    std::bitset<6> bitset2("101"); //若不满长度则高位自动补0
    auto ptr = &bitset1;

}
namespace test17 {
    class A {
    public:
        virtual ~A() {};
        int a = 1;
    };

    typedef std::vector<A> Avec;
    typedef Avec::iterator ptrAvec;

}
namespace test18 {
    class A {
    public:
        virtual void fun() { std::cout << "test18::A::fun()" << std::endl;}
    };
    class B : public A {
    public:
        virtual void fun() { std::cout << "test18::B::fun()" << std::endl;}
    };

    B b;
    A a;
    std::vector<A> Avec;
}
namespace test19 {
    std::list<int> list1(5,5);
    std::list<int> list2(5,10);
    auto itr = test19::list1.begin();
}
namespace test20 {
    class A {
    public:
        ~A() { std::cout << "test20::~A" << std::endl;}
        virtual void fun() { std::cout << "test20::A" << std::endl;}
    };
    class B : public A {
    public:
        ~B() { std::cout << "test20::~B" << std::endl;}
        virtual void fun() { std::cout << "test20::B" << std::endl;}
        int b;
    };
    typedef void (*FuncPtr)();
    FuncPtr func[10];
    int fun1() {return 20;}
    B* b = new B[2];
    void clsDelete(A *a) { delete[] a;}
}
namespace test21 {
    class A {
    public:
        A(int a) : m_a(a) {}
        int m_a;
    };
    typedef A* ptrA;
    ptrA *a = new ptrA[5]; //声明一个指针数组，成员为目标类的指针

}
int main(int argc ,char **argv)
{
	std::cout << "Test2-----------------------------------------------------\n";
	for_each(test2::vec.begin(), test2::vec.end(), [](int n) { std::cout << "for_each :n : " << n <<std::endl; });//按顺序输出vector中的内容
	//for_each(test2::vec.begin(), test2::vec.end(), &test2::output);
	copy(test2::lit3.begin(), test2::lit3.end(), std::ostream_iterator<int>(std::cout," "));//将list的内容按顺序以此复制到输出流中，相当于输出内容。
	for (std::list<int>::iterator itr = test2::lit3.begin(); itr != test2::lit3.end(); itr++)
	{
		std::cout << *itr << std::endl;
	}
	std::cout << std::endl << std::endl;//测试std::endl代表回车功能。
	test2::lit3.sort();//测试list的排序功能，因为list内部为链表结构，地址顺序不连续，导致不能使用常规排序方式进行排序。
	for_each(test2::lit3.begin(), test2::lit3.end(), [](int n) {std::cout << n << " "; });//同上
	std::cout << std::endl << std::endl;
	std::cout << *find_first_of(test2::lit1.begin(), test2::lit1.end(), test2::lit2.begin(), test2::lit2.end()) << std::endl; //将两个链表中第一个相同的元素输出，因为函数返回值为第一个链表该元素的指针，需要加*
	// std::cout << []() { return std::less<int>()(10, 12); } << std::endl;
	std::cout << "Test1-----------------------------------------------------\n";
	test1::test(1, 2, &test1::output);//函数地址作为函数参数传入
	test1::test(3, 4, test1::ptr);//同上
	test1::test(5, 6, test1::ptr2);//同上
	std::cout << test2::output << std::endl;
	std::cout << "Test3-----------------------------------------------------\n";
	test3::fun(1, 2, test3::Add()); //这里直接调用类的类型名字作为临时变量是允许的。
	std::cout << "Test4-----------------------------------------------------\n";
	test4::StrFun.a = 1;
	test4::StrFun.b = 2;
	test4::StrFun.Fun = NULL;
	test4::StrFun.Fun = First; //a+b 将函数地址变量直接赋值为另一个函数
	std::cout << test4::StrFun.Fun(test4::StrFun.a, test4::StrFun.b) << std::endl;
	test4::StrFun.Fun = Second; //a-b //同上
	std::cout << test4::StrFun.Fun(test4::StrFun.a, test4::StrFun.b) << std::endl;
	test4::StrFun.Fun = test4::fun[ThirdNum-1]; //a*b //将函数地址变量赋值为某函数返回值类型相同的数组中，达到了可以读取数组中表示的函数参数。
	std::cout << test4::StrFun.Fun(test4::StrFun.a, test4::StrFun.b) << std::endl;
	test4::maptest2[FirstNum] = First;
	test4::maptest2[SecondNum] = Second;
	test4::maptest2.insert(std::pair<Enum, int(*)(int&, int&)>(ThirdNum, Third));
	test4::itrmap = test4::maptest2.find(FirstNum);
	std::cout << test4::itrmap->second(test4::StrFun.a, test4::StrFun.b) << std::endl;
	std::cout << "Test5-----------------------------------------------------\n";
	[](int x) {std::cout << "仿函数学习：" << x << std::endl; }(10); //学习仿函数
	[](int x) ->int {std::cout << "仿函数学习："; std::cout << x << std::endl; return x; }(10);//仿函数返回值
	system("echo system test");
	int a = 100;
	{
		test5::My_ptr<int> p = &a; //My_ptr<int>相当于int智能指针
		std::cout << *p << std::endl;
	}
	std::cout << "Test6-----------------------------------------------------\n";
	test6::fun(1);
	std::cout << "Test7-----------------------------------------------------\n";
	test7::Test1 test1;
	std::cout << "Test8-----------------------------------------------------\n";
	std::thread thread1(test8::fun, &test8::promiseObj,&test8::num);
	thread1.join();
	std::cout << test8::futureObj.get() << std::endl;
	std::cout << test8::num << std::endl;
	std::cout << "Test8-----------------------------------------------------\n";
	std::cout << "argc is " << argc << std::endl;
	for (int i = 1; i < argc; i++)
	{
		std::cout << **(argv+i) << std::endl;;
	}

	for (int i = 1; i < argc; i++)
	{
		std::cout << argv[i] << std::endl;;
	}
	std::cout << (argv + 1) << std::endl;
	//copy((argv+1), (argv+3), std::ostream_iterator<int>(std::cout, " "));
	//std::cout << "argv is " << *argv[1] << std::endl;
	std::cout << "Test9-----------------------------------------------------\n";
	test9::vec2.push_back(std::move(test9::vec[0]));//move 右值赋值 相当于将变量作为常数传给新的vector且不为拷贝 而是直接内存传递即原值变为空
	for_each(test9::vec2.begin(), test9::vec2.end(), [](int n) { std::cout << "for_each :n : " << n << std::endl; });
	std::cout << "test9::vec[0] is " << test9::vec[0] << std::endl;
	test9::vec4.push_back(std::move(test9::vec3[0]));//move 右值赋值 相当于将变量作为常数传给新的vector且不为拷贝 而是直接内存传递即原值变为空
	test9::vec4.push_back(static_cast<std::string&&>(test9::vec3[1]));//static_cast<std::string&&>(test9::vec3[1]) <==> std::move(test9::vec3[0]) 返回的是右值引用，对对象本身没做任何事
	for_each(test9::vec4.begin(), test9::vec4.end(), [](std::string n) { std::cout << "for_each :n : " << n << std::endl; });
	std::cout <<  "test9::vec3[0] is "<< test9::vec3[0] << std::endl;
	std::cout << "test9::vec3[1] is " << test9::vec3[1] << std::endl;
	std::cout << "static_cast<int>test9::i is " << static_cast<int>(test9::i) << std::endl;
	std::cout << "Test10-----------------------------------------------------\n";
    //test10::Test test10; 对是否调用哪个构造函数会产生歧义 所以不被允许
	test10::Test test10(1,2);
	std::cout << test10.a << std::endl;
	std::cout << "Test11-----------------------------------------------------\n";
	test11::q.push(1);
	std::cout << "q'size is "<< sizeof(test11::q) << std::endl; //sizeof(q) == 40的原因是因为其类has a deque
	std::cout << "d' size is " << sizeof(test11::d) << std::endl; //解释 sizeof(deque) == sizeof(queue)
	std::cout << "Test12-----------------------------------------------------\n";
	const char **tmp = NULL;
	{
		test12::A clsA("hello world", &test12::ch);
		test12::A clsB(clsA); //不允许使用浅拷贝，会导致在析构函数中会对同一地址的内存进行两次释放。
		std::cout << &test12::ch << std::endl;
		std::cout << clsA.GetChPtr() << std::endl;
		//以上是实现了将某类的私有成员的地址指向已知的地址，通过二级指针的形式，进行赋值并且返回该地址。
		tmp = &test12::ch;
	}
	std::cout << *tmp << std::endl; //有输出,并不是内存泄漏。而是因为test12::ch为全局变量，不为临时变量。
    std::cout << "Test13-----------------------------------------------------\n";
    test13::A *b = new test13::B;
    b->f(); //通过接口与实现隔离的方式，实现了接口继承的效果。笔者初见为之惊叹! (NVI::Non-Virtual-Interface)
    delete b;
    std::cout << "Test14-----------------------------------------------------\n";
    test14::B* test14b = new test14::B;
    test14b->fun();
    test14::A* test14a = new test14::B;
    test14a->fun();//以上告诉我们，不应重新定义继承而来的缺省参数值，因为参数为静态绑定，它只与指针类型有关。
    std::cout << "Test15-----------------------------------------------------\n";
    test15::A<int> test15a;
    std::cout << sizeof(test15a.fun()) << std::endl;
    test15::B<long int> test15b;
    std::cout << sizeof(test15b.fun()) << std::endl;
    std::cout << "Test16-----------------------------------------------------\n";
    std::cout << test16::bitset1 << std::endl;
    std::cout << test16::bitset2 << std::endl;
    std::cout << sizeof(test16::bitset1) << std::endl;
    for(int i = 0; i < 20; i++) { std::cout << test16::bitset1[i];} //由低到高按位输出
    std::cout << std::endl;
    std::cout << test16::ptr << std::endl;
    std::cout << ++test16::ptr << std::endl;
    std::cout << "Test17-----------------------------------------------------\n";
    test17::Avec clsAVec(10);
    std::cout << clsAVec[9].a << std::endl; //typedef
    std::cout << "Test18-----------------------------------------------------\n";
    test18::Avec.push_back(test18::a);
    test18::Avec.push_back(test18::b);
    test18::Avec[1].fun(); //仍会调用积累的接口
    std::cout << "Test19-----------------------------------------------------\n";
    test19::list1.splice(test19::list1.end(), test19::list2);
    std::cout << test19::list1.size() << std::endl;
    std::cout << test19::list2.size() << std::endl; //splice的作用是将某个链表的内容转移到其他链表的固定位置
    for_each(test19::list1.begin(), test19::list1.end(), [](int n) { std::cout << "for_each :n : " << n <<std::endl; });//按顺序输出list中的内容
    std::advance(test19::itr,4);
    std::cout << *test19::itr << std::endl;
    std::cout << "Test20-----------------------------------------------------\n";
    test20::func[0] = reinterpret_cast<test20::FuncPtr>(&test20::fun1);
    std::cout << test20::func[0] << std::endl;
    std::cout <<  "sizeof(test20::B) is " <<sizeof(test20::B) << std::endl;
    test20::clsDelete(test20::b); //表示尽管传入的是子类的指针，但是入参类型是基类，所以delete的仍是基类，告诉我们多态与数组不要共用。
    std::cout << "Test21-----------------------------------------------------\n";
    for(int i = 0; i < 5; i++) { test21::a[i] = new test21::A(i); std::cout << "test21::a[" << i << "]::a = " << test21::a[i]->m_a << std::endl;};
    std::cout << "Test22-----------------------------------------------------\n";
    return 0;
}


