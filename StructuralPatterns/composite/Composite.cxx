/*
 * C++ Design Patterns:
 * Author: Junzhuo Du [github.com/Junzhuodu]
 * 2020
 *
 */

#include <iostream>
#include <string>
#include <vector>

class Component {
public:
  Component() { std::cout << "Component" << std::endl; }
  virtual ~Component() {}

  virtual void operation() = 0;

  virtual void add(Component *) {};
  virtual void remove(Component *) {};
  virtual Component* getChild(int) { return nullptr; };
};

class Leaf : public Component {
public:
  Leaf(int id) : id_(id) { std::cout << "Leaf" << std::endl; }
  ~Leaf() {}

  void operation() { std::cout << "This is operation from Leaf: " << id_ << std::endl; }

private:
  int id_;
};

class Composite : public Component {
public:
  Composite() { std::cout << "Composite" << std::endl; }
  ~Composite() {
    for (unsigned int i = 0; i < children_.size(); ++i) {
      delete children_[i];
    }
  }

  void operation() {
    std::cout << "size of children: " << children_.size() << std::endl;
    for (unsigned int i = 0; i < children_.size(); ++i) {
      children_[i]->operation();
    }
  }

  void add(Component *c) {
    children_.push_back(c);
  }

  void remove(Component *c) {
    for (auto iter = children_.begin(); iter != children_.end(); ++iter) {
      if (*iter == c) {
        children_.erase(iter);
      }
    }
  }

  Component* getChild(unsigned int idx) {
    return idx < children_.size() ? children_[idx] : nullptr;
  }

private:
  std::vector<Component*> children_;
};

int main() {
  Composite composite;
  for (unsigned int i = 0; i < 3; ++i) {
    composite.add(new Leaf(i));
  }

  composite.add(new Composite);

  composite.remove(0);
  composite.operation();

  Component *component1 = composite.getChild(0);
  component1->operation();

  Component *component2 = composite.getChild(3);
  component2->operation();

}