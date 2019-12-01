#ifndef ITERATOR_H_
#define ITERATOR_H_

#include <basics.h>

template<typename T>
class Iterator
{
public:
    Iterator();
    ~Iterator();
    Iterator<T>& operator++();
    Iterator<T> operator++(int);
    void reposition(T* start, T* end);
private:
    T* current_pos_;
    T* start_;
    T* end_;
};

template<typename T>
void Iterator<T>::reposition(T* start, T* end)
{
    current_pos_ = start;
    start_ = start;
    end_ = end;
}

template<typename T>
Iterator<T>::Iterator()
{
    current_pos_ = nullptr;
    start_ = nullptr;
    end_ = nullptr;
}

template<typename T>
Iterator<T>& Iterator<T>::operator++()
{
    current_pos_ += 1;
    return *this;
}

template<typename T>
Iterator<T> Iterator<T>::operator++(int)
{
    Iterator<T> temp = *this;
    *this+=1;
    return temp;
}


#endif //ITERATOR_H_