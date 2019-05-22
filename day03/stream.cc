#include <iostream>
#include <ios>
#include <limits>
#include <string>

using std::cout;
using std::string;
using std::endl;
using std::cin;

void printStreamStatus(std::ios & ding){
    cout << "the badbit is " << ding.bad() << endl;
    cout << "the goodbit is " << ding.good() << endl;
    cout << "the eofbit is " << ding.eof() << endl;
    cout << "the failbit is " << ding.fail() << endl;
}


int test0(){
    int number;
    while(cin >> number, !cin.eof()){
        printStreamStatus(cin);
        cout << number << " 队友呢队友呢队友呢" << endl;
        if(cin.fail()){
        printStreamStatus(cin);
            cout << " ding ding ding mother fucker " << endl;
            break;
        }
    }
    printStreamStatus(cin);
    cin.clear();
    cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
    printStreamStatus(cin);

    string str1;
    cin >> str1;
    cout << str1 << "你气不气" << endl;
    return 0;
}



int main()
{
    test0();    
    return 0;
}

