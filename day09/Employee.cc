#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <fstream>
#include <map>
#include "Employee.h"

int main()
{
    Employee ee1("mk",200,"computer science ",10);    
    Employee ee2("mk1",250,"xaaaaaa",30);    
    Employee ee3("mk",200,"revenger ",12);

    ee1.display();
    cout << "---------------" << endl;
    cout << endl;
    ee2.display();
    cout << "---------------" << endl;
    cout << endl;
    ee3.display();
    return 0;
}

