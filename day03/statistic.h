#ifndef __STATISTIC_H__
#define __STATISTIC_H__

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>

using namespace std;

class Statistic
{
public:
    void read(const string & inputfile);
    void store(const string & outputfile);
private:
    map<string,size_t> wordInfo;
};

void Statistic::read(const string & inputfile){
    ifstream ifs(inputfile);
    string word;
    while(ifs >> word){
        ++wordInfo[word];
    }
    ifs.close();
}

void Statistic::store(const string & outputfile){
    ofstream ofs(outputfile);
    if(!ofs){
        cout << " open file error " << endl;
    }

    for(auto & mapword : wordInfo){
        ofs << mapword.first << " " << mapword.second << endl;
    }

    ofs.close();
}

#endif

