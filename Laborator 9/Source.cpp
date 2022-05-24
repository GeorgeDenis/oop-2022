#include <string>
#include <iostream>
#include <vector>
#include <map>

template <class T, class Y>
struct pereche {
    T key;
    Y value;
};
template <class T, class Y>
class Iterator {
    struct tuple {
        T key;
        Y value;
        int index;
    };
    pereche<T, Y>* ptr;
    int index;

public:
    Iterator(pereche<T, Y>* ptr, int index) : ptr(ptr), index(index) {
    }
    bool operator!=(Iterator const& other) {
        return ptr != other.ptr;
    }
    Iterator& operator++() {
        ptr++;
        index++;
        return *this;
    }
    tuple operator*() {
        tuple treime;
        treime.key = ptr->key;
        treime.value = ptr->value;
        treime.index = index;
        return treime;
    }
};

template <class T, class Y>
class Map {
    pereche<T, Y> vector[30];
    int size;

public:
    Map() {
        size = 0;
    }
    Y& operator[](T key) {
        for (int i = 0; i < size; i++)
            if (vector[i].key == key)
                return vector[i].value;
        vector[size].value = {};
        vector[size].key = key;
        size++;
        return vector[size - 1].value;
    };
    void Set(T key, Y value)
    {
        for (int i = 0; i < size; i++)
            if (vector[i].key == key)
                vector[i].value = value;
    }
    bool Get(const T& key, Y& value)
    {
        for(int i=0;i<size;i++)
            if (vector[i].key == key)
            {
                value = vector[i].value;
                return true;
            }
        return false;
    }
    int Count() {
        return size;
    }
    void Clear() {
        size = 0;
    }
    bool Delete(const T& key )
    {
        for (int i = 0; i < size; i++)
            if (vector[i].key == key)
            {
                for (int j = i; j < size - 1; j++)
                    vector[j] = vector[j + 1];
                size--;
            }
        return false;
    }
    bool Includes(const Map<T, Y>& map)
    {
        int g;
        for (int i = 0; i < size; i++)
        {
            g = 0;
            for(int j=0;j<map.size;j++)
                if (vector[i].key == map.vector[j].key)
                {
                    g = 1;
                    break;
                }
            if (g == 0)
                return false;
        }
        return true;
    }
    Iterator<T, Y> begin()
    {
        return{ vector,0 };
        
    }
    Iterator<T, Y> end()
    {
        return { vector + size,size };
    }
};
int main()

{
    Map<int, const char*> m;

    m[10] = "C++";

    m[20] = "test";

    m[30] = "Poo";

    for (auto [key, value, index] : m)

    {
        printf("Index:%d, Key=%d, Value=%s\n", index, key, value);
    }

    m[20] = "result";

    for (auto [key, value, index] : m)

    {
        printf("Index:%d, Key=%d, Value=%s\n", index, key, value);
    }
    printf("\n");
    m.Delete(20);
    for (auto [key, value, index] : m)

    {
        printf("Index:%d, Key=%d, Value=%s\n", index, key, value);
    }

    printf("\n");
    Map<int, const char*> map;
    map[10] = "C++";

    map[20] = "test";

    map[15] = "test";

    std::cout << m.Includes(map);
    return 0;
}