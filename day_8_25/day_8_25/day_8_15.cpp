#define _CRT_SECURE_NO_WARNINGS 

#include<iostream>

using namespace std;
/*
class Base {
public:
	virtual void f() {
		cout << "Base::f" << endl;
	}
	virtual void g() {
		cout << "Base::g" << endl;
	}
	virtual void h() {
		cout << "Base::h" << endl;
	}
};


#include <iostream>
using namespace std;

class Base {
public:
	virtual void f() { cout << "Base::f" << endl; }
 virtual void g() { cout << "Base::g" << endl; }
	void h() { cout << "Base::h" << endl; }

};
class Derived :public Base
{
public:
	virtual void f() { cout << "Derived::f" << endl; }
	void g() { cout << "Derived::g" << endl; }
	void h() { cout << "Derived::h" << endl; }
};


int main()
{
	Base *pB = new Base();
	cout << "当基类指针指向基类对象时：" << endl;
	pB->f();
	pB->g();
	pB->h();
	cout << endl;

	Derived *pD = (Derived*)pB;
	cout << "当父类指针被强制转换成子类指针时：" << endl;
	pD->f();
	pD->g();
	pD->h();
	cout << endl;

	Derived *pd = new Derived();
	cout << "当子类指针指向子类时候" << endl;
	pd->f();
	pd->g();
	pd->h();
	cout << endl;

	Base *pb = (Base *)pd;
	cout << "当子类指针被强制转换成父类指针时：" << endl;
	pb->f();
	pb->g();
	pb->h();
	cout << endl;

	Base *pp = new Derived();
	cout << "父类指针指向子类对象时候：" << endl;
	pp->f();
	pp->g();
	pp->h();
	cout << endl;
	system("pause");
	return 0;
}

class Base
{
public:
	int Bar(char x)
	{
		return (int)(x);
	}
	virtual int Bar(int x)
	{
		return (2 * x);
	}
};
class Derived: public Base
{
public:
	int Bar(char x)
	{
		return (int)(-x);
	}
	int Bar(int x)
	{
		return (x / 2);
	}
};
int main(void)
{
	Derived Obj;
	Base *pObj = &Obj;
	printf("%d,", pObj->Bar((char)(100)));
	printf("%d,", pObj->Bar(100));
	system("pause");
	return 0;
}

//  100, 50

class animal
{
protected:
	int age;
public:
	virtual void print_age(void) = 0;
};

class dog : public animal
{
public:
	dog() { this->age = 2; }
	~dog() {}
	virtual void print_age(void) { cout << "wang. my age=" << this->age << endl; }
};

class cat :public animal
{
public:
	cat() { this->age = 1; }
	~cat() {}
	virtual void print_age(void) { cout << " Miao,my age= " << this->age << endl; }
};

int main(void)
{
	cat kitty;
	dog jd;

	animal *pa;
	int *p = (int *)(&kitty);
	int *q = (int *)(&jd);
	p[1] = q[1] = 2;
	pa = &kitty;
	pa->print_age();
	pa = &jd;
	pa->print_age();
	system("pause");
	return 0;
}

class Base
{
public:
	virtual void f()
	{
		this->print();
	}
	virtual void print(int i = 6)
	{
		cout << "Base:" << i * i << endl;
	}
};

class Derived : public Base
{
public:
	virtual void f()
	{
		this->print();  //
	}
	virtual void print(int i = 10)
	{
		cout << "Derived" << i * i << endl;
	}
};

void bar(Base* p)
{
	p->print();
	p->f();
}

int main()
{
	Base * p = new Base;
	bar(p);

	Derived  * q = new Derived();
	bar(q);

	Base * r = (Base *)new Derived();
	bar(r);

	system("pause");
	return 0;
}
#include<iostream>  
#include"omp.h"  

using namespace std;

int main()
{
#pragma omp parallel num_threads(6)  
	{
		cout << "Test" << endl;
	}
	system("pause");
	return 0;
}
class A
{
public:
	void sayhello()
	{
		cout << "hello A" << endl;
	}
private:
};

class B
{
public:
	virtual void sayhello()
	{
		cout << "hello B" << endl;
	}
private:
};

int main()
{
	A *pa = NULL;
	pa->sayhello();  

	B *pb = NULL;
	pb->sayhello();    //虚函数表指针无法读取内存

	system("pause");
	return 0;
}


class Base
{
public:
	virtual void f()
	{
		this->print();   //协变
	}
	virtual void print(int i = 6)
	{
		cout << "Base:" << i * i << endl;
	}
};

class Derived : public Base
{
public:
	virtual void f()
	{
		this->print();  //
	}
	virtual void print(int i = 10)
	{
		cout << "Derived" << i * i << endl;
	}
};

void bar(Base* p)
{
	p->print();
	p->f();
}

int main()
{
	Base * p = new Base;
	bar(p);

	Derived  * q = new Derived();
	bar(q);

	Base * r = (Base *)new Derived();
	bar(r);

	system("pause");
	return 0;
}

class CBase
{
public:
	virtual void act1() { cout << "CBase::act1()! "; act2(); }
	void act2() { cout << "CBase::act2()! "; act3(); }
	virtual void act3() {
		cout << "CBase::act3()! ";
		act4();
	}
	virtual void act4() { cout << "CBase::act4()! "; act5(); }
	void act5() { cout << "CBase::act5()! "; }
};

class CDerive : public CBase
{
public:
	void act3() { cout << "CDerive::act3()! ";  act4(); }
	void act4() { cout << "CDerive::act4()! ";  act5(); }
	void act5() { cout << "CDerive::act5()! "; }
};

int main(void)
{
	CBase *pObj1 = new CBase;
	pObj1->act1();
	pObj1->act5();
	cout << endl;
	CBase *pObj2 = new CDerive;
	pObj2->act1();
	pObj2->act5();
	delete pObj1;
	delete pObj2;
	system("pause");
	return 0;
}



class A
{
	virtual void g()
	{
		cout << "A::g" << endl;
	}
private:
	virtual void f()
	{
		cout << "A::f" << endl;
	}
};

class B : public A
{
	void g()
	{
		cout << "B::g" << endl;
	}
	virtual void h()
	{
		cout << "B::h" << endl;
	}
};

typedef void(*Fun)(void);
int main(int argc, char* argv[])
{
	B b;
	Fun pFun;
	for (int i = 0; i < 3; i++)
	{
		pFun = (Fun)*((int*) *(int*)(&b) + i);
		pFun();
	}
	system("pause");
	return 0;
}

class base
{
public:
	virtual void disp()
	{
		cout << "Hello,base" << endl;
	}
};
class child1 :public base
{
public:
	void disp()
	{
		cout << "hello,child1" << endl;
	}
};
class child2 :public base
{
public:
	void disp()
	{
		cout << "hello,child2" << endl;
	}
};

void display(base *pb)
{
	pb->disp();
}

int main()
{
	base *pBase = NULL, obj_base;
	obj_base.disp();
	pBase = &obj_base;
	pBase->disp();

	child1 *pchild1 = NULL, obj_child1;
	obj_child1.disp();
	pchild1 = &obj_child1;
	pchild1->disp();

	child2 *pchild2 = NULL, obj_child2;
	obj_child2.disp();
	pchild2 = &obj_child2;
	pchild2->disp();

	pBase = &obj_child1;
	pBase->disp();

	display(&obj_base);
	display(&obj_child1);
	display(&obj_child2);
	return 0;
}
*/

