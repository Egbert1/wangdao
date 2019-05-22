#ifndef __STACK_H__
#define __STACK_H__

#include <iostream>

using std::cout;
using std::endl;
using std::cin;

typedef struct _stack{
    int value;
    struct _stack *next;
}_stack,*_pstack;

class Stack
{
public:
    Stack(){
        vstack = nullptr;
        size = 10;
    }

    ~Stack(){
        _stack *node_t = nullptr;
        while(vstack != nullptr){
            node_t = vstack;
            vstack = vstack -> next;
            delete node_t;
        }
    }

    void push(int);
    
    int getSize();

    void pop();
    
    int top();
    
    bool empty();
    
    bool full();

private:
    _stack *vstack;
    int size;
};

void Stack::push(int x){
    cout << "Stack::push"<<endl;
    _stack *top = new _stack;
    if(size > 0){
        size--;
    }else{
        cout << "超出长度"<<endl;
    }
    top->value = x;
    top->next = vstack;
    vstack = top;
}

void Stack::pop(){
    _stack *node_t = vstack;
    vstack = vstack -> next;
    delete node_t;
    size++;
}

int Stack::top(){
    return vstack->value;
}

bool Stack::empty(){
    if(vstack->next == nullptr){
        return true;
    }else{
        return false;
    }
}

bool Stack::full(){
    if(size == 0){
        return true;
    }else{
        return false;
    }
}

int Stack::getSize(){
    return size;
}

#endif
