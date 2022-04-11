#include "Vowels.h"

int CountVowelsHash::HashFromString(const char* sir)
{   
    int k = 0;
    for(unsigned i =0;i<strlen(sir);i++)
        if(strchr("AEIOUaeiou",sir[i]))
            k++;
    return k;
}
