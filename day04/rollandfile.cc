#include <iostream>
#include <string>
#include <sstream>
#include <log4cpp/Category.hh>
#include <log4cpp/FileAppender.hh>
#include <log4cpp/RollingFileAppender.hh>
#include <log4cpp/Priority.hh>
#include <log4cpp/PatternLayout.hh>


using std::cout;
using std::endl;
using std::cin;

int main()
{
    using namespace log4cpp;
    Category & root = Category::getRoot();
    Category & infoc = root.getInstance("infoc");

    PatternLayout * pLayout = new PatternLayout();
    pLayout->setConversionPattern("%d %p %c %x : %m %n");
    PatternLayout * pLayout1 = new PatternLayout();
    pLayout1->setConversionPattern("%d %p %c %x : %m %n");

    Appender * fileApp = new FileAppender("fileApp","log.txt");
    fileApp->setLayout(pLayout);
    cout << "FileAppender over" << endl;
    RollingFileAppender * rfapp = new RollingFileAppender("rfapp","rolllog.txt",1024,5);
    rfapp->setLayout(pLayout1);

    infoc.setAppender(fileApp);
    infoc.setAppender(rfapp);
    infoc.setPriority(Priority::DEBUG);

    std::string strError;
    std::ostringstream oss;
    for(int i = 0;i< 100;i++){
        infoc.alert("this is an alert message");
        infoc.fatal("this is a fatal message");
        infoc.error("this is an error message");
    }


    Category::shutdown();
    return 0;
}

