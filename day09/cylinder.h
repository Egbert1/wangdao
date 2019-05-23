#ifndef __CYLINDER_H__
#define __CYLINDER_H__
#include "circle.h"


class Cylinder
:public Circle
{
public:
    
    Cylinder(double r,double h):Circle(r),_height(h) {}
    double getVolume();
    void showVolume();
private:
    double _height;
};

double Cylinder::getVolume(){
    return getArea() * _height;
}

void Cylinder::showVolume(){
    show();
    cout << "the cylinder's volume is " << getVolume() << endl;
}

#endif
