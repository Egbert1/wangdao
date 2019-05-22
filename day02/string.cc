#include <iostream>
#include "String.h"
using std::cout;
using std::endl;
using std::cin;

int main()
{
    String str1;
    str1.print();
    
    String str2 = "hello,world";
    String str3("wangdao");
    str2.print();
    str3.print();
    
    String str4 = str3;
    str4.print();
    
    str4 = str2;
    str4.print();

    return 0;
}

