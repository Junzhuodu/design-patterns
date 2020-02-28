/*
 * C++ Design Patterns:
 * Author: Junzhuo Du [github.com/Junzhuodu]
 * 2020
 *
 */

#include <iostream>
#include <vector>

class Iterator;
class ConcreteIterator;

class Aggregate {
public:
  virtual ~Aggregate() {}

  virtual Iterator* createIterator() = 0;
};

class ConcreteAggregate : public Aggregate {
public:
  ConcreteAggregate(int N) {
    for (int i = 0; i < N; ++i) {
      objs_.emplace_back(i);
    }
  }
  ~ConcreteAggregate() {}

  Iterator* createIterator();

  int getItem(int idx) { return objs_.at(idx); }

  unsigned int getSize() { return objs_.size(); }

  void addItem(int obj) { objs_.emplace_back(obj); }

private:
  std::vector<int> objs_;
};

class Iterator {
public:
  virtual ~Iterator() {}

  virtual void first() = 0;
  virtual void next() = 0;
  virtual bool isDone() = 0;
  virtual int currentItem() = 0;
};

class ConcreteIterator : public Iterator {
public:
  ConcreteIterator(ConcreteAggregate *ag)
  : cag_(ag), index_(0) {}

  void first() {
    index_ = 0;
  }

  void next() {
    ++index_;
  }

  bool isDone() {
    return index_ >= cag_->getSize();
  }

  int currentItem() {
    return cag_->getItem(index_);
  }
private:
  ConcreteAggregate *cag_;
  int index_;
};

Iterator * ConcreteAggregate::createIterator() {
  return new ConcreteIterator(this);
}

int main() {
  ConcreteAggregate *cag = new ConcreteAggregate(10);
  cag->addItem(99);

  Iterator* it = cag->createIterator();
  for ( ; !it->isDone(); it->next()) {
    std::cout << "Item value: " << it->currentItem() << std::endl;
  }

}


