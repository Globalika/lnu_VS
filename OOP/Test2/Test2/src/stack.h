#pragma once
using namespace std;
#include <vector>
#include <iostream>


template<typename T>
class Stack
{
public:
    void push(T);
    T pop();
    int GetCount();

private:
    int count = 0;
    vector<T> v;
};


template<class T>
int Stack<T>::GetCount()
{
    return this->count;
}

template<class T>
void Stack<T>::push(T elem)
{
    v.push_back(elem);
    count++;
}

template<class T>
T Stack<T>::pop()
{
    T elem = v.back();
    v.pop_back();
    count--;
    return elem;
}