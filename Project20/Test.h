#pragma once
#include <iostream>
using namespace std;


template<class T>
class MyVector
{
private:
	T* ptr;
	int size;
	static int counter; // Amount of vectors
public:
	MyVector()
	{
		this->counter++;
		this->ptr = nullptr;
		this->size = 0;
	}
	MyVector(int size)
	{
		this->counter++;
		this->size = size;
		this->ptr = new T[this->size];
	}
	MyVector(const MyVector& obj)
	{
		this->counter++;
		this->size = obj.size;
		this->ptr = new T[obj.size];
		for (size_t i = 0; i < this->size; i++)
		{
			obj.ptr[i] = this->ptr[i];
		}
	}
	~MyVector()
	{
		delete[]this->ptr;
		this->ptr = nullptr;
		this->counter--;
	}
	MyVector<T> &operator=(MyVector& obj)
	{
		if (this->ptr != nullptr)
		{
			this->ptr = nullptr;
		}
		this->size = obj.size;
		this->ptr = new T[this->size];
		for (size_t i = 0; i < this->size; i++)
		{
			this->ptr[i] = obj.ptr[i];
		}
		return *this;
	}
	MyVector<T> operator[](int index)
	{
		return this->ptr[index];
	}
	void SetPtr(T* ptr)
	{
		this->ptr = new T[this->size];
		for (size_t i = 0; i < this->size; i++)
		{
			this->ptr[i] = ptr[i];
		}
	}
	void SetSize(int size)
	{
		this->size = size;
	}
	T GetPtr()
	{
		return *this->ptr;
	}
	int GetSize()
	{
		return this->size;
	}
};

template<typename T>
int MyVector<T>::counter = 0;
