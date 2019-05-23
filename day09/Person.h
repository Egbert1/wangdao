#ifndef __PERSON_H__
#define __PERSON_H__

#include <string>
#include <iostream>

using namespace std;

class Person
{
public:
    Person(string name,int age):_name(name),_age(age) {}
    void display();
private:
    string _name;
    int _age;
};

void Person::display(){
    cout << "the employer's name is " << _name << endl;
    cout << "the employer's age is " << _age << endl;
}

#endif
