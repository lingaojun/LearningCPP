// ConsoleApplication1.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include "iterator"
#include "vector"
#include "algorithm"
#include "string"
#include "iterator"
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
	std::vector<int> vec{12,4,43,5,436,345};
	std::vector<int> vec2(vec);
	std::list<char> lit1{ 'a','b','c','d','e' };
	std::list<char> lit2{ 'b','c','d','e','f' };
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
		Add(int x) :sum(x) {};
		int operator()(int a,int b)
		{
			sum += a + b;
			return sum;
		}
	private:
		int sum;
	};
	void fun(int a, int b, Add add)
	{
		std::cout << add(a, b) << std::endl;
	}
}
namespace test4
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
int main()
{
	std::cout << "Test2-----------------------------------------------------\n";
	std::cout << "原Vector" << std::endl;
	for_each(test2::vec.begin(), test2::vec.end(), [](int n) { std::cout << n <<std::endl; });//学习for_each
	std::cout << "Vector进行降序排列" << std::endl;
	sort(test2::vec.begin(), test2::vec.end(), std::greater<int>());
	for_each(test2::vec.begin(), test2::vec.end(), [](int n) { std::cout << n << std::endl ; });//学习for_each
	std::cout << "Vector进行升序排列" << std::endl;
	sort(test2::vec.begin(), test2::vec.end()); //sort 第三个为适配器 默认为升序
	for_each(test2::vec.begin(), test2::vec.end(), [](int n) { std::cout  << n  << std::endl; });//学习for_each
	//for_each(test2::vec.begin(), test2::vec.end(), &test2::output);
	copy(test2::lit3.begin(), test2::lit3.end(), std::ostream_iterator<int>(std::cout," "));//学习copy输出
	std::cout << std::endl << std::endl;
	test2::lit3.sort();//学习list的sort排序
	for_each(test2::lit3.begin(), test2::lit3.end(), [](int n) {std::cout << n << " "; });
	std::cout << *find_first_of(test2::lit1.begin(), test2::lit1.end(), test2::lit2.begin(), test2::lit2.end()) << std::endl;//找到两个数组第一个相同的数值，并返回其值
	// std::cout << []() { return std::less<int>()(10, 12); } << std::endl;
	std::cout << "Test1-----------------------------------------------------\n";
	test1::test(1, 2, &test1::output);//学习函数指针
	test1::test(3, 4, test1::ptr);
	test1::test(5, 6, test1::ptr2);
	std::cout << test2::output << std::endl;
	std::cout << "Test3-----------------------------------------------------\n";
	test3::fun(1, 2, test3::Add(5)); //这里直接调用类的类型名字作为临时变量是允许的。
	[](int x) {std::cout << "仿函数学习：" << x << std::endl; }(10); //学习仿函数
	[](int x) ->int {std::cout << "仿函数学习："; std::cout << x << std::endl; return x; }(10);//仿函数返回值
	std::cout << "Test4-----------------------------------------------------\n";
	int a = 100;
	{
		test4::My_ptr<int> p = &a; //My_ptr<int>相当于int智能指针
		std::cout << *p << std::endl;
	}
	std::cout << std::endl;
	return 0;		
}


