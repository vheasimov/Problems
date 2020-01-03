#ifndef ISolution_h
#define ISolution_h


#include <iostream>

class ISolution
{
public:
    virtual void run() = 0;

    virtual void check(bool isOk)
    {
        if (isOk)
            std::cout << "OK" << std::endl;
        else
            std::cout << "FAIL" << std::endl;
    }
};



#endif // ISolution_h