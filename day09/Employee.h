#ifndef __EMPLOYEE_H__
#define __EMPLOYEE_H__
#include "Person.h"

class Employee
:public Person
{
public:
    Employee(string name,int age,string department,double salary)
    :Person(name,age),_department(department),_salary(salary){}
    ~Employee() {}

    void display();

private:
    string _department;
    double _salary;
};

void Employee::display(){
    Person::display();
    cout << "the employer's department is " << _department << endl;
    cout << "the employer's salary is " << _salary << endl;
}

#endif
