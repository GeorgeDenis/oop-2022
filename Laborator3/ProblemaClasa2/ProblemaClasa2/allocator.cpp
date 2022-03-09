#include "allocator.h"
#include <cstdlib>
#include <cstring>
void* Allocator::alloc_raw(unsigned size) {
    char *s = buffer+offset;
    offset += size;
    return s;
}

Allocator::Allocator(unsigned max_size) {
    buffer = (char *)malloc(max_size);
    offset = 0;
    this->max_size = max_size;
}

Allocator::~Allocator() {
    free(buffer);
}
#define makefunction(type)\
type* Allocator::alloc(type x) {\
    type* p = (type*) alloc_raw(sizeof(x));\
    *p          = x;\
    return p;\
}
makefunction(unsigned);
makefunction(int);
makefunction(double);
makefunction(float);
makefunction(char);
      /* int* Allocator::alloc(int x) {
    int* p = (int*) alloc_raw(sizeof(x));
    *p          = x;
    return p;
}

float* Allocator::alloc(float x) {
    float* p = (float*) alloc_raw(sizeof(x));
    *p          = x;
    return p;
}

double* Allocator::alloc(double x) {
    double* p = (double*) alloc_raw(sizeof(x));
    *p          = x;
    return p;
}

char* Allocator::alloc(char x) {
    char* p = (char*) alloc_raw(sizeof(x));
    *p          = x;
    return p;
}
*/
char* Allocator::alloc(const char* string) {
    int l       = strlen(string);
    char * p = (char*) alloc_raw(sizeof(l+1));
    memcpy(p, string, l+1);
    return p;
}
