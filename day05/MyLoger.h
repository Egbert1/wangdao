#ifndef __MYLOGER_H__
#define __MYLOGER_H__
#include <log4cpp/Category.hh>
#include <log4cpp/Priority.hh>
#include <log4cpp/OstreamAppender.hh>
#include <log4cpp/RollingFileAppender.hh>
#include <log4cpp/PatternLayout.hh>
#include <iostream>
#include <sstream>
using namespace std;
using namespace log4cpp;

#define LoggerWarn(msg) myloger->warn(GET_FNAME_LINE(msg),root);
#define LoggerInfo(msg) myloger->info(GET_FNAME_LINE(msg),root);
#define LoggerDebug(msg) myloger->debug(GET_FNAME_LINE(msg),root);
#define LoggerError(msg) myloger->error(GET_FNAME_LINE(msg),root);

#define GET_FNAME_LINE(msg) \
    string(msg).append(" < ").append(__FILE__).append(",").append(__FUNCTION__) \
    .append(",").append(std::to_string(__LINE__)).append(" > ")


class MyLoger{

public:
   static MyLoger* getInstance(){
       if(nullptr == myloger){
            myloger = new MyLoger();
       }  
        return myloger;
    }
    Category& logInit();
    void warn(string,Category&);
    void error(string,Category&);
    void info(string,Category&);
    void debug(string,Category&);
    void destroy(){
        Category::shutdown();
    }

    void MyLogerDestroy(){
        if(myloger){
            delete myloger;
        }
    }

private:
    MyLoger(){

    }
    ~MyLoger(){

    }

private:
    static MyLoger * myloger;
};

MyLoger * MyLoger::myloger = nullptr;

Category& MyLoger::logInit(){
    Category& root = Category::getRoot().getInstance("info");

    PatternLayout * pLayout = new PatternLayout();
    pLayout->setConversionPattern("%d : [%p] %c %x : %m %n");
    PatternLayout * pLayout1 = new PatternLayout();
    pLayout1->setConversionPattern("%d : [%p] %c %x : %m %n");

    OstreamAppender * pOstreamAppender = new OstreamAppender("ostreamappender",&cout);
    pOstreamAppender->setLayout(pLayout);


    Appender* rfapp = new RollingFileAppender("rfapp","rfappender.txt",2*1024,2);
    rfapp->setLayout(pLayout1);

    root.setAppender(rfapp);
    root.setAppender(pOstreamAppender);
    root.setPriority(Priority::DEBUG);
    
    return root;
}

void MyLoger::warn(string msg,Category & root){
    root.warn(msg);
}

void MyLoger::error(string msg,Category & root){
    root.error(msg);
}

void MyLoger::info(string msg,Category & root){
    root.info(msg);
}

void MyLoger::debug(string msg,Category & root){
    root.debug(msg);
}
        
#endif
