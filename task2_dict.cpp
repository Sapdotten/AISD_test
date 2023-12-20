// 2. Реализовать класс для хранения пар строковый ключ - значение.
// В классе необходимы конструкторы, деструктор, операция присваивания,
// операция обращения по строковому ключу, операция составного сложения
// с новой парой, операция сложения двух объектов класса.
// Контейнер реализовать в виде массива, максимальный размер передается
// как параметр конструктора и текущий размер показывает количество пар,
// которые там хранятся.
#include <string>
#include <vector>
#include <stdexcept>
using namespace std;
class Dict;
class Pair
{
    friend Dict;
    string key_;
    float value_;
    Pair() : key_("null"), value_(0){};
    Pair(const string key, const float value)
        : key_(key), value_(value) {}
    Pair(const Pair &other) = default;
    ~Pair() = default;
};

class Dict
{
    int capacity_, size_;
    vector<Pair> arr_;

public:
    Dict(int capacity) : capacity_(capacity), size_(0)
    {
        arr_.reserve(capacity_);
    }
    Dict(const Dict &other)
    {
        capacity_ = other.capacity_;
        size_ = other.size_;
        arr_ = vector<Pair>(other.arr_);
    }

    Pair *FindPair(const string &key)
    {
        for (int i = 0; i < size_; i++)
        {
            if (arr_[i].key_ == key)
                return &(arr_[i]);
        }
        return nullptr;
    }
    Dict &operator+=(const Pair &pair)
    {
        Pair *fpair = this->FindPair(pair.key_);
        if (fpair)
            *fpair = pair;
        else if (size_ < capacity_)
        {
            arr_.push_back(pair);
            size_++;
        }
        else
            throw out_of_range("Dict is full");
        return (*this);
    }

    Dict operator+(const Pair &pair) const
    {
        Dict dict(capacity_);
        dict += pair;
        return dict;
    }

    Dict operator+(const Dict &other) const
    {
        Dict dict((*this));
        for (int i = 0; i < other.size_; ++i)
        {
            dict += other.arr_.at(i);
        }
        return dict;
    }
    Dict &operator+=(const Dict &other)
    {
        (*this) = this->operator+(other);
        return (*this);
    }

    float &operator[](const string &key)
    {
        Pair *pair = this->FindPair(key);
        if (pair)
            return pair->value_;
        else
            throw invalid_argument("Invalid key");
    }
    float operator[](const string &key) const
    {
        float res = this->operator[](key);
        return res;
    }
};

int main()
{
    return 0;
}