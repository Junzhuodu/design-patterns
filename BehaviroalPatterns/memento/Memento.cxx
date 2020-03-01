/*
 * C++ Design Patterns:
 * Author: Junzhuo Du [github.com/Junzhuodu]
 * 2020
 *
 */

#include <iostream>
#include <vector>

class Memento {
private:
    friend class Originator;

    Memento(int s) : state_(s) {}

    void setState(int s) {
        state_ = s;
    }

    int getState() {
        return state_;
    }
private:
    int state_;
};

class Originator {
public:
    void setState(int s) {
        state_ = s;
    }

    int getState() {
        return state_;
    }

    void setMemento(Memento* const m) {
        state_ = m->getState();
    }

    Memento* createMemento() {
        return new Memento(state_);
    }

    int getMementoState(Memento* const m) {
        return m->getState();
    }

private:
    int state_;
};

class CareTaker {
public:
    CareTaker(Originator* const o) : originator_(o) {}

    ~CareTaker() {
        for (auto m : historySaved_) {
            if (m) delete m;
        }
        for (auto m : historyUndo_) {
            if (m) delete m;
        }
        historySaved_.clear();
        historyUndo_.clear();
    }

    void save() {
        std::cout << "Save state: " << originator_->getState() << std::endl;
        historySaved_.push_back(originator_->createMemento());
    }

    void printSavedStates() {
        std::cout << "Saved states:" << std::endl;
        if (historySaved_.empty()) {
            std::cout << "It's empty" << std::endl;
        }
        for (auto m : historySaved_) {
            std::cout << "state " << originator_->getMementoState(m) << std::endl;
        }
    }

    void undo() {
        if (historySaved_.empty()) {
            std::cout << "Unable to undo state." << std::endl;
            return;
        }
        Memento* m = historySaved_.back();
        originator_->setMemento(m);
        std::cout << "Undo state: " << originator_->getState() << std::endl;

        historySaved_.pop_back();
        historyUndo_.push_back(m);
    }

    void redo() {
        if (historyUndo_.empty()) {
            std::cout << "Unable to redo state." << std::endl;
            return;
        }
        Memento* m = historyUndo_.back();
        originator_->setMemento(m);
        std::cout << "Redo state: " << originator_->getState() << std::endl;

        historyUndo_.pop_back();
        historySaved_.push_back(m);
    }

private:
    Originator* originator_;
    std::vector<Memento*> historySaved_; // for undo
    std::vector<Memento*> historyUndo_; // for redo
};

int main() {
    Originator *originator = new Originator();
    CareTaker *careTaker = new CareTaker( originator);

    originator->setState(0);
    careTaker->save();
    originator->setState(1);
    careTaker->save();
    originator->setState(2);
    careTaker->save();

    careTaker->printSavedStates();

    careTaker->undo();
    careTaker->printSavedStates();

    careTaker->redo();
    careTaker->printSavedStates();

    careTaker->undo();
    careTaker->undo();
    careTaker->undo();
    careTaker->printSavedStates();
}
