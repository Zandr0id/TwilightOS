#include <libc/vector.h>
#include <assert.h>

template<typename T>
vector<T>::vector()
{
    size_ = 0;
    capacity_ = vector_size_unit;
    T new_array[capacity_];
    data_ = new_array;
}

//create a new data array that is larger,
//and copy the old one into it
template<typename T>
void vector<T>::resize_up()
{
 //TODO: implement me
}

//if there's extra space un needed,
//shrink the data array
template<typename T>
void vector<T>::resize_down()
{
 //TODO: implement me
}

template<typename T>
void vector<T>::push(T new_item)
{
    if(size_ >= capacity_)
    {
        resize_up();
    }

    data_[size_] = new_item; //put the new item at the end of the data array
    size_++;
}

template<typename T>
T vector<T>::pop()
{
    //return the top element, and back up one.
    return data_[size_--];
}