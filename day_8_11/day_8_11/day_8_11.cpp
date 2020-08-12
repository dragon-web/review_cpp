#define _CRT_SECURE_NO_WARNINGS 

#include<iostream>
#include<vector>
#include<string>

using namespace std;
/*
using namespace std;
int main()
{
	int n;
	cin >> n;
	int sum = 0;
	vector<int> bp;
	int i;
	for (i = 1; i <= n; ++i)
	{
		if (sum == n)
		{
			break;
		}
		sum += i;
		bp.push_back(i);
	}
	for (int j = i+1; j <= n; ++j)
	{
			

	}

	system("pause");
	return 0;
}

using namespace std;
int main()
{
	vector<int> bp;
	int sum = 0;
	for (int i = 1; i <= 6; ++i)
	{
		for (int j = 1; j <= 6; ++j)
		{
			sum = i + j;
			if (sum % 2 == 0)
			{
				auto it = bp.begin();
				while (it != bp.end())
				{
					if (sum == *it)
					{
						break;
					}
					it++;
				}
				if (it == bp.end())
				{
					bp.push_back(sum);
				}
			}
		}
	}
	for (auto &e : bp )
	{
		cout << e << endl;
	}

	system("pause");
	return 0;
}


int main()
{
	string A("ABCDEF");
	cout << A.length() << "  " << strlen(A) << endl;
	string B("B");
	A.append(B);
	B = A;
	cout << "A = " << A << "B = " << B << endl;
	system("pause");
	return 0;
}

#include<iostream>
using namespace std;
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
	~dog() { }
	virtual void print_age(void)
	{
		cout << "Wang, my age = " << this->age << endl;
	}
};
class cat : public animal
{
public:
	cat() { this->age = 1;} 	~cat() { }
	virtual void print_age(void)
	{
		cout << "Miao, my age = " << this->age << endl;
	}
};
int main(void)
{
	cat kitty;
	dog jd;
	animal * pa;
	int * p = (int *)(&kitty);
	int * q = (int *)(&jd);
	p[0] = q[0];
	pa = &kitty;
	pa->print_age();
	system("pause");
	return 0;
}
*/
#include<iostream>

using namespace std;

int main()
{
	float a[3] = { 1.5,2.5,3.5 }, *pa = a;
	//*pa++ *= 3;
	*(++pa) *= 3;
	system("pause");
	return 0;
}
