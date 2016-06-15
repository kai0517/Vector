// This sample program demos the Vector defined in the book: 
// "The C++ Programming Language 4th"
// 2016-06-13 Create the Vector class and read_and_sum function
#include "Vector.h"
#include <iostream>

int main()
{
	std::cout << "How many elements in the vector(<= 20):";
	int size;
	std::cin >> size;
	if (size <= 20)
	{
		std::cout << "\nPlease enter the value of the elements in the vector.\n";
		double ret = read_and_sum(size);
		std::cout << "The sum of the values in the vector is " << ret << "\n";
	}
	else
	{
		std::cout << "\nElements more than 20 is not accepted.\n";
	}
	std::cout << "bye\n";
	system("pause");
	return 0;
}