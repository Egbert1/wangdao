#include <iostream>

using std::cout;
using std::endl;
using std::cin;



class Singleton{

public:
    static Singleton* getInstance(int x,int y){
        if(_pSingleton == nullptr){
            _pSingleton = new Singleton(x,y);
        }
        return _pSingleton;
    }

    void change(int x,int y){
        cout << "change(int x,int y) "<<endl;
        this->x = x;
        this->y = y;
    }

    void destory(){
        if(_pSingleton){
            delete _pSingleton;
        }
    }

    void print() const {
        cout << "x is " << x 
        << " y is " << y << endl;
    }

private:
    Singleton(){
        cout << "Singleton();" << endl;
    }
    Singleton(int a,int b):x(a),y(b){
        cout << "Singleton(int ,int )" << endl;
    }
    ~Singleton(){
        cout << "~Singleton();" << endl;
    }
    static Singleton * _pSingleton;

    int x;
    int y;
};

Singleton * Singleton::_pSingleton = nullptr;

int main()
{
    Singleton *p1 = Singleton::getInstance(1,2);
    cout << "p1->print : " << endl;
    p1->print();
    Singleton *p3 = Singleton::getInstance(3,4);
    cout << "p3->print : " << endl;
    p3->print();
    p3->change(3,4);
    p3->print();
    cout << "p1 = " << p1 <<endl;
    cout << "p3 = " << p3 <<endl;

    p1->destory();
    return 0;
}

