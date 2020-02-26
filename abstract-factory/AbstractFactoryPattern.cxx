/*
 * C++ Design Patterns:
 * Author: Junzhuo Du [github.com/Junzhuodu]
 * 2020
 *
 */

#include <iostream>

class AbstractProductA {
public:
  AbstractProductA() { std::cout << "AbstractProductA" << std::endl; }
  virtual ~AbstractProductA() {}
  virtual void checkProduct() = 0;
};

class AbstractProductB {
public:
  AbstractProductB() { std::cout << "AbstractProductB" << std::endl; }
  virtual  ~AbstractProductB() {}
  virtual void checkProduct() = 0;
};

class ProductA1 : public AbstractProductA {
public:
  ProductA1() { std::cout << "ProductA1" << std::endl; }
  ~ProductA1() {}
  void checkProduct() { std::cout << "ProductA1 has been created" << std::endl;}

};

class ProductA2 : public AbstractProductA {
public:
  ProductA2() { std::cout << "ProductA2" << std::endl; }
  ~ProductA2() {}
  void checkProduct() { std::cout << "ProductA2 has been created" << std::endl; }

};

class ProductB1 : public AbstractProductB {
public:
  ProductB1() { std::cout << "ProductB1" << std::endl; }
  ~ProductB1() {}
  void checkProduct() { std::cout << "ProductB1 has been created" << std::endl; }

};

class ProductB2 : public AbstractProductB {
public:
  ProductB2() { std::cout << "ProductB2" << std::endl; }
  ~ProductB2() {}
  void checkProduct() { std::cout << "ProductB2 has been created" << std::endl; }

};

class AbstractFactory {
public:
  AbstractFactory() { std::cout << "AbstractFactory" << std::endl; }
  virtual ~AbstractFactory() {}
  virtual AbstractProductA* createProductA() = 0;
  virtual AbstractProductB* createProductB() = 0;
};

class ConcreateFactory1 : public AbstractFactory {
public:
  ConcreateFactory1() { std::cout << "ConcreateFactory1" << std::endl; }
  ~ConcreateFactory1() {}
  AbstractProductA* createProductA() { return new ProductA1; }
  AbstractProductB* createProductB() { return new ProductB1; }
};

class ConcreateFactory2 : public AbstractFactory {
public:
  ConcreateFactory2() { std::cout << "ConcreateFactory2" << std::endl; }
  ~ConcreateFactory2() {}
  AbstractProductA* createProductA() { return new ProductA2; }
  AbstractProductB* createProductB() { return new ProductB2; }
};

int main(int argc, char* argv[]) {
  AbstractFactory* cf1 = new ConcreateFactory1();
  AbstractProductA* productA1 = cf1->createProductA();
  productA1->checkProduct();
  AbstractProductB* productB1 = cf1->createProductB();
  productB1->checkProduct();

  AbstractFactory* cf2 = new ConcreateFactory2();
  AbstractProductA* productA2 = cf2->createProductA();
  productA2->checkProduct();
  AbstractProductB* productB2 = cf1->createProductB();
  productB2->checkProduct();

}