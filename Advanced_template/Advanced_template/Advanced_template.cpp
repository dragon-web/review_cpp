#define _CRT_SECURE_NO_WARNINGS 

#include<iostream>


using namespace std;

template<class T>
class Test
{
private:
	T m_data;
public:
	void Print(T data);
};

template<class T>
void Test<T>::Print(T data)
{
	cout << "Test" << endl;
}
int main()
{
	Test<int> t;
	t.Print(0);
	system("pause");
	return 0;
}