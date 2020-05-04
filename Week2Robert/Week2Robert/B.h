#pragma once
#include <iostream>
using namespace std;
class B
{
	int a;
public:
	B() 
	{
		cout << "object of" << typeid(*this).name() << "was created\n";
	}
	B(int x) :B() { a = x; }
	~B() 
	{
		cout << "object of" << typeid(*this).name() << "was destroyed\n";
	}
};

class D1: public B
{
	int b;
public:
	D1(int x, int y) : B(y)
	{
		b = x;
		cout << "object of" << typeid(*this).name() << "was created\n";
	}
	
	~D1()
	{
		cout << "object of" << typeid(*this).name() << "was destroyed\n";
	}
};

class D2 : private B
{
	int c;
public:
	D2(int r, int t) : B(t)
	{
		c = r;
		cout << "object of" << typeid(*this).name() << "was created\n";
	}

	~D2()
	{
		cout << "object of" << typeid(*this).name() << "was destroyed\n";
	}
};

class D3 : private B
{
	int d;
public:
	D3(int z, int n) : B(n)
	{
		d = z;
		cout << "object of" << typeid(*this).name() << "was created\n";
	}

	~D3()
	{
		cout << "object of" << typeid(*this).name() << "was destroyed\n";
	}
};

class D4 : public D2, private D1
{
	int e;
public:
	D4(int x, int y, int r, int t, int m) : D1(y, r), D2(t, m)
	{
		e = x;
		cout << "object of" << typeid(*this).name() << "was created\n";
	}

	~D4()
	{
		cout << "object of" << typeid(*this).name() << "was destroyed\n";
	}
};

class D5 : private D3, public D2
{
	int f;
public:
	D5(int x, int r, int t, int z, int n) : D2(r, t), D3(z, n)
	{
		f = x;
		cout << "object of" << typeid(*this).name() << "was created\n";
	}

	~D5()
	{
		cout << "object of" << typeid(*this).name() << "was destroyed\n";
	}
};

