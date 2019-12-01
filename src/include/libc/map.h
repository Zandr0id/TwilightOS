#ifndef MAP_H_
#define MAP_H_

#include <basics.h>
#include <libc/memory.h>
#include <libc/vector.h>

template<typename key_type, typename value_type>
class Map
{
public:
    Map();
    ~Map();
    void insert(key_type key, value_type value);
    value_type search(key_type key);
    bool remove(key_type key);
private:
    Vector<key_type> keys;
    Vector<value_type> values;
};

template<typename key_type, typename value_type>
Map<key_type, value_type>::Map()
{

}

template<typename key_type, typename value_type>
Map<key_type,value_type>::~Map()
{

}

template<typename key_type, typename value_type>
void Map<key_type,value_type>::insert(key_type key, value_type value)
{
    keys.push_back(key);
    values.push_back(value);
}

template<typename key_type, typename value_type>
value_type Map<key_type,value_type>::search(key_type key)
{

}

template<typename key_type, typename value_type>
bool Map<key_type,value_type>::remove(key_type key)
{

}


#endif //MAP_H_