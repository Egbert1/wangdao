#include "MyLoger.h"

using namespace std;

int main()
{
    MyLoger* myloger = MyLoger::getInstance();
    Category & root = myloger->logInit();
    LoggerWarn("hello");
    LoggerInfo("Info message");
    LoggerDebug("debug message");
    LoggerError("error message");
    myloger->destroy();
    myloger->MyLogerDestroy();
    return 0;
}

