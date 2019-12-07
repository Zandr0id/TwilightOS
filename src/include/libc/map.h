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
    bool search(key_type key, value_type & value_dest);
    bool remove(key_type key);
private:
    Vector<key_type> keys_;
    Vector<value_type> values_;
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
    keys_.push_back(key);
    values_.push_back(value);
}

template<typename key_type, typename value_type>
bool Map<key_type,value_type>::search(key_type key, value_type & value_dest)
{
    typename Vector<key_type>::Iterator i = keys_.begin();
    while(i != keys_.end())
    {
        if(*i == key)
        {
            value_dest = values_[i.iterator_index()];
            return (true);
        }
    }
    return(false); 
}

template<typename key_type, typename value_type>
bool Map<key_type,value_type>::remove(key_type key)
{
    return false;
}


#endif //MAP_H_