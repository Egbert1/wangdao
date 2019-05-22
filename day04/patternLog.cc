#include <iostream>
#include <log4cpp/Category.hh>
#include <log4cpp/PatternLayout.hh>
#include <log4cpp/OstreamAppender.hh>
#include <log4cpp/Priority.hh>


using std::cout;
using std::endl;
using std::cin;

int main()
{
    using namespace log4cpp;
    Category & root = Category::getRoot();
    Category & infoc = root.getInstance("infoc");

    OstreamAppender * pOstreamAppender = new OstreamAppender("osAppender",&cout);
    PatternLayout *pLayout = new PatternLayout();
    pLayout->setConversionPattern("%d %p %c %x: %m %n");
    pOstreamAppender->setLayout(pLayout);

    //root.setAppender(pOstreamAppender);
    //root.setPriority(Priority::DEBUG);
    infoc.addAppender(pOstreamAppender);
    infoc.setPriority(Priority::INFO);

    infoc.emerg("this is an emerg message");
    infoc.fatal("this is a fatal message");
    infoc.alert("this is an alert message");
    infoc.crit("this is a crit message");
    infoc.error("this is a error message");
    infoc.warn("this is a warn message");
    infoc.notice("this is a notice message");
    infoc.info("this is a info message");
    infoc.debug("this is a debug message");


    Category::shutdown();
    return 0;
}

