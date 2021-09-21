#include <iostream>
#include "Test.h"

using namespace std;

template<class T>
ostream& operator<<(ostream& os, MyVector<T>& obj) // Overloading operator of output
{
	os << obj.GetPtr() << endl << obj.GetSize() << endl;
	return os;
}

template<class T>
istream& operator>>(istream& is, MyVector<T>& obj) // Overloading operator of input
{
	int a;
	cout << "Enter size: ";
	is >> a;
	obj.SetSize(a);
	cout << endl;
	cout << "Enter elements of array: ";
	cout << endl;
	T* ptr = new T[a];
	for (size_t i = 0; i < a; i++)
	{
		is >> ptr[i];
	}
	obj.SetPtr(ptr);
	return is;
}

int main()
{
	MyVector <int>a;
	cin >> a;
	cout << a;
	MyVector <int>b;
	b = a;
	cout << endl;
	cout << b;
}