#include <iostream>  
/*
class MyClass {  
  public:  
    int x;  
    MyClass(int i); 
    ~MyClass(); 
};    
MyClass::MyClass(int i) {  
    x = i; 
}    
MyClass::~MyClass() {  
    std::cout<<' '<<x;  
}  
int main() {    
    MyClass t1(5); 
    MyClass t2=15; 
    MyClass t3=MyClass(25); 
    MyClass t4(t3); 
    t4.x+=10; 
    return 0; 
} 

#include <iostream> 
using namespace std; 
class Myclass { 
  private: 
    int m; 
  public: 
    Myclass(int arg1) {m=arg1;} 
    void setvalue(int arg1=0) {m=arg1;} 
    void show(); 
    void show() const; 
}; 
void Myclass::show() { 
    cout << "s1=" << m << '.'; 
} 
void Myclass::show() const 
{ 
    cout << "s2=" << m << '.'; 
} 
int main(){ 
    Myclass obj1(100); 
    const Myclass obj2(200); 
    obj1.show(); 
    obj2.show(); 
    obj1.setvalue(300); 
    obj1.show(); 
    return 0; 
}

#include <iostream>
using namespace std; 
class DivByZero{}; //定义异常类 
int division(int x,int y) { 
  if (!y) throw DivByZero();  
    else    return x/y; 
    } 
    int main(){ 
      try { 
          cout<<division(12,5)<<','; 
              cout<<division(0,5)<<','; 
                  cout<<division(12,0)<<','; 
                      cout<<division(12,7)<<endl; 
                        } 
                          catch (DivByZero) { 
                              cout << "已经捕获到错误...."; 
                                  cout << "错误类型是除零错。"; 
                                    } 
                                      cout << "程序结束运行！" << endl; 
                                        return 0; 
                                        } 
#include <iostream>
using namespace std;  
class Base { 
  private: 
    int bi; 
  public: 
    Base() {    bi=0;   } 
    ~Base() { 
            cout<<bi<<' '; 
        } 
}; 
class Base1 { 
  private: 
    int bi1; 
  public: 
    Base1(int x) {    bi1=x;   } 
    ~Base1() { 
            cout<<bi1<<' '; 
        } 
}; 
class Base2 { 
  private: 
    int bi2; 
  public: 
    Base2(int x) {    bi2=x;   } 
    ~Base2() { 
            cout<<bi2<<' '; 
        } 
}; 
class Myclass { 
  private: 
    int mi; 
  public: 
    Myclass(int x) {    mi=x;   } 
    ~Myclass() { 
            cout<<mi<<' '; 
        } 
}; 
class Derived:public Base2,Base1,protected Base { 
  private: 
    int di; 
    Myclass obj; 
  public: 
    Derived(int a,int b,int c,int d) 
        :obj(b),Base1(c),Base2(d) { 
                di=a; 
            } 
    ~Derived() { 
            cout<<di<<' '; 
        } 
}; 
int main() { 
    Derived dObj(1,2,3,4); 
    return 0; 
} 
#include<iostream>

using namespace std;

struct Myclass {
      int a;   
      int b; 
}; 
int main() { 
  Myclass obj; 
  obj.a=100;
  obj.b = 10;
  int *p = &obj.b;
  cout<<*p<<endl;

}

第 25 页共 27 页
template <class T> 
class List { 
  private: 
    int n;      //表的当前长度 
    int size;   //表元素的最大长度 
    T *data;    //表元素数组指针 
  public: 
    List(int max=10);         //构造函数，默认表元素的最大长度为10 
    ~List(){delete[] data;}    //析构函数，释放表元素数组 
    //其他函数的声明（或定义）：略 
    //    //>>>>>>>>>>>>>>>>在下面声明重载赋值运算符的函数原型<<<<<<<<<<<<<<<<<//
    //    ;   //（2分） 
    //    }; 
    //    //构造函数等函数的定义：略 
    //    //>>>>>>>>>>>>>>在下面给出重载赋值运算符函数的定义（实现）<<<<<<<<<<<<<<<//
    }
*/








