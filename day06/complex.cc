#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <fstream>
#include <map>

using namespace std;

class Complex{

public:
    Complex(double real,double image) 
    :_real(real),_image(image){
        cout << "Complex(double,double);" << endl;
    }

    void print(){
        cout <<"the number is " <<  _real << " + " << _image << "i" << endl;
    }

    int getReal() const { return _real; }
    int getImage() const { return _image; }

    ~Complex(){
        cout << "~Complex" << endl;
    }

private:
    int _real;
    int _image;
};

Complex operator+(const Complex & lhs,const Complex & rhs){
    return Complex(lhs.getReal()+rhs.getReal(),
                   lhs.getImage()+ rhs.getImage());
}


int main()
{
    Complex c1(3,4);
    Complex c2(1,2);
    Complex c3 = c1 + c2;
    cout << "c1.print()" << endl;
    c1.print();
    cout << "c2.print()" << endl;
    c2.print();
    cout << "c3.print()" << endl;
    c3.print();
    return 0;
}

