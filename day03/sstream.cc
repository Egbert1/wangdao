#include <iostream>
#include <sstream>
#include <string>


using std::cout;
using std::endl;
using std::cin;

int main()
{
    int val1 = 200;
    int val2 = 400;

    std::stringstream ss;
    ss << " val1 = " << val1 << " val2  = " << val2;
    std::string str1 = ss.str();
    cout << str1 << endl;

    while(ss >> str1){
        cout << str1 << endl;
    }
    return 0;
}

