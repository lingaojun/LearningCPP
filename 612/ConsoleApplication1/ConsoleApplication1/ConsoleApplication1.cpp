// ConsoleApplication1.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
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
int main()
{	
	std::cout << "Test2-----------------------------------------------------\n";
	for_each(test2::vec.begin(), test2::vec.end(), [](int n) { std::cout << "for_each :n : " << n <<std::endl; });//按顺序输出vector中的内容
	//for_each(test2::vec.begin(), test2::vec.end(), &test2::output);
	copy(test2::lit3.begin(), test2::lit3.end(), std::ostream_iterator<int>(std::cout," "));//将list的内容按顺序以此复制到输出流中，相当于输出内容。
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
	

	return 0;		
}


