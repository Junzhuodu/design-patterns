/*
 * C++ Design Patterns:
 * Author: Junzhuo Du [github.com/Junzhuodu]
 * 2020
 *
 */

#include <iostream>
#include <string>

class Handler {
public:
    virtual ~Handler() {}

    void setSuccessor(Handler *s) {
        successor_ = s;
    }

    Handler* getSuccessor() {
        return successor_;
    }

    virtual void handleRequest() = 0;
private:
    Handler *successor_;
};

class ConcreteHandler1 : public Handler {
public:
    ~ConcreteHandler1() {}

    void handleRequest() {
        if (!this->getSuccessor()) {
            std::cout << "This is handled by Concrete Handler 1" << std::endl;
        }
        else {
            std::cout << "This will be handled by the Successor" << std::endl;
            this->getSuccessor()->handleRequest();
        }
    }
};

class ConcreteHandler2 : public Handler {
public:
    ~ConcreteHandler2() {}

    void handleRequest() {
        if (!this->getSuccessor()) {
            std::cout << "This is handled by Concrete Handler 2" << std::endl;
        }
        else {
            std::cout << "This will be handled by the Successor" << std::endl;
            this->getSuccessor()->handleRequest();
        }
    }
};

int main() {
    Handler* h1 = new ConcreteHandler1();
    Handler* h2 = new ConcreteHandler2();

    h1->setSuccessor(h2);
    h1->handleRequest();
}