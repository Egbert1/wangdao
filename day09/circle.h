#ifndef __CIRCLE_H__
#define __CIRCLE_H__
#include <iostream>

using namespace std;
//圆类
class Circle
{
public:
    
    Circle():_radius(0.0) {}
    Circle(double r):_radius(r){}
    
    double getArea();     //获取圆的面积
    double getPerimeter();//获取圆的周长
    void show();          //输出半径、周长、面积  

private:
    double _radius;
};

double Circle::getArea(){
    return _radius * _radius;
}

double Circle::getPerimeter(){
    return 2 * 3.14 * _radius;
}

void Circle::show(){
    cout << "the circle's radius is " << _radius << endl;
    cout << "the circle's area is " << getArea() << endl;
    cout << "the circle's perimeter is " << getPerimeter() << endl;
}

#endif
