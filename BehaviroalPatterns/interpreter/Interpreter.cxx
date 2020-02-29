/*
 * C++ Design Patterns:
 * Author: Junzhuo Du [github.com/Junzhuodu]
 * 2020
 *
 */

#include <iostream>
#include <unordered_map>

/*
 * Interpreter example:
 * A->true, B->false, AB->false, C->true, AC->true
 */
class Context {
public:
    void set(char var, bool value) {
        maps.insert(std::make_pair(var, value));
    }

    char get(char var) {
        return maps[var];
    }
private:
    std::unordered_map<char, bool> maps;
};

class AbstractExpression {
public:
    virtual ~AbstractExpression() {}

    virtual bool interpret(Context* const context) = 0;
};

class TerminalExpression : public AbstractExpression {
public:
    TerminalExpression(char var) : var_(var) {}
    ~TerminalExpression() {}

    bool interpret(Context* const context) {
        return context->get(var_);
    }
private:
    char var_;
};

class NonTerminalExpression : public AbstractExpression {
public:
    NonTerminalExpression(AbstractExpression* f, AbstractExpression* s)
    : first(f), second(s) {}

    ~NonTerminalExpression() {
        if (first) delete first;
        if (second) delete second;
    }

    bool interpret(Context* const context) {
        return first->interpret(context) && second->interpret(context);
    }
private:
    AbstractExpression* first;
    AbstractExpression* second;
};

int main() {
    Context context;
    context.set('A', true);
    context.set('B', false);
    context.set('C', true);

    AbstractExpression* expressionA = new TerminalExpression('A');
    AbstractExpression* expressionB = new TerminalExpression('B');
    AbstractExpression* expressionC = new TerminalExpression('C');

    AbstractExpression* expressionAB = new NonTerminalExpression(expressionA, expressionB);
    AbstractExpression* expressionAC = new NonTerminalExpression(expressionA, expressionC);

    std::cout << "A -> " << expressionA->interpret(&context) << std::endl;
    std::cout << "B -> " << expressionB->interpret(&context) << std::endl;
    std::cout << "C -> " << expressionC->interpret(&context) << std::endl;

    std::cout << "AB -> " << expressionAB->interpret(&context) << std::endl;
    std::cout << "AC -> " << expressionAC->interpret(&context) << std::endl;
}