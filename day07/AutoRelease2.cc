#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <fstream>
#include <map>

using namespace std;

class Singleton{
public:
    
    static Singleton* getInstance(){
        pthread_once(&_once,init);
        return _pSingleton;
    }

    static void init(){
        _pSingleton = new Singleton();
        ::atexit(destroy);
    }

    static void destroy(){
        if(_pSingleton){
            cout << "destroy()::delete" << endl;
            delete _pSingleton;
        }
    }

    void print() const {
        cout << " print() " << endl;
    }

private:
    Singleton(){
        cout << "Singleton() " << endl;
    }

    ~Singleton(){
        cout << "~Singleton() " << endl;
    }

private:
    static Singleton * _pSingleton;
    static pthread_once_t _once;
};

Singleton* Singleton::_pSingleton = nullptr;
pthread_once_t Singleton::_once = PTHREAD_ONCE_INIT;

int main()
{
    Singleton * p = Singleton::getInstance();
    p->print();
    return 0;
}

