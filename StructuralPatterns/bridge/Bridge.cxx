/*
 * C++ Design Patterns:
 * Author: Junzhuo Du [github.com/Junzhuodu]
 * 2020
 *
 */

#include <iostream>
#include <string>

class Implementor {
public:
  Implementor() { std::cout << "Implementor" << std::endl; }
  virtual ~Implementor() {}

  virtual void operationImp() = 0;
};

class ConcreateImplementorA : public Implementor {
public:
  ConcreateImplementorA() { std::cout << "ConcreateImplementorA" << std::endl; }
  ~ConcreateImplementorA() {}

  void operationImp() { std::cout << "This is operationImp from ConcreateImplementorA" << std::endl; }
};

class ConcreateImplementorB : public Implementor {
public:
  ConcreateImplementorB() { std::cout << "ConcreateImplementorB" << std::endl; }
  ~ConcreateImplementorB() {}

  void operationImp() { std::cout << "This is operationImp from ConcreateImplementorB" << std::endl; }
};

class Abstraction {
public:
  Abstraction() { std::cout << "Abstraction" << std::endl; }
  virtual ~Abstraction() {}

  virtual void operation() = 0;
};

class RefinedAbstraction : public Abstraction {
public:
  ~RefinedAbstraction() {}
  RefinedAbstraction(Implementor *ip) : implementor(ip) {
    std::cout << "RefinedAbstraction" << std::endl;
  }

  void operation() {
    implementor->operationImp();
  }

private:
  Implementor *implementor;
};

int main() {
  Implementor *imp1 = new ConcreateImplementorA();
  Abstraction *abs1 = new RefinedAbstraction(imp1);
  abs1->operation();

  Implementor *imp2 = new ConcreateImplementorB();
  Abstraction *abs2 = new RefinedAbstraction(imp2);
  abs2->operation();
}