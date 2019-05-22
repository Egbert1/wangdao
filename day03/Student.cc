#include <iostream>
#include <string.h>

using std::cout;
using std::endl;
using std::cin;

class Student{

public:
    Student(){};
    
    Student(const char* name,int id):_name(new char[strlen(name)+1]()),_id(id){
        cout << "Student(const char *,int)" << endl;
        strcpy(_name,name);
    }

    void print(){
        cout << "name is " << _name << endl
            << "id is " << _id << endl;
    }

    void destroy(){
        delete this;
    }

private:
    ~Student(){
        delete [] _name;
        cout << "private : ~Student();" << endl;
    }
    char *_name;
    int _id;
};




int main()
{
    Student *pstu = new Student("mk",10);
   // Student stu("mk",100);
    pstu->print();
    pstu->destroy();
    return 0;
}
