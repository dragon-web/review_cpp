#define _CRT_SECURE_NO_WARNINGS 

#include<iostream>

using namespace std;


namespace bit
{
	template <class _Ty>

	class auto_ptr
	{
	public:
		auto_ptr(_Ty * _P = 0) :_Owns(_P != 0), _Ptr(_P)
		{

		}
		~auto_ptr()
		{
			if (_Owns)
				delete _Ptr;
		}
	private:
		bool _Owns;
		_Ty *_Ptr;
	};
}



int main()
{
	int *p = new int(10);
	bit::auto_ptr <int> ap(p);
	
	system("pause");
	return 0;
}