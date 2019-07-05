#ifndef ARRAY_H
#define ARRAY_H

template <typename T>
class Array
{
	T *data;
	int  capacity;
	int isValidIndex(int index) const
	{
		if (index >= 0 && index < capacity)
			return 1;
		return 0;
	}
public:
	~Array();
	T & operator [] (int i);
	const T & operator [] (int i) const;
	int getCapacity();
	void reSize(int newCap);
	Array<T> & operator = (Array<T> & ref);
	Array(const Array<T> & ref);
	Array();
	//Array(initializer_list<T>  list);
};
#endif
//template<typename T>
//Stack<T>& Stack<T> ::operator = (const Stack<T> &ref);

template <typename T>
Array<T>::~Array()
{
	if (data)
	{
		delete[]data;
		data = nullptr;
		capacity = 0;
	}
}
template <typename T>
T& Array<T>:: operator [] (int i)
{
	if (i < capacity && i >= 0)
		return data[i];
	else
		exit(0);
}

template <typename T>
const T& Array<T>:: operator [] (int i) const
{
	if (i < capacity && i >= 0)
		return data[i];
	else
		exit(0);
}

template <typename T>
int Array<T>::getCapacity()
{
	return capacity;
}

template <typename T>
void Array<T>::reSize(int newCap)
{
	T *temp = new T[newCap];
	for (int i = 0; i < capacity; i++)
		temp[i] = data[i];
	(*this).~Array();
	capacity = newCap;
	data = temp;
}

template <typename T>
Array<T>& Array<T>::operator = (Array<T> & ref)
{
	if (data != ref.data)
	{
		data = new T[ref.capacity];
		for (int i = 0; i < ref.capacity; i++)
			data[i] = ref.data[i];
	}
		capacity = ref.capacity;
		return (*this);
}

template <typename T>
Array<T>::Array(const Array<T> & ref)
{
	if (!ref.data)
	{
		data = 0;
		capacity = 0;
		return;
	}
	data = new T[ref.capacity];
	for (int i = 0; i < ref.capacity; i++)
		data[i] = ref.data[i];
	capacity = ref.capacity;
}

template <typename T>
Array<T>::Array()
{
	capacity = 0;
	data = 0;
}