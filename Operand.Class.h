#ifndef __OPERANDTYPE_CLASS__
#define __OPERANDTYPE_CLASS__

#include <iostream>
#include <cstdint>
#include <sstream>

#include "IOperand.Class.h"
#include "eOperandTypes.h"

template <typename T>
class OperandType : public IOperand
{
    std::string _value;
    eOperandType _type;

    OperandType<T>(void);

public:
    OperandType<T>(std::string const &value, eOperandType typ) : _value(value), _type(typ) {}
    OperandType<T>(std::string const &value) : _value(value) {}
    OperandType<T>(const OperandType<T> &src) : _value(src._value), _type(src.getType()) {} //copy constructor
    virtual eOperandType getType(void) const { return (this->_type); }
    virtual int getPrecision(void) const { return (static_cast<int>(this->_type)); }
    void setType(eOperandType type) { this->_type = type; }

    virtual IOperand const *operator+(IOperand const &rhs) const
    {
        
        switch( eOperandType tp = ( this->getPrecision() < rhs.getPrecision())? rhs.getType() : _type )
        {
            case eOperandType::FLOAT :
            {
                double sum = std::stof(this->_value) + std::stof(rhs.toString());
                OperandType<float> ret(std::to_string(sum));
                ret.setType(eOperandType::FLOAT);
                return (new OperandType<float>(ret));
            }
            case eOperandType::DOUBLE :
            {
                float sum = std::stod(this->_value) + std::stod(rhs.toString());
                OperandType<double> ret(std::to_string(sum));
                ret.setType(eOperandType::DOUBLE);
                return (new OperandType<double>(ret));
            }
            default :
            {
                auto sum = std::stol(this->_value) + std::stol(rhs.toString());
                OperandType<int32_t> ret(std::to_string(sum));
                ret.setType(eOperandType::INT32);
                return (new OperandType<int32_t>(ret));
            }
        }
        
    }

    virtual IOperand const *operator-(IOperand const &rhs) const
    {
        switch( eOperandType tp = ( this->getPrecision() < rhs.getPrecision())? rhs.getType() : _type )
        {
            case eOperandType::FLOAT :
            {
                auto diff = std::stof(this->_value) - std::stof(rhs.toString());
                OperandType<float> ret(std::to_string(diff));
                ret.setType(eOperandType::FLOAT);
                return (new OperandType<float>(ret));
            }
            case eOperandType::DOUBLE :
            {
                auto diff = std::stod(this->_value) - std::stod(rhs.toString());
                OperandType<double> ret(std::to_string(diff));
                ret.setType(eOperandType::DOUBLE);
                return (new OperandType<double>(ret));
            }
            default:
            {
                auto diff = std::stol(this->_value) - std::stol(rhs.toString());
                OperandType<int32_t> ret(std::to_string(diff));
                ret.setType(eOperandType::INT32);
                return (new OperandType<int32_t>(ret));
            }
        }
    }

    virtual IOperand const *operator*(IOperand const &rhs) const
    {
       switch( eOperandType tp = ( this->getPrecision() < rhs.getPrecision())? rhs.getType() : _type )
        {
            case eOperandType::FLOAT :
            {
                auto diff = std::stof(this->_value) * std::stof(rhs.toString());
                OperandType<float> ret(std::to_string(diff));
                ret.setType(eOperandType::FLOAT);
                return (new OperandType<float>(ret));
            }
            case eOperandType::DOUBLE :
            {
                auto diff = std::stod(this->_value) * std::stod(rhs.toString());
                OperandType<double> ret(std::to_string(diff));
                ret.setType(eOperandType::DOUBLE);
                return (new OperandType<double>(ret));
            }
            default :
            {
                auto diff = std::stol(this->_value) * std::stol(rhs.toString());
                OperandType<int32_t> ret(std::to_string(diff));
                ret.setType(eOperandType::INT32);
                return (new OperandType<int32_t>(ret));
            }
        }
    }

    virtual IOperand const *operator/(IOperand const &rhs) const
    {
        switch( eOperandType tp = ( this->getPrecision() < rhs.getPrecision())? rhs.getType() : _type )
        {
            case eOperandType::FLOAT :
            {
                auto diff = std::stof(this->_value) / std::stof(rhs.toString());
                OperandType<float> ret(std::to_string(diff));
                ret.setType(eOperandType::FLOAT);
                return (new OperandType<float>(ret));
            }
            case eOperandType::DOUBLE :
            {
                auto diff = std::stod(this->_value) / std::stod(rhs.toString());
                OperandType<double> ret(std::to_string(diff));
                ret.setType(eOperandType::DOUBLE);
                return (new OperandType<double>(ret));
            }
            default:
            {
                auto diff = std::stol(this->_value) / std::stol(rhs.toString());
                OperandType<int32_t> ret(std::to_string(diff));
                ret.setType(eOperandType::INT32);
                return (new OperandType<int32_t>(ret));
            }
        }
    }

    virtual IOperand const *operator%(IOperand const &rhs) const
    {
        auto sum = std::stoi(this->_value) % std::stoi(rhs.toString());
        OperandType<double> ret(std::to_string(sum));
        ret.setType(eOperandType::DOUBLE);
        return (new OperandType<double>(ret));
    }

    virtual IOperand &operator=(IOperand const &rhs)
    {

        this->_type = rhs.getType();
        this->_value = rhs.toString();
        return (*this);
    }

    virtual std::string const &toString(void) const { return (this->_value); }
    virtual ~OperandType<T>(void) {}
};

#endif /* __OPERANDTYPE_CLASS__ */