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
  void partA(const std::string &part) {
    part_a = part;
  }
  void partB(const std::string &part) {
    part_b = part;
  }
  void partC(const std::string &part) {
    part_c = part;
  }

  void checkProduct() {
    std::cout << part_a + " " + part_b + " " + part_c + " have been created" << std::endl;
  }

private:
  std::string part_a;
  std::string part_b;
  std::string part_c;
};

class Builder {
public:
  Builder() { std::cout << "Builder" << std::endl; }
  virtual ~Builder() {}
  Product getProduct() { return product; }

  virtual void buildPartA() = 0;
  virtual void buildPartB() = 0;
  virtual void buildPartC() = 0;

protected:
  Product product;
};

class ConcreateBuilder1 : public Builder {
public:
  ConcreateBuilder1() { std::cout << "ConcreateBuilder1" << std::endl; }
  ~ConcreateBuilder1() {}

  void buildPartA() {
    product.partA("1-A");
  }
  void buildPartB() {
    product.partB("1-B");
  }
  void buildPartC() {
    product.partC("1-C");
  }

};

class ConcreateBuilder2 : public Builder {
public:
  ConcreateBuilder2() { std::cout << "ConcreateBuilder2" << std::endl; }
  ~ConcreateBuilder2() {}

  void buildPartA() {
    product.partA("2-A");
  }
  void buildPartB() {
    product.partB("2-B");
  }
  void buildPartC() {
    product.partC("2-C");
  }

};

class Director {
public:
  Director() { std::cout << "Director" << std::endl; }
  ~Director() {
    if (builder) {
      delete builder;
    }
  }

  void setBuilder(Builder *b) {
    if (builder) {
      delete builder;
    }
    builder = b;
  }

  Product getProduct() { return builder->getProduct(); }

  void construct() {
    builder->buildPartA();
    builder->buildPartB();
    builder->buildPartC();
  }

private:
  Builder *builder = nullptr;
};

int main(int argc, char* argv[]) {
  Director director;
  director.setBuilder(new ConcreateBuilder1);
  director.construct();

  Product product1 = director.getProduct();
  product1.checkProduct();

  director.setBuilder(new ConcreateBuilder2);
  director.construct();

  Product product2 = director.getProduct();
  product1.checkProduct();
}