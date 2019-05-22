#include <string.h>
#include <iostream>

using std::cout;
using std::endl;
using std::cin;

class String
{
public:
    String():_pstr(new char[1]) {}
    String(const char *pstr);
    String(const String &rhs);
    String & operator=(const String &rhs);
    void print();
    ~String() {
        cout << "~String();"<<endl;
        delete  _pstr;
    }

private:
    char *_pstr;

};

String::String(const char *pstr)/*:_pstr(new char[strlen(pstr)+1])*/{
    _pstr = new char[strlen(pstr) + 1]; 
    strcpy(_pstr,pstr);
}

String::String(const String &rhs):_pstr(new char[strlen(rhs._pstr)+1]){
    strcpy(_pstr,rhs._pstr);
}

String& String::operator=(const String &rhs){
    _pstr = new char[strlen(rhs._pstr)+1];
    strcpy(_pstr,rhs._pstr);
    return *this;
}

void String::print(){
    cout<< "_pstr is " << _pstr << endl;
}
