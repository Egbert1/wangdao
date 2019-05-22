#include <iostream>

namespace wd{
    int number = 10;
    void printf(){
        std::cout << "printf" << std::endl;
    }
    void cout(){
        std::cout << "cout" << std::endl;
    }
}

int number = 1000;

void printf(){
    std::cout << "void printf" << std::endl;
}

int main()
{
    std::cout << wd::number << std::endl;
    wd::printf();
    wd::cout();
    printf();
    std::cout << ::number << std::endl;
    std::cout << "Hello world" << std::endl;
    return 0;
}

