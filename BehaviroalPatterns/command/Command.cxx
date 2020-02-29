/*
 * C++ Design Patterns:
 * Author: Junzhuo Du [github.com/Junzhuodu]
 * 2020
 *
 */

#include <iostream>

class Receiver {
public:
    void action() {
        std::cout << "Recevier: execute action" << std::endl;
    }
};

class Command {
public:
    virtual ~Command() {}
    
    virtual void execute() = 0;
};

class ConcreteCommand : public Command {
public:
    ConcreteCommand(Receiver *r) : receiver_(r) {};
    ~ConcreteCommand() {
        if (!receiver_) {
            delete receiver_;
        }
    }
    
    void execute() {
        receiver_->action();
    }
private:
    Receiver* receiver_;
};

class Invoker {
public:
    void setCommand(Command* c) {
        command_ = c;
    }
    
    void executeCommand() {
        if (command_) command_->execute();
    }

private:
    Command* command_;
};

int main() {
    Receiver* receiver = new Receiver();
    Command *command = new ConcreteCommand(receiver);
    
    Invoker invoker;
    invoker.setCommand(command);
    invoker.executeCommand();
}