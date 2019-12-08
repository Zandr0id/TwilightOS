#ifndef PAIR_H_
#define PAIR_H_

template<typename left_type, typename right_type>
class Pair
{
public:
    Pair(left_type left, right_type right);
    Pair(const Pair<left_type,right_type>&);
    Pair() {};
    ~Pair() {};
    left_type left();
    right_type right();
    void set_data(left_type left, right_type right);
private:
    left_type left_data_;
    right_type right_data_;
};




template<typename left_type, typename right_type>
Pair<left_type,right_type>::Pair(left_type left, right_type right)
{
    left_data_ = left;
    right_data_ = right;
}

template<typename left_type, typename right_type>
Pair<left_type,right_type>::Pair(const Pair<left_type,right_type> &old)
{
    left_data_ = old.left_data_;
    right_data_ = old.right_data_;
}
template<typename left_type, typename right_type>
left_type Pair<left_type, right_type>::left()
{
    return left_data_;
}

template<typename left_type, typename right_type>
right_type Pair<left_type, right_type>::right()
{
    return right_data_;
}

template<typename left_type, typename right_type>
void Pair<left_type, right_type>::set_data(left_type left, right_type right)
{
    left_data_ = left;
    right_data_ = right;
}
#endif //PAIR_H_