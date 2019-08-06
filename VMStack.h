#ifndef __VM_STACK__
#define __VM_STACK__

#include "Operand.Class.h"
#include "eOperandTypes.h"
#include "Exceptions.h"

#include <vector>
#include <regex>
#include <cstdint>

const int MAX = 10;

class vmstack
{
    std::vector<const IOperand *> _stk;
    void printChar(std::string const &) const;

public:
    vmstack() = default;
    void push(std::string *);
    void pop(void);
    void asset(std::string);
    void dump(void);
    void add(void);
    void sub(void);
    void mul(void);
    void div(void);
    void mod(void);
    void print(void);
    ~vmstack(void) {}
};
std::string getValue(std::string);
eOperandType getType(std::string);
void checkValue(eOperandType const&, std::string const &);

#endif /* VM_STACK */