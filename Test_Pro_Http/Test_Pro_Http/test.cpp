#include<sstream>
#include<iostream>
#include<string>
#include<unordered_map>

using namespace std;
/*
int main()
{
	string str = "aa bb cc";
	stringstream cc(str);
	string str1;
	string str2;
	string str3;
	cc >> str1 >> str2 >> str3;
	cout << str1 << endl;
	cout << str2 << endl;
	cout << str3 << endl;

	string str = "aa bb cc";
	system("pause");
	return 0;
}



int main()
{
	string str = "aabbcc\nasvcjasb\nasbdias\n";
	size_t pos = str.find('\n');
	int start = 0;
	while (pos != str.npos) //找到\n的位置
	{
		string sub = str.substr(start, pos - start);
		cout << sub << endl;
		start = pos + 1;
		pos = str.find('\n',pos+1);
	}
	system("pause");
	return 0;
}


int main()
{
	string str = "Content-Length: 30";
	size_t pos = str.find(": ");
	if (str.npos == pos)
	{
		return -1;
	}
	string key = str.substr(0, pos);
	string value = str.substr(pos + 2);
	cout << "key :" << key << endl;
	cout << "value :" << value << endl;
	unordered_map <string, string> mp;
	//mp.insert(make_pair<string, string>(key, value));
	mp.insert({key,value});
	cout << mp.size() << endl;
	system("pause");
	return 0;
}



int main()
{
	string str = "1234adskjasn";
	stringstream ss(str);
	int len = 0;
	ss >> len;
	cout << len << endl;
	system("pause");
	return 0;
}

*/

//同样整型转字符串 

int main()
{
	int len = 1234;
	stringstream ss;
	ss << len;
	string str = ss.str();


	cout << len << endl;
	system("pause");
	return 0;
}