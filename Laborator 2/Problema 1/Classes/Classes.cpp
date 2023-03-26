

#include <iostream>
#include "NumberList.h"

int main()
{
    NumberList myVector;
    for (int i = 10; i >= 0; i--) {
        myVector.Add(i);
    }
    if (myVector.Add(999))
        std::cout << "enough space\n";
    else
        std::cout << "vector full\n";
    myVector.Print();
    myVector.Sort();
    myVector.Print();
    myVector.Init();
    myVector.Print();
}


