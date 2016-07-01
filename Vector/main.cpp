// This sample program demos the Vector defined in the book: 
// "The C++ Programming Language 4th"
// 2016-06-13 Create the Vector class and read_and_sum function
#include "DblVector.h"
#include <iostream>
#include "VecContainer.h"
#include "ListContainer.h"
#include <ctime>
#include "TplVector.h"

void print(Container& c)
{
	const int sz = c.size();
	for (int i = 0; i != sz; ++i)
	{
		std::cout << c[i] << " ";
	}
	std::cout << "\n";
}

void test_read_and_sum()
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
}

void test_exception()
{
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
    }
}

void test_push_back()
{
	DblVector v{ 1.2,32.3,354,441 };
	print_vector(v);
	
	DblVector v2(5);
	v2.push_back(10);
	v2.push_back(20);
	v2.push_back(14.4);
	print_vector(v2);
}

void test_inheritance()
{
	Vector_container vc{ 10,9,8,7,6,5,4,3,2,1,0 };
	print(vc);

	List_container lc{ 0,1,2,3,4,5,6,7,8,9,10 };
	print(lc);
}

void test_copy_and_move()
{
	// Try copy and move constructor and operators
	DblVector v1(10000000);
	for (int i = 0; i < v1.size(); ++i)
	{
		v1[i] = i + 101;
	}

	clock_t start = clock();
	for (int i = 0; i < 50; ++i)
	{
		DblVector v2(v1);
	}
	std::cout << "Time to copy: " << ((clock() - start) / CLOCKS_PER_SEC) << " seconds\n";

	start = clock();
	for (int i = 0; i < 50; ++i)
	{
		DblVector v3 = std::move(v1);
	}	
	std::cout << "Time to move: " << ((clock() - start) / CLOCKS_PER_SEC) << " seconds\n";
}

void test_template()
{
    Vector<std::string> strVec = { "Apple", "Orange", "Grape", "Strawberry" };
    print_vector(strVec);

    Vector<int> intVec = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
    print_vector(intVec);
}

void test_template2()
{
    Vector<int> vec = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
    int x = 6;
    std::cout << "number of values less than " << x 
              << ": " << count(vec, Less_than<int>{x})
              << '\n';

    std::list<std::string> lst = { 
        "number", "object", "abstract", "polymorphism", "resource", "memory"
        "singleton", "processor", "thread", "eagle", "tiger", "business", 
        "cake", "critical", "coffee", "callback"
    };
    std::string s = "constructor";
    std::cout << "number of value less than " << s
              << ": " << count(lst, Less_than<std::string>{s})
              << '\n';
}

void test_lambda()
{
    Vector<int> vec = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
    int x = 6;
    std::cout << "number of values less than " << x 
              << ": " << count(vec, [&](int elem){ return elem<x; })
              << '\n';

    std::list<std::string> lst = { 
        "number", "object", "abstract", "polymorphism", "resource", "memory"
        "singleton", "processor", "thread", "eagle", "tiger", "business", 
        "cake", "critical", "coffee", "callback"
    };
    std::string s = "constructor";
    std::cout << "number of value less than " << s
              << ": " << count(lst, [&](std::string const& elem){ return elem<s; })
              << '\n';
}


int main()
{
    //test_read_and_sum();
    //test_exception();
    //test_push_back();
    //test_inheritance();
    //test_copy_and_move();
    test_template();
    test_template2();
    test_lambda();

#if defined(_MSC_VER)
	system("pause");
#else
    std::cout << "Press [Enter] to continue...";
    std::cin.get();
#endif
	
	return 0;
}
