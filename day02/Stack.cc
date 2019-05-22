#include <iostream>
#include "Stack.h"

using std::cout;
using std::endl;
using std::cin;

int main()
{
    Stack sta;
    
    sta.push(10);
    sta.push(12);
    sta.push(14);
    int size = sta.getSize();
    cout << "capacity = " << size << endl;
    int topValue = sta.top();
    cout << "top = " << topValue << endl;
    sta.pop();
    size = sta.getSize();
    cout << "after pop : capacity = " << size << endl;
    topValue = sta.top();
    cout << "top = " << topValue << endl;
   
    return 0;
}

