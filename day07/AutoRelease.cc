#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <fstream>
#include <map>

using namespace std;

class Singleton{

    class release{
    public:
        release(){
            cout << "class release::release() " << endl;
        }

        ~release(){
            cout << "class release::~release()" << endl;
            if(_pSingleton){
                delete _pSingleton;
            }
        }
    };

public:
    void print() { cout << "print()" << endl; }
   
    static Singleton * getInstance() {
        if(_pSingleton == nullptr){
            _pSingleton = new Singleton();
        }
        return _pSingleton;
    }
    friend class release;
private:

    Singleton(){
        cout << "Singleton() " << endl;
    }

    ~Singleton(){
        cout << "~Singleton() " << endl;
    }

private:
    static Singleton * _pSingleton;
    static release _prelease;
};

Singleton * Singleton::_pSingleton = nullptr;
Singleton::release  Singleton::_prelease;

int main()
{
    Singleton * p = Singleton::getInstance();
    p->print();
    return 0;
}

