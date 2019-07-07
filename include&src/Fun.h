#ifndef __FUN_H
#define __FUN_H

#include "iostream"
#include "map"

enum Enum
{
	FirstNum = 1,
	SecondNum = 2,
	ThirdNum = 3
};



struct MyStruct
{
	int a;
	int b;
	int (*Fun)(int &a, int &b);
};

class Fun
{
public:
	Fun();
	~Fun();
private:

};



int First(int &a, int &b);
int Second(int &a, int &b);
int Third(int &a, int &b);
#endif