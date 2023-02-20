#include <iostream>

class A {
public:
    void methodA() {
        std::cout << "Method A called from class A" << std::endl;
    }
};

class B {
public:
    void methodB() {
        std::cout << "Method B called from class B" << std::endl;
    }
};

template<typename T>
using func_ptr = void (T::*)();

union func_union {
    func_ptr<A> funcA;
    func_ptr<B> funcB;
};

int main() {
    A objA;
    B objB;
    
    func_union funcs[] = { {&A::methodA}, {&B::methodB} };

    (objA.*funcs[0].funcA)(); // calls objA.methodA()
    (objB.*funcs[1].funcB)(); // calls objB.methodB()
    
    return 0;
}
