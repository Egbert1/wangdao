#include <iostream>
#include "statistic.h"
using std::cout;
using std::endl;
using std::cin;

int main()
{
    Statistic sta;
    sta.read("The_Holy_Bible.txt");
    sta.store("data.txt");
    cout << "get"<<endl;
    return 0;
}

