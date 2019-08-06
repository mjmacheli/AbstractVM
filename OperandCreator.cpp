#include "OperandCreator.h"

#include "Operand.Class.h"
#include "OperandCreator.h"
#include "eOperandTypes.h"

#include "IOperand.Class.h"


class OperandCreator;

typedef IOperand const *(OperandCreator::*arr_name)(std::string const &value) const;

arr_name OperandCreator::_ary[] = {
    &OperandCreator::createInt8,
    &OperandCreator::createInt16,
    &OperandCreator::createInt32,
    &OperandCreator::createFloat,
    &OperandCreator::createDouble
    };

OperandCreator::OperandCreator(void) { }

IOperand const *OperandCreator::createInt8(std::string const &value) const
{
    OperandType<int8_t> tmp(value);
    tmp.setType(eOperandType::INT8);

    return (new OperandType<int8_t>(tmp));
}

IOperand const *OperandCreator::createInt16(std::string const &value) const
{
    OperandType<int16_t> tmp(value);
    tmp.setType(eOperandType::INT16);

    return (new OperandType<int16_t>(tmp));
}

IOperand const *OperandCreator::createInt32(std::string const &value) const
{
    OperandType<int32_t> tmp(value);
    tmp.setType(eOperandType::INT32);

    return (new OperandType<int32_t>(tmp));
}

IOperand const *OperandCreator::createFloat(std::string const &value) const
{
    OperandType<float> tmp(value);
    tmp.setType(eOperandType::FLOAT);

    return (new OperandType<float>(tmp));
}

IOperand const *OperandCreator::createDouble(std::string const &value) const
{
    OperandType<double> tmp(value);
    tmp.setType(eOperandType::DOUBLE);

    return (new OperandType<double>(tmp));
}

IOperand const *OperandCreator::createOperand(eOperandType type, std::string const &value) const
{
    arr_name op = (_ary[(int)type]);
    IOperand const *ret = ((this)->*(op))(value);
    return (ret);
}
