/*
 * C++ Design Patterns:
 * Author: Junzhuo Du [github.com/Junzhuodu]
 * 2020
 *
 */

#include <iostream>
#include <string>

class Product {
public:
  Product() { std::cout << "Product" << std::endl; }
  virtual ~Product() {}

  virtual void checkProduct() = 0;
};

class ConcreateProductA : public Product {
public:
  ConcreateProductA() { std::cout << "ConcreateProductA" << std::endl; }
  ~ConcreateProductA() {}

  void checkProduct() { std::cout << "ProductA has been created" << std::endl; }
};

class ConcreateProductB : public Product {
public:
  ConcreateProductB() { std::cout << "ConcreateProductB" << std::endl; }
  ~ConcreateProductB() {}

  void checkProduct() { std::cout << "ProductB has been created" << std::endl; }
};

class Creater {
public:
  Creater() { std::cout << "Creater" << std::endl; }
  virtual ~Creater() {}

  virtual Product* createProductA() = 0;
  virtual Product* createProductB() = 0;
};

class ConcreateCreater : public Creater {
public:
  ConcreateCreater() { std::cout << "ConcreateCreater" << std::endl; }
  ~ConcreateCreater() {}

  Product* createProductA() { return new ConcreateProductA; }
  Product* createProductB() { return new ConcreateProductB; }
};

int main(int argc, char* argv[]) {
  Creater *creater = new ConcreateCreater;

  Product *productA = creater->createProductA();
  productA->checkProduct();

  Product *productB = creater->createProductB();
  productB->checkProduct();

}