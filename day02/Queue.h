#ifndef __QUEUE_H__
#define __QUEUE_H__

#include <iostream>


typedef struct node_t{
    
    int value;
    struct node_t *next;
    
}node_t,*pnode_t;

class Queue
{
public:
    Queue() {
        size = 10;
        phead = ptail = nullptr;
    }
    ~Queue() {
        node_t *node = nullptr;
        while(phead != nullptr){
            node = phead;
            phead = phead->next;
            delete node;
        }
    }

    void push(int);

    void pop();

    int front();

    int back();

    bool empty();

    bool full();

    int getSize();

private:
    node_t *phead,*ptail;
    int size;
};

#endif

void Queue::push(int x){
    node_t *node = new node_t;
    node->value = x;
    if(phead == nullptr){
        phead = ptail = node;
    }else{
        ptail -> next = node;
        ptail = node;
    }
    size--;
}

void Queue::pop(){
    node_t *node = nullptr;
    node = phead;
    phead = phead->next;
    size++;
    delete node;
}

int Queue::front(){
    return phead->value;
}

int Queue::back(){
    return ptail->value;
}

bool Queue::empty(){
    if(phead == nullptr){
        return true;
    }else{
        return false;
    }
}

bool Queue::full(){
    if(size == 0){
        return true;
    }else{
        return false;
    }
}

int Queue::getSize(){
    return size;
}
