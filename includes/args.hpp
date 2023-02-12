#ifndef ARGS_HPP
#define ARGS_HPP

#include <iostream>

class Base {
public:
    virtual void methodA() { std::cout << "Base::methodA()" << std::endl; }
    virtual void methodB() { std::cout << "Base::methodB()" << std::endl; }
};

#endif // ARGS_HPP