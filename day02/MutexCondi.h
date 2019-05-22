#ifndef __MUTEXCONDI_H__
#define __MUTEXCONDI_H__

#include <iostream>
#include <pthread.h>
using std::cout;
using std::endl;
using std::cin;



class MutexLock{
public:
    MutexLock(){
        pthread_mutex_init(&mutex,NULL);
    }

    ~MutexLock(){
        pthread_mutex_destroy(&mutex);
    }

    pthread_mutex_t * getMutexAddr(){
        return &mutex;
    }

    void lock(){
        pthread_mutex_lock(&mutex);
    }

    void unlock(){
        pthread_mutex_unlock(&mutex);
    }

private:
    pthread_mutex_t mutex;
};

class Condition{
public:

    Condition(MutexLock & mutex) : _mutex(mutex){
        pthread_cond_init(&_cond,NULL);
    }

    ~Condition(){
        pthread_cond_destroy(&_cond);
    }

    void wait(){
        pthread_cond_wait(&_cond,_mutex.getMutexAddr());
    }

    void notify(){
        pthread_cond_signal(&_cond);
    }

    void notifyall(){
        pthread_cond_broadcast(&_cond);
    }

private:
    pthread_cond_t _cond;
    MutexLock & _mutex;
};

#endif

