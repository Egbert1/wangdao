#include <iostream>
#include <log4cpp/Category.hh>
#include <log4cpp/PatternLayout.hh>
#include <log4cpp/BasicLayout.hh>
#include <log4cpp/FileAppender.hh>
#include <log4cpp/OstreamAppender.hh>
#include <log4cpp/Priority.hh>

using std::cout;
using std::endl;
using std::cin;

int main()
{
    using namespace log4cpp;
    Category & root = Category::getRoot();

    OstreamAppender * pOstreamAppender = new OstreamAppender("OstreamAppender",&cout);
    pOstreamAppender->setLayout(new BasicLayout());

    root.setAppender(pOstreamAppender);
    root.setPriority(Priority::WARN);

    root.debug("this is a debug message");
    root.info("this is a info message");
    root.error("this is a error message");
    root.alert("this is a alert message");
    root.warn("this is a warn message");
    root.notice("this is a notice message");
    root.crit("this is a crit message");
    root.emerg("this is a emerge message");
    root.fatal("this is fatal message");
   
    Category::shutdown(); 
    return 0;
}

