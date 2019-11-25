#ifndef VECTOR_H_
#define VECTOR_H_

static const int vector_size_unit = 8;

template<typename T> //T will get replaced with whatever Typename is supplied
class vector
{
public:
    void push(T new_item);
    T pop();
    int size();
    void insert(int index, T new_item);
    vector();
private:
   T * data_;
   void resize_up();
   void resize_down();
   int size_; //how much is filled
   int capacity_; //current max spots
   
};


#endif //VECTOR_H_