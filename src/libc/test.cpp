#include <iostream>

int inc(int &num)
{
	return ++num;
}

int main()
{
	int number = 0;
	while(number <= 10)
	{
		std::cout << number << " ";
		inc(number);
	}
	std::cout << std::endl;
	return 0;
}
