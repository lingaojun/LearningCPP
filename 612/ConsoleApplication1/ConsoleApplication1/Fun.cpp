#include "Fun.h"

Fun::Fun()
{

}

Fun::~Fun()
{

}

//通过数组来决定选择哪一个函数指针
//编写多个函数，用来对应多次寻找函数指针

int First(int &a, int &b)
{
	return a + b;
}

int Second(int &a, int &b)
{
	return a - b;
}

int Third(int &a, int &b)
{
	return a * b;
}