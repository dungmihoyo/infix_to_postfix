#ifndef NODE_H
#define NODE_H 
using namespace std ; 

template<class T> 
struct Node
{
    T value; 
    Node<T>* next ; 
};

#endif