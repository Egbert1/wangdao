#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <fstream>
#include <limits>
#include <map>

using namespace std;

class Complex{
public:
    Complex(double real = 0.0,double image = 0.0)
        :_real(real),_image(image){
            cout << "Complex(double,double)" << endl;
        }

    void print(){
        cout << _real << " + " << _image << "i" << endl;
    }

    double getReal() const { return _real; }
    double getImage() const { return _image; }

    Complex & operator+=(const Complex & lhs){
        _real += lhs.getReal();
        _image += lhs.getImage();
        return *this;
    }
    friend ostream & operator<<(ostream & os , const Complex & lhs);
    friend istream & operator>>(istream & os ,Complex & lhs);
    friend void readDouble(istream & is,double & value);
private:
    double _real;
    double _image;
};

Complex operator+(const Complex & lhs,const Complex & rhs){
    Complex tmp(lhs);
    tmp += rhs;
    return tmp;
}

bool operator==(const Complex & lhs ,const Complex & rhs){
    return (lhs.getReal() == rhs.getReal() && (lhs.getImage() == rhs.getImage()));
}

bool operator!=(const Complex & lhs,const Complex & rhs){
    return !(lhs == rhs);
}

ostream & operator<<(ostream & os , const Complex & lhs){
    os << lhs._real << " + " << lhs._image << "i" << endl;
    return os;
}

void readDouble(istream & is,double & value){
    while(is >> value,!is.eof()){
        if(is.bad()){
            cout << "istream is corrupted " << endl;
            break;
        }else if(is.fail()){
            is.clear();
            is.ignore(numeric_limits<streamsize>::max(),'\n');
            cout << " >> pls input an invalid number;" << endl;
            continue;
        }
        break;
    }
}

istream & operator>>(istream & os , Complex & lhs){
    readDouble(os,lhs._real);
    readDouble(os,lhs._image);
    return os;
}

int main()
{
    Complex c1(1,2);
    Complex c2(3,3);
    Complex c4;
    Complex c3 = c1+c2;
    /* c3.print(); */
    cin >> c4;
    cout << c4;
    cout << c3;
    return 0;
}

