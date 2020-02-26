/*
 * C++ Design Patterns:
 * Author: Junzhuo Du [github.com/Junzhuodu]
 * 2020
 *
 */

#include <iostream>
#include <string>

class Target {
public:
  Target() { std::cout << "Target" << std::endl; }
  virtual ~Target() {};

  virtual void request() = 0;
};

class Adaptee {
public:
  Adaptee() { std::cout << "Adaptee" << std::endl; }
  ~Adaptee() {}

  void specificRequest() { std::cout << "This is specific request" << std::endl; }
};

class Adapter : public Target, private Adaptee {
public:
  Adapter() { std::cout << "Adapter" << std::endl; }
  ~Adapter() {}

  void request() {
    specificRequest();
    std::cout << "This is request" << std::endl;
  }
};

int main() {
  Target *t = new Adapter();
  t->request();
}