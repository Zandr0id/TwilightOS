#ifndef VECTOR_H_
#define VECTOR_H_

#include <basics.h>
#include <libc/memory.h>
static const int vector_size_unit = 8; //auto resize by this amount

template<typename T> //T will get replaced with whatever Typename is supplied
class Vector
{
public:
    void push_back(T new_item); //add a new item
    T pop_back(); //return and remove
    unsigned int size(); //return the size
    unsigned int capacity(); //return the capacity
    void insert(unsigned int index, T new_item); //insert an item at a specific spot
    Vector();
    ~Vector();
private:
   T * data_;
   void resize_up(); //get more space
   void resize_down(); //give up extra space
   unsigned int size_; //how many slots are filled
   unsigned int capacity_; //current max slots
};

template<typename T>
Vector<T>::Vector()
{
    size_ = 0;
    capacity_ = vector_size_unit;
    data_ = new int[capacity_];
}

template<typename T>
Vector<T>::~Vector()
{
    delete data_; // free the data section
}

//create a new data array that is larger,
//and copy the old one into it
template<typename T>
void Vector<T>::resize_up()
{
    //T * bigger_data = new T[capacity_ + vector_size_unit]; //make a new array that is larger
    T * bigger_data = new T[capacity_ + vector_size_unit]; //make a new array that is larger
    for (size_t i = 0; i<capacity_; i++)
    {
        bigger_data[i] = data_[i];
    }
    delete data_; // delete the old array
    data_ = bigger_data; //save the new one
    capacity_ += vector_size_unit; //update the max capacity
}

//if there's extra space unneeded,
//shrink the data array
template<typename T>
void Vector<T>::resize_down()
{
 //TODO: implement me
}

template<typename T>
void Vector<T>::push_back(T new_item)
{
    if(size_ >= capacity_)
    {
        resize_up();
    }

    data_[size_] = new_item; //put the new item at the end of the data array
    size_++;
}

template<typename T>
void Vector<T>::insert(unsigned int index, T new_item)
{
    (void)index;
    (void)new_item;
    //TODO: implement me
}

template<typename T>
T Vector<T>::pop_back()
{
    //return the top element, and back up one.
    return data_[--size_];
}

template<typename T>
unsigned int Vector<T>::capacity()
{
    return capacity_;
}

template<typename T>
unsigned int Vector<T>::size()
{
    return size_;
}

#endif //VECTOR_H_