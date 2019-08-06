#include "VMStack.h"

#include "OperandCreator.h"

void vmstack::pop(void)
{
    try
    {
        if (_stk.size() < 1) throw EmptyStackException();
        _stk.pop_back();
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
}

void vmstack::add(void)
{
    try
    {
        if (_stk.size() < 2) throw FewElemsOnStackException();
        const IOperand *scnd = _stk.back();
        _stk.pop_back();
        const IOperand *fst = _stk.back();
        _stk.pop_back();
        _stk.push_back(*fst + *scnd);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
}

void vmstack::sub(void)
{
    try
    {
        if (_stk.size() < 2) throw FewElemsOnStackException();
        const IOperand *scnd = _stk.back();
        _stk.pop_back();
        const IOperand *fst = _stk.back();
        _stk.pop_back();
        _stk.push_back(*fst - *scnd);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
}

void vmstack::mul(void)
{
    try
    {
        if (_stk.size() < 2) throw FewElemsOnStackException();
        const IOperand *scnd = _stk.back();
        _stk.pop_back();
        const IOperand *fst = _stk.back();
        _stk.pop_back();
        _stk.push_back((*fst) * (*scnd));
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
}

void vmstack::div(void)
{
    try
    {
        if (_stk.size() < 2) throw FewElemsOnStackException();
        const IOperand *scnd;
        _stk.back()->toString() == "0" ? throw DivisionByZeroException() : scnd = _stk.back();
        _stk.pop_back();
        const IOperand *fst = _stk.back();
        _stk.pop_back();
        _stk.push_back((*fst) / (*scnd));
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
}

void vmstack::mod(void)
{
    try
    {
        if (_stk.size() < 2) throw FewElemsOnStackException();
        const IOperand *scnd = _stk.back();
        _stk.pop_back();
        const IOperand *fst = _stk.back();
        _stk.pop_back();
        _stk.push_back((*fst) % (*scnd));
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
}

void vmstack::asset(std::string val)
{
    
    try
    {
        std::string value;
        eOperandType type;
        const IOperand *top = nullptr;

        if ( _stk.size() < 1 ) throw EmptyStackException();

        top = _stk.back();

        if ( std::regex_search(val, std::regex("int\\d+")) )
        {
            if (val.substr(7, 4) == "int8")
            {
                type = getType( val.substr(7, 4));
                value = getValue(val.substr(12));
                if ((type != top->getType()) || ( value != top->toString() )) throw AssertionException();
            }
            else if (val.substr(7, 5) == "int16" || val.substr(7, 5) == "int32" )
            {
                type = getType( val.substr(7, 5));
                value = getValue(val.substr(13));
                if ((type != top->getType()) || ( value != top->toString() )) throw AssertionException();
            }
            else throw UnknownInstructionException();
        }
        else if (std::regex_search(val, std::regex("float")))
        {
            type = getType( val.substr(7, 5 ));
            value = getValue(val.substr(13));
            if ((type != top->getType()) || ( value != top->toString() )) throw AssertionException();
        }
        else if (std::regex_search(val, std::regex("double")))
        {
            type = getType( val.substr(7, 6));
            value = getValue(val.substr(14));
            if ((type != top->getType()) || ( value != top->toString() )) throw AssertionException();
        }
        else throw UnknownInstructionException();
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
}

void vmstack::push(std::string *tmp)
{
    std::string type;
    std::string value;
    OperandCreator *builder = nullptr;

    //hook this with the creator class
    if (std::regex_search(*tmp, std::regex("int\\d+")))
    {
        if (tmp->substr(5, 4) == "int8")
        {
            type = tmp->substr(5, 4);
            value = getValue(tmp->substr(10));
            checkValue( getType(type), value );
            _stk.push_back(builder->createOperand(getType(type), value));
        }
        else if( tmp->substr( 5, 5 ) == "int16" || tmp->substr(5, 5) == "int32")
        {
            type = tmp->substr(5, 5);
            value = getValue(tmp->substr(11));
            checkValue( getType(type), value );
            _stk.push_back(builder->createOperand(getType(type), value));
        }
        else throw UnknownInstructionException();
    }
    else if (std::regex_search(*tmp, std::regex("float")))
    {
        type = tmp->substr(5, 5);
        value = getValue(tmp->substr(11));
        checkValue( getType(type), value );
        _stk.push_back(builder->createOperand(getType(type), value));
    }
    else if (std::regex_search(*tmp, std::regex("double")))
    {
        type = tmp->substr(5, 6);
        value = getValue(tmp->substr(12));
        checkValue( getType(type), value );
        _stk.push_back(builder->createOperand(getType(type), value));
    }
    else throw UnknownInstructionException();
}

void vmstack::dump(void)
{
    if (_stk.size())
    {
        for (auto rit = _stk.crbegin(); rit != _stk.crend(); ++rit)
            std::cout  << (*rit)->toString() << std::endl;
    }
}

void vmstack::printChar( std::string const& value ) const
{
    char c = (char)atoi(value.c_str());
    std::cout << c << std::endl;
}

void vmstack::print(void)
{
    try
    {
        if ( _stk.size() < 1 ) throw EmptyStackException();
        const IOperand *top = _stk.back();
        top->getType() == eOperandType::INT8 ? printChar( top->toString() ) : throw printAssertFailed();
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
}

