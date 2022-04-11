#include "CountAsciiHash.h"

int CountAsciiHash::HashFromString(const char* sir)
{   
    int sum = 0;
    for (unsigned i = 0; i < strlen(sir); i++)
    {
        int nr = sir[i];
        sum = sum + nr;
    }
    return sum;
}
