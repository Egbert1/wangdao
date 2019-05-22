#include <iostream>
#include "Queue.h"

using std::cout;
using std::endl;
using std::cin;

int main()
{
    Queue qu;

    qu.push(10);
    qu.push(12);
    qu.push(14);

    int size = qu.getSize();
    cout << "capacity is " << size << endl;
    int front = qu.front();
    int back = qu.back();
    cout << "front is " << front << endl
         << " back is " << back << endl;
    qu.pop();
    cout << "pop() "<<endl;
    size = qu.getSize();
    cout << "capacity is " << size << endl;
    
    return 0;
}

