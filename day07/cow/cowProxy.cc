#include <iostream>
#include <string.h>
#include <vector>
#include <string>
#include <sstream>
#include <fstream>
#include <map>

using namespace std;
//cowString 写时复制
class cowString{

    class cowProxy{
        public:
            cowProxy(int idx,cowString & cow) : _idx(idx),_cowString(cow){}

            char & operator=(const char & ch){
               int sz = _cowString.size();
               if(_idx >= 0 && _idx < sz){
                   if(_cowString.getRefcount() > 1){
                        _cowString.decreaseRefcount();

                        char * ptmp = new char[sz + 5] + 4;
                        strcpy(ptmp,_cowString._pcowString);
                        _cowString._pcowString = ptmp;
                        _cowString.initRefcount();
                   }
                   _cowString._pcowString[_idx] = ch;
                   return _cowString._pcowString[_idx];
               }else{
                   cout << "下标越界" << endl;
                   static char nullchar = '\0';
                   return nullchar;
               }
            }

            friend ostream & operator<<(ostream & os,const cowProxy & lhs);

        private:
            int _idx;
            cowString & _cowString;
    };
    friend class cowProxy;
    friend ostream & operator<<(ostream & os,const cowProxy & lhs);
public:
    cowString()
        :_pcowString(new char[5]()+4){
        cout << "cowString()" << endl;
        initRefcount();
    }
    
    cowString(const char * str1)
        :_pcowString((new char[strlen(str1) + 5])+4){
        strcpy(_pcowString,str1);
        initRefcount();
    }

    cowString(const cowString & lhs){
       _pcowString = lhs._pcowString;
       increaseRefcount();
    }
    
    cowString & operator=(const char * str1){
        if(!strcmp(_pcowString,str1)){
            delete (_pcowString-4);
            _pcowString = (new char[strlen(str1)+5])+4;
            strcpy(_pcowString,str1);
        }
        increaseRefcount();
        return *this;
    }

    cowString & operator=(const cowString & rhs){
        if(this != &rhs){
            destroy();

            _pcowString = rhs._pcowString;
            increaseRefcount();
        }
        return *this;
    }

    int increaseRefcount(){
        return ++*(int *)(_pcowString-4);
    }

    int decreaseRefcount(){
        return --*(int *)(_pcowString-4);
    }

    int getRefcount(){
        return *(int *)(_pcowString-4);
    }

    void initRefcount() { *(int *)(_pcowString-4) = 1; }
    
    int size() { return strlen(_pcowString); }
  
    void destroy(){
        decreaseRefcount();
        if(getRefcount() == 0)
            delete (_pcowString-4);
    }

    ~cowString(){
        destroy();        
    }

    const char * c_str() const { return _pcowString; }

    cowProxy operator[](int idx){
        return cowProxy(idx,*this);  
    }

    friend ostream & operator<<(ostream & os,const cowString & rhs);

private:
    char * _pcowString;
};                

ostream & operator<<(ostream & os,const cowString & rhs){
    os << rhs._pcowString;
    return os;
}
ostream & operator<<(ostream & os,const cowString::cowProxy & lhs){
    os << lhs._cowString._pcowString[lhs._idx];
    return os;
}

int main()
{
    cowString s0;
    cout << "s0 = " << s0 << endl;
    cowString s1("hello,world");
    cowString s2 = s1;
    cowString s3("shenzhen");
    cout << " s1 = " << s1 << endl;
    cout << " s2 = " << s2 << endl;
    printf("s1's address is %p\n",s1.c_str());
    printf("s2's address is %p\n",s2.c_str());
    cout << "s1's refcount is " << s1.getRefcount()<<endl;
    cout << "s2's refcount is " << s2.getRefcount()<<endl;
    s2 = s3;
    cout << "s3 = " << s3 << endl;
    cout << "执行s2 = s3 之后 ：" << endl;
    cout << " s2 = " << s2 << endl;
    cout << " s3 = " << s3 << endl;
    printf("s2's address is %p\n",s2.c_str());
    printf("s3's address is %p\n",s3.c_str());
    cout << "s2's refcount is " << s2.getRefcount()<<endl;
    cout << "s3's refcount is " << s3.getRefcount()<<endl;
    
    cowString s4 = s3;
    cout << "s4 = s3 : " << s4 << endl;
    printf("s3's address is %p\n",s3.c_str());
    printf("s4's address is %p\n",s4.c_str());
    cout << "s3's refcount is " << s3.getRefcount()<<endl;
    cout << "s4's refcount is " << s4.getRefcount()<<endl;
    cout << "执行s4[0] = 'S' 之后 ：" << endl;
    s4[0] = 'S';
    cout << "s4[0] = " << s4[0] << endl;
    cout << endl;
    printf("s3's address is %p\n",s3.c_str());
    printf("s4's address is %p\n",s4.c_str());
    cout << "s3's refcount is " << s3.getRefcount()<<endl;
    cout << "s4's refcount is " << s4.getRefcount()<<endl;


    return 0;
}

