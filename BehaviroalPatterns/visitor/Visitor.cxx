/*
 * C++ Design Patterns:
 * Author: Junzhuo Du [github.com/Junzhuodu]
 * 2020
 *
 */

#include <iostream>

class Element;
class ConcreteElementA;
class ConcreteElementB;

class Vistor {
public:
    virtual ~Vistor() {}

    virtual void vistorElementA(ConcreteElementA* const element) = 0;
    virtual void vistorElementB(ConcreteElementB* const element) = 0;
};

class ConcreteVistor1 : public Vistor {
public:
    ~ConcreteVistor1() {}

    void vistorElementA(ConcreteElementA* const element);
    void vistorElementB(ConcreteElementB* const element);
};

class ConcreteVistor2 : public Vistor {
public:
    ~ConcreteVistor2() {}

    void vistorElementA(ConcreteElementA* const element);
    void vistorElementB(ConcreteElementB* const element);
};

class Element {
public:
    virtual ~Element() {}

    virtual  void accept(Vistor& v) = 0;
};

class ConcreteElementA : public Element {
public:
    ConcreteElementA(const std::string& data)
    : data_(data) {}
    ~ConcreteElementA() {}

    void accept(Vistor& v) {
        v.vistorElementA(this);
    }

    std::string getData() {
        return data_;
    }
private:
    std::string data_;
};

class ConcreteElementB : public Element {
public:
    ConcreteElementB(const std::string& data)
    : data_(data) {}
    ~ConcreteElementB() {}

    void accept(Vistor& v) {
        v.vistorElementB(this);
    }

    std::string getData() {
        return data_;
    }
private:
    std::string data_;
};

void ConcreteVistor1::vistorElementA(ConcreteElementA *const element) {
    std::cout << "Concrete Vistor 1 : Element A visited." << std::endl;
    std::cout << "Element A data: " << element->getData() << std::endl;
}

void ConcreteVistor1::vistorElementB(ConcreteElementB *const element) {
    std::cout << "Concrete Vistor 1 : Element B visited." << std::endl;
    std::cout << "Element B data: " << element->getData() << std::endl;
}

void ConcreteVistor2::vistorElementA(ConcreteElementA *const element) {
    std::cout << "Concrete Vistor 2 : Element A visited." << std::endl;
    std::cout << "Element A data: " << element->getData() << std::endl;
}

void ConcreteVistor2::vistorElementB(ConcreteElementB *const element) {
    std::cout << "Concrete Vistor 2 : Element B visited." << std::endl;
    std::cout << "Element B data: " << element->getData() << std::endl;
}

int main() {
    ConcreteElementA elementA("Hello");
    ConcreteElementB elementB("World");

    ConcreteVistor1 vistor1;
    ConcreteVistor2 vistor2;

    elementA.accept(vistor1);
    elementA.accept(vistor2);

    elementB.accept(vistor1);
    elementB.accept(vistor2);
}