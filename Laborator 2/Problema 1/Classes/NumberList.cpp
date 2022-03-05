#include "NumberList.h"

void NumberList::Init()
{
	if(count >0)
	{
	for(int i=0;i<count;i++)
	{
		numbers[i] = NULL;
	}
	count = 0;
	}
}

bool NumberList::Add(int x)
{
	if(count <10)
	{
		numbers[count] = x;
		count++;
		return true;
	}
	else
	return false;
}

void NumberList::Sort()
{
	std::sort(std::begin(numbers), std::end(numbers));
}

void NumberList::Print()
{
	if (count > 0) {
		for (int i = 0; i < count; i++)
		{
			std::cout << numbers[i] << std::endl;
		}
	}
	else
		std::cout << "empty\n";
}

NumberList::NumberList()
{
	count = 0;
}
