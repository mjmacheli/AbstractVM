#ifndef __OPERANDCREATOR__
#define __OPERANDCREATOR__
#include <memory>

#include "IOperand.Class.h"
#include "Operand.Class.h"
#include "eOperandTypes.h"

class OperandCreator;

typedef IOperand const *(OperandCreator::*arr_name)(std::string const &value) const;

class OperandCreator
{

    static arr_name _ary[];

    IOperand const *createInt8(std::string const &value) const;
    IOperand const *createInt16(std::string const &value) const;
    IOperand const *createInt32(std::string const &value) const;
    IOperand const *createFloat(std::string const &value) const;
    IOperand const *createDouble(std::string const &value) const;

public:
    IOperand const *createOperand(eOperandType type, std::string const &value) const;
    OperandCreator(void);
    ~OperandCreator(void){};
};

#endif /* CREATOROPERATOR */