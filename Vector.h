//
// Created by zhuxingtian on 18-9-29.
//

#ifndef DS_VECTOR_H
#define DS_VECTOR_H
typedef int Rank;
#define DEFAULT_CAPACITY 5

#include <iostream>
#include <cstdlib>
#include <ctime>

using std::cout;
using std::endl;

template <typename Type>
class Vector {
protected:
    Rank _size; //规模
    int _capacity;  //容量
    Type * _elem;   //数据区
    void expand();  //空间不足时扩容

public:
    Vector();
    Vector(int n);
    Vector(const Vector & other);
    void print()const;
    bool isEmpty()const;
    void reverse();
    void push_back(Type x);
    Type & operator [](int i);
    ~Vector();
};

template <typename Type>
Vector<Type>::Vector() {
    this->size = 0;
    this->elem = nullptr;
}

template <typename Type>
Vector<Type>::Vector(int n) {
    this->size = n;
    _elem = new Type[n];
    srand(unsigned(time(nullptr)));
    for(int i = 0;i < this->size;i++) {
        _elem[i] = rand()%10;
    }
}

template <typename Type>
Vector<Type>::Vector(const Vector &other) {
    this->size = other.size;
    _elem = new Type[other.size];
    for(int i = 0;i < this->size;i++){
        this->_elem[i] = other._elem[i];
    }
}

template <typename Type>
void Vector<Type>::print() const {
    for(int i = 0; i <this->size;i++){
        cout << _elem[i] << "  ";
    }
    cout << endl;
}

template  <typename Type>
bool Vector<Type>::isEmpty() const {
    if(_elem){
        return false;
    }
    return true;
}

template <typename Type>
void Vector<Type>::reverse() {
    for(int i = 0;i < this->size/2 ;i++){
        Type temp = _elem[this->size - i -1];
        _elem[this->size - i -1] = _elem[i];
        _elem[i] = temp;
    }
}


template <typename Type>
Type& Vector<Type>::operator[](int i) {
    return this->_elem[i];
}

template <typename Type>
void Vector<Type>::expand() {
    if(_size < _capacity){
        return;
    }
    if(_capacity < DEFAULT_CAPACITY){
        _capacity = DEFAULT_CAPACITY;
    }

    Type * oldElem = _elem;
    _elem = new Type[_capacity << = 1];

    for(int i = 0;i < _size;i++){
        _elem[i] = oldElem[i];
    }

    delete [] oldElem;
}

template <typename Type>
void Vector<Type>::push_back(Type x) {
    if(_size > _capacity){
        expand();
    }
    _elem[_size++] = x;
}

template <typename Type>
Vector<Type>::~Vector() {
    delete [] this->_elem;
}
#endif //DS_VECTOR_H
