#define _CRT_SECURE_NO_WARNINGS 

#include<iostream>
using namespace std;
/*
int main()
{
	double m, n;
	cin >> m >> n;
	try
	{
		cout << "before deviding." << endl;
		if (n == 0)
			throw - 1;
		else
			cout << m / n << endl;
		cout << "after deviding" << endl;
	}
	catch (double d)
	{
		cout << "catch(double)" << d << endl;
	}
	catch (int e)
	{
		cout << "catch(int)" << e << endl;
	}
	cout << "finished" << endl;
	system("pasue");
	return 0;
}

//能捕获任何异常的catch语句
int main()
{
	double m, n;
	cin >> m >> n;
	try
	{
		cout << "before dividing." << endl;
		if (n == 0)
			throw - 1;
		else if (m == 0)
			throw - 1.0;
		else
			cout << m / n << endl;
		cout << "after dividing" << endl;
	}
	catch (double d)
	{
		cout << "catch(double)" << d << endl;
	}
	catch (...)
	{
		cout << "catch(...)" << endl;
	}
	cout << "finished" << endl;
	system("pause");
	return 0;
}
*/