#include<iostream>
using namespace std;
#include"Array.h"

int main()
{
	Array<int>a;
	a.reSize(10);
	for (int i = 0; i < 5; i++)
		a[i] = i + 1;
	for (int i = 0; i < 5; i++)
		cout << a[i];
}