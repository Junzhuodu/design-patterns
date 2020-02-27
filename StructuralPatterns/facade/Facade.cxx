/*
 * C++ Design Patterns:
 * Author: Junzhuo Du [github.com/Junzhuodu]
 * 2020
 *
 */

#include <iostream>

class SubSystem1 {
public:
  void suboperation() {
    std::cout << "SubSystem1 operation" << std::endl;
  }
};

class SubSystem2 {
public:
  void suboperation() {
    std::cout << "SubSystem2 operation" << std::endl;
  }
};

class Facade {
public:
  Facade() {
    std::cout << "Facade" << std::endl;
    subsystem1 = new SubSystem1();
    subsystem2 = new SubSystem2();
  }

  ~Facade() {
    if (subsystem1) {
      delete  subsystem1;
    }
    if (subsystem2) {
      delete subsystem2;
    }
  }

  void operationWrapper() {
    subsystem1->suboperation();
    subsystem2->suboperation();
  }

private:
  SubSystem1 *subsystem1;
  SubSystem2 *subsystem2;
};

int main() {
  Facade facade;
  facade.operationWrapper();
}