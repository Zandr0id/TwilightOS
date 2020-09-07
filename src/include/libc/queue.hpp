#ifndef QUEUE_H_
#define QUEUE_H_

#include <basics.h>
#include <libc/memory.h>

constexpr int queue_size_unit = 8;

template<typename T>
class Queue
{ 
public:
    Queue();
    ~Queue();
    void push(T item);
    T pop();
    unsigned int size(); //return the size
    unsigned int capacity(); //return the capacity
private:
    T * data_;
    void resize_up(); //get more space
    void resize_down(); //give up extra space
    unsigned int size_; //how many slots are filled
    unsigned int capacity_; //current max slots
    T operator[](int index);
};

template<typename T>
Queue<T>::Queue()
{
    size_ = 0;
    capacity_ = queue_size_unit;
    data_ = new T[capacity_];
}

template<typename T>
Queue<T>::~Queue()
{
    delete data_; // free the data section
}

//create a new data array that is larger,
//and copy the old one into it
template<typename T>
void Queue<T>::resize_up()
{
    //T * bigger_data = new T[capacity_ + vector_size_unit]; //make a new array that is larger
    T * bigger_data = new T[capacity_ + queue_size_unit]; //make a new array that is larger
    for (size_t i = 0; i<capacity_; i++)
    {
        bigger_data[i] = data_[i];
    }
    delete data_; // delete the old array
    data_ = bigger_data; //save the new one
    capacity_ += queue_size_unit; //update the max capacity
}

//if there's extra space unneeded,
//shrink the data array
template<typename T>
void Queue<T>::resize_down()
{
 //TODO: implement me
}

template<typename T>
void Queue<T>::push(T new_item)
{
    if(size_ >= capacity_)
    {
        resize_up();
    }

    data_[size_] = new_item; //put the new item at the end of the data array
    size_++;
}

template<typename T>
T Queue<T>::pop()
{
    T ret = data_[0];
    for(unsigned int i = 0; i < size_ ;i++)
    {
        data_[i] = data_[i+1];
    }
    size_--;
    return ret;
}

template<typename T>
unsigned int Queue<T>::size()
{
    return size_;
}

template<typename T>
unsigned int Queue<T>::capacity()
{
    return capacity_;
}

#endif //QUEUE_H_