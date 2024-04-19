#include"node.h"
#ifndef STACK_H
#define STACK_H

template<class T> 
class Stack { 
    private: 
    Node<T>* top ; 

    public: 
    Stack() { 
        top = NULL; 
    }

    void Push(T value) { 
        Node<T>* newNode = new Node<T>;
        newNode ->value = value; 
        newNode ->next = top;
        top = newNode;
    }

    T Pop() {
        T value = top->value;
        Node<T>* p = top; 
        top = top -> next ; 
        delete p ; 
        return value;
    }
    
    bool IsEmpty() const { 
        return top == NULL; 
    }

    T GetTop() const { 
        return top -> value ;
    } 
};


#endif 