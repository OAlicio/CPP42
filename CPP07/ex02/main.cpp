#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Array.hpp"

#define MAX_VAL 5
int main(int, char**)
{
    Array<int> numbers(MAX_VAL);
    int* mirror = new int[MAX_VAL];
	std::srand(std::time(NULL));
    for (int i = 0; i < MAX_VAL; i++)
    {
        const int value = std::rand();
        numbers[i] = value;
        mirror[i] = value;
    }
    //SCOPE
    {
        Array<int> tmp = numbers;
        Array<int> test(tmp);
    }

	const Array<int>numbersconst(numbers);
	//numbersconst[0] = 2; // This is an error
	std::cout << "Testing copy constuctor\n";
	std::cout << numbersconst[0] << std::endl;
	std::cout << numbers[0] << std::endl;
	std::cout << "=======================\n";

	{
		Array<int> n2;
		n2 = numbers;
		if (numbers.size() != n2.size())
			std::cerr << "assignment operator is wrong!\n";
	}
	if (numbers.size() != MAX_VAL)
		std::cerr << "size method not as expected\n";
    for (int i = 0; i < MAX_VAL; i++)
    {
        if (mirror[i] != numbers[i])
        {
            std::cerr << "didn't save the same value!!" << std::endl;
            return 1;
        }
    }
	std::cout << "Testing exception handling\n";
    try
    {
        numbers[-2] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    try
    {
        numbers[MAX_VAL] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
	std::cout << "==========================\n";

	Array<int> copy(numbers);
	std::cout << "Printin values after change numbers\n";
    for (int i = 0; i < MAX_VAL; i++)
    {
		numbers[i] = i;
		std::cout << numbers[i] << std::endl;
		std::cout << copy[i] << std::endl;
    }
	std::cout << "======================\n";
    delete [] mirror;//
    return 0;
}
