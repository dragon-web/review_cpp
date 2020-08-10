#define _CRT_SECURE_NO_WARNINGS 

#include<iostream>
#include<fstream>
#include<string>
using namespace std;
/*
int main()
{
	char line[100];
	cout << "Type a text line:\n";  //遇到指定字符串才进行停止输入
	cin.getline(line, 100, '\n');
	cout << line;
	system("pause");
	return 0;
}


class Date
{
public:
	Date(int y = 2012, int m = 12, int d = 22)
	{
		year = y;
		month = m;
		day = d;
	}
	friend ostream &operator<<(ostream& os, Date& date);
	friend istream &operator>>(istream& is, Date& date);
private:
	int year;
	int month;
	int day;
};

ostream &operator<<(ostream& os, Date& date)
{
	os << date.year << '/' << date.month << '/' << date.day << '\n';
	return os;
}
istream &operator>>(istream& is, Date& date)
{
	is >>date.year>>date.month>>date.day;
	return is;
}

int main()
{
	Date dt;
	cout << dt;
	cin >> dt;
	cout << dt;
	system("pause");
	return 0;
}
int main()
{
	ofstream ofile;
	ofile.open("Test1.txt");
	if (!ofile)
	{
		cout << "Can not open file test.txt\n";
	}
	else
	{
		ofile << 10 << " " << 123.45 << "This is a file"<<endl;
	}
	ofile.close();
	system("pause");
	return 0;
}

int main()
{
	int i;
	float f;
	char str1[80];
	
	ifstream in("Test1.txt");
	if (!in.is_open())
	{
		cout << "Can not open this file" << endl;
	}
	else
	{
		in >> i >> f>>str1;
		cout << i << f<<endl;
		cout << str1 << endl;

	}
	system("pause");
	return 0;
}

class A
{
public:
	A(const string &str = "") :name(str) {}
	~A() {}
protected:
	string name;
};
class B :public A
{
public:
	void func(const B& b, const A &a) {
		cout << name << endl;//right
		cout << b.name << endl;//right
		cout << a.name << endl;//error can't visit protected member
	}
};
*/



