/*
 * C++ Design Patterns:
 * Author: Junzhuo Du [github.com/Junzhuodu]
 * 2020
 *
 */

#include <iostream>

class AbstractClass {
public:
  virtual ~AbstractClass() {}

  void templateMethod() {
    primitiveOperation1();
    primitiveOperation2();
  }

  virtual void primitiveOperation1() = 0;
  virtual void primitiveOperation2() = 0;
};

class ConcreteClass : public AbstractClass {
public:
  ~ConcreteClass() {}

  void primitiveOperation1() {
    std::cout << "Primitive Operation 1" << std::endl;
  }

  void primitiveOperation2() {
    std::cout << "Primitive Operation 2" << std::endl;
  }
};

int main() {
  AbstractClass *templateClass = new ConcreteClass();
  templateClass->templateMethod();
}