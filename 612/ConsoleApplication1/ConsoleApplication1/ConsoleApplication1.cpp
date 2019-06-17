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
int main()
{
	std::cout << "Test2-----------------------------------------------------\n";
	for_each(test2::vec.begin(), test2::vec.end(), [](int n) { std::cout << "for_each :n : " << n <<std::endl; });
	//for_each(test2::vec.begin(), test2::vec.end(), &test2::output);
	copy(test2::lit3.begin(), test2::lit3.end(), std::ostream_iterator<int>(std::cout," "));
	std::cout << std::endl << std::endl;
	test2::lit3.sort();
	for_each(test2::lit3.begin(), test2::lit3.end(), [](int n) {std::cout << n << " "; });
	std::cout << std::endl << std::endl;
	std::cout << *find_first_of(test2::lit1.begin(), test2::lit1.end(), test2::lit2.begin(), test2::lit2.end()) << std::endl;
	// std::cout << []() { return std::less<int>()(10, 12); } << std::endl;
	std::cout << "Test1-----------------------------------------------------\n";
	test1::test(1, 2, &test1::output);
	test1::test(3, 4, test1::ptr);
	test1::test(5, 6, test1::ptr2);
	std::cout << test2::output << std::endl;
	std::cout << "Test3-----------------------------------------------------\n";
	test3::fun(1, 2, test3::Add()); //这里直接调用类的类型名字作为临时变量是允许的。
	return 0;		
}


