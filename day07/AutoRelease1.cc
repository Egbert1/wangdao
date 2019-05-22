#include <iostream>
#include <vector>
#include <stdlib.h>
#include <string>
#include <sstream>
#include <fstream>
#include <map>

using namespace std;

class Singleton{
public:
    static Singleton * getInstance(){
        if(_pSingleton == nullptr){
            _pSingleton = new Singleton();
            atexit(destroy);
        }
        return _pSingleton;
    }

    static void destroy(){
        if(_pSingleton){
            cout << "destroy() :: delete" << endl;
            delete _pSingleton;
        }
    }

    void print() const {
        cout << " print() " << endl;
    }

private:
    Singleton(){
        cout << "Singleton()" << endl;
    }

    ~Singleton(){
        cout << "~Singleton()" << endl;
    }


private:
    static Singleton * _pSingleton;
};

Singleton * Singleton::_pSingleton = nullptr;


int main()
{
    Singleton * p = Singleton::getInstance();
    p -> print();
    return 0;
}

