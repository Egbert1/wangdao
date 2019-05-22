#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <fstream>
#include <map>

using namespace std;

struct FunctionObject{

    int operator()(int x,int y){
        ++_count;
        return x+y;
    }

    int operator()(int x,int y,int z){
        return x * y * z;
    }

    int getCount() const { return _count; }

private:
    int _count = 0;
};

int add(int x,int y){
    static int count = 0;
    ++count;
    cout << "函数调用了" << count << "次" << endl;
    return x+y;
}


int main()
{
    int a = 3,b = 4;
    add(a,b);

    cout << "add(a,b) = " << add(a,b) << endl;
    
    FunctionObject fo;
    fo(a,b);
    cout << "fo(a,b) = " << fo(a,b) << endl;
    cout << "fo(a,b) 被调用了 " << fo.getCount() << endl;

    return 0;
}

