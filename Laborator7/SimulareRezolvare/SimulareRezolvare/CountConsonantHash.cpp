#include "CountConsonantHash.h"

int CountConsonantHash::HashFromString(const char* sir)
{   
    int k = 0;
    for (unsigned i = 0; i < strlen(sir); i++)
        if ((sir[i] >= 'a' && sir[i] <= 'z' && strchr("aeiou", sir[i]) == 0) || (sir[i] >= 'A' && sir[i] <= 'Z' && strchr("AEIOU", sir[i]) == 0))
            k++;
            return k;
}
