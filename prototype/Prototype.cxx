/*
 * C++ Design Patterns:
 * Author: Junzhuo Du [github.com/Junzhuodu]
 * 2020
 *
 */

#include <iostream>
#include <string>

class Prototype {
public:
  Prototype() { std::cout << "Prototpye" << std::endl; }
  virtual ~Prototype() {}

  virtual Prototype* clone() = 0;
  virtual void checkPrototype() = 0;
};

class ConcreatePrototype1 : public Prototype {
public:
  ConcreatePrototype1() { std::cout << "ConcreatePrototype1" << std::endl; }
  ~ConcreatePrototype1() {}

  Prototype* clone() { return new ConcreatePrototype1; }
  void checkPrototype() { std::cout << "Prototype1 has been created" << std::endl; }
};

class ConcreatePrototype2 : public Prototype {
public:
  ConcreatePrototype2() { std::cout << "ConcreatePrototype2" << std::endl; }
  ~ConcreatePrototype2() {}

  Prototype* clone() { return new ConcreatePrototype2; }
  void checkPrototype() { std::cout << "Prototype2 has been created" << std::endl; }
};

class Client {
public:
  Client() { std::cout << "Client" << std::endl; }
  ~Client() {
    if (prototype) {
      delete prototype;
    }
  }

  void setPrototype(Prototype *p) {
    if (prototype) {
      delete prototype;
    }
    prototype = p;
  }
  Prototype* clone() {
    if (!prototype) {
      return nullptr;
    }
    return prototype->clone();
  }

private:
  Prototype *prototype;
};

int main(int argc, char* argv[]) {
  Client client;
  client.setPrototype(new ConcreatePrototype1);
  Prototype *p1 = client.clone();
  p1->checkPrototype();

  client.setPrototype(new ConcreatePrototype2);
  Prototype *p2 = client.clone();
  p2->checkPrototype();

}