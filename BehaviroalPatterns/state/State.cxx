/*
 * C++ Design Patterns:
 * Author: Junzhuo Du [github.com/Junzhuodu]
 * 2020
 *
 */

#include <iostream>

class State {
public:
    virtual ~State() {}
    
    virtual void handle() = 0;
};

class ConcreteStateA : public State {
    ~ConcreteStateA() {}
    
    void handle() {
        std::cout << "State A handled." << std::endl;
    }
};

class ConcreteStateB : public State {
    ~ConcreteStateB() {}

    void handle() {
        std::cout << "State B handled." << std::endl;
    }
};

class Context {
public:
    Context() : state() {}
    ~Context() {
        if (state) {
            delete state;
        }
    }
    
    void setState(State* const s) {
        if (state) {
            delete state;
        }
        state = s;
    }
    
    void request() {
        state->handle();
    }
    
private:
    State* state;
};

int main() {
    Context* context = new Context();
    
    context->setState(new ConcreteStateA());
    context->request();
    
    context->setState(new ConcreteStateB());
    context->request();
}