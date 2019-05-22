#include <iostream>
#include "MutexCondi.h"

using std::cout;
using std::endl;
using std::cin;

#define N 10000000

int sum = 0;
MutexLock ml;
Condition cd(ml);
void *sumValue(void* n){
    cout << "sumValue" << endl;
    for(int i = 0;i<N;i++){
        ml.lock();
        sum += 1;
        ml.unlock();
    }
    cout << "pthread : Condition notify();" << endl;
    cd.notify();
    cout << "after pthread : Condition notify();" << endl;
}
int main()
{
    pthread_t phid=0;
    pthread_create(&phid,NULL,sumValue,NULL);
    cout << "Condition wait();" << endl;
    ml.lock();
    cout << "cd.wait() " << endl;
    cd.wait(); 
    ml.unlock();
    for(int i = 0;i<N;i++){
        ml.lock();
        /* ml.lock(); */
        sum += 1;
        ml.unlock();
    }
    pthread_join(phid,NULL);
    cout << " sum = " << sum << endl;
    return 0;
}

