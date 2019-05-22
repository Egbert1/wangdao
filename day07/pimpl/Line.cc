#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <fstream>
#include <map>
#include "Line.h"
using namespace std;

class Line::LineImpl{
    class Point{
    public:
        Point(int x=0,int y=0)
            :_x(x),_y(y){
                cout << "Point(int,int)" << endl;
            }

        void print(){
            cout <<"(" << _x << "," << _y << ")" ;
        }

        ~Point(){
            cout << "~Point()" << endl;
        }

    private:
        int _x,_y;
    };

public:
    LineImpl(int x,int y,int x1,int y1)
        :_pt1(x,y),_pt2(x1,y1){
            cout << "LineImpl(int,int,int,int)" << endl;
    }

    void print(){
        _pt1.print();
        cout << "---->" ;
        _pt2.print();
        cout << endl;
    }

private:
    Point _pt1,_pt2;
};

Line::Line(int x,int y,int x1,int y1)
    :_pImpl(new LineImpl(x,y,x1,y1)){
        cout << "Line(int,int,int,int)"<<endl;
    }

Line::~Line(){
    cout << "~Line()" << endl;
    if(_pImpl){
        delete _pImpl;
    }
}

void Line::printLine() const{
    _pImpl->print();
}
