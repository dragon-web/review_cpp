#define _CRT_SECURE_NO_WARNINGS 

#include <iostream>
using namespace std;

class Base
{
public:
	virtual void print() const = 0;

};

class Test : public Base
{
public:
	void print();
	void print() const;

};

void Test::print()
{
	cout << "Test::print()" << endl;

}

void Test::print() const
{
	cout << "Test::print() const" << endl;

}

int main()
{
	Base* pChild = new Test();
	pChild->print();

	const Test  obj;
	obj.print();

	Test obj1;
	obj1.print();

	Test* pOwn = new Test();
	pOwn->print();
	system("pause");
	return 0;
}


