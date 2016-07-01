// This sample program demos the Vector defined in the book: 
// "The C++ Programming Language 4th"
// 2016-06-13 Create the Vector class and read_and_sum function
#include "DblVector.h"
#include <iostream>
#include "VecContainer.h"
#include "ListContainer.h"
#include <ctime>

void print(Container& c)
{
	const int sz = c.size();
	for (int i = 0; i != sz; ++i)
	{
		std::cout << c[i] << " ";
	}
	std::cout << "\n";
}

int main()
{
	/*std::cout << "How many elements in the vector(<= 20):";
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
	}*/

	/*
	// code to try the exception
	try
	{
		//DblVector v(-5);
		DblVector v(5);
		v[v.size()] = 20;
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << "\n";
	}*/

	/*
	DblVector v{ 1.2,32.3,354,441 };
	print_vector(v);
	
	DblVector v2(5);
	v2.push_back(10);
	v2.push_back(20);
	v2.push_back(14.4);
	print_vector(v2);
	std::cout << "bye\n";

	Vector_container vc{ 10,9,8,7,6,5,4,3,2,1,0 };
	print(vc);

	List_container lc{ 0,1,2,3,4,5,6,7,8,9,10 };
	print(lc);*/

	// Try copy and move constructor and operators
	DblVector cpv1(10000000);
	for (int i = 0; i < cpv1.size(); ++i)
	{
		cpv1[i] = i + 101;
	}

	clock_t start = clock();
	for (int i = 0; i < 50; ++i)
	{
		DblVector cpv2(cpv1);
	}
	std::cout << "Time to copy: " << ((clock() - start) / CLOCKS_PER_SEC) << " seconds\n";

	start = clock();
	for (int i = 0; i < 50; ++i)
	{
		DblVector cpv3 = std::move(cpv1);
	}	
	std::cout << "Time to move: " << ((clock() - start) / CLOCKS_PER_SEC) << " seconds\n";

#if defined(_MSC_VER)
	system("pause");
#else
    std::cout << "Press [Enter] to continue...";
    std::cin.get();
#endif
	
	return 0;
}
