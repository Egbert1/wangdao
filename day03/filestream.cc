#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <ios>

using namespace std;
vector<string> vec;

void printStreamStatus(ios & ding){
    cout << "goodbit is  " << ding.good() << endl;
    cout << "badbit  is  " << ding.bad() << endl;
    cout << "failbit is  " << ding.fail() << endl;
    cout << "eofbit  is  " << ding.eof() << endl;
}

void test0(){
    ifstream ifs("Student.cc");
    if(!ifs){
        cout << "open file error" << endl;
        return;
    }

    printStreamStatus(ifs);

    string word;
    while(getline(ifs, word)){
        vec.push_back(word);
    }

    for(auto i : vec){
        cout << i << endl;
    }
    
    ifs.close();
}

void test1(){
    /* test0(); */
    ofstream ofd("data.txt",std::ios::app);
    if(!ofd){
        cout << "open file error " << endl;
        return;
    }

    cout << "pos = " << ofd.tellp() << endl;
#if 0
    for(auto &i : vec){
        ofd << i << "\n";
    }
#endif
    ofd << " that's a new line" << "\n";

    ofd.close();
}

void test2(){
    ifstream ifs("data.txt",std::ios::ate);
    if(!ifs){
        cout << "open file error " << endl;
    }
    ifs.seekg(std::ios::beg);
    string str1;
    while(getline(ifs,str1)){
        cout << str1 << endl;
    }
    ifs.clear();
    ifs.seekg(std::ios::beg);
    printStreamStatus(ifs);
    cout << "pos = " << ifs.tellg() << endl;
    printStreamStatus(ifs);
    cout << "pos = " << ifs.tellg() << endl;
}

void test3(){
    fstream fs("data1.txt");

    if(!fs){
        cout << "open file error " << endl;
    }

    int number;
    for(int i = 0;i<10;i++){
        cin >> number;
        fs << number << " ";
    }

    cout << endl;
    fs.clear();
    cout << "pos = " << fs.tellg() << endl;

    for(int i = 0;i<10;i++){
        cout << "pos = " << fs.tellg() << endl;
        fs >> number;
        cout << number << " ";
    }

    cout << endl;
    fs.close();
}

void test4(){
    string filename = "data1.txt";
    ifstream ifs(filename,std::ios::ate);
    
    if(!ifs){
        cout << "open file error" << endl;
        return ;
    }

    int length = ifs.tellg();
    ifs.seekg(0);
    char *buff = new char[length +1];
    ifs.read(buff,length);

    string content(buff);
    
    cout << content << endl;
    delete [] buff;
    ifs.close();
}

int main()
{
    //test1();
    /* test3(); */
    /* test2(); */
    test4();
    return 0;
}

