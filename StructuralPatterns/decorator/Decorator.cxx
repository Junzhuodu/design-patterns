/*
 * C++ Design Patterns:
 * Author: Junzhuo Du [github.com/Junzhuodu]
 * 2020
 *
 */

#include <iostream>
#include <string>

class Component {
public:
  virtual ~Component() {}

  virtual void operation() = 0;
};

class ConcreteComponent : public Component {
public:
  ~ConcreteComponent() {}

  void operation() {
    std::cout << "Concrete Component operation" << std::endl;
  }
};

class Decorator : public Component {
public:
  ~Decorator() {}

  Decorator(Component *c) : component_(c) {}

  virtual void operation() {
    component_->operation();
  }
private:
  Component *component_;
};

class ConcreteDecoratorA : public Decorator {
public:
  ConcreteDecoratorA(Component *c) : Decorator(c) {}

  void operation() {
    Decorator::operation();
    std::cout << "AddedBehavior for ConcreteDecoratorA" << std::endl;
  }
};

class ConcreteDecoratorB : public Decorator {
public:
  ConcreteDecoratorB(Component *c) : Decorator(c) {}

  void operation() {
      Decorator::operation();
      std::cout << "AddedBehavior for ConcreteDecoratorB" << std::endl;
  }
};

int main() {
  Component *cc = new ConcreteComponent();
  ConcreteDecoratorA *cda = new ConcreteDecoratorA(cc);
  ConcreteDecoratorB *cdb = new ConcreteDecoratorB(cc);

  cda->operation();
  cdb->operation();

}