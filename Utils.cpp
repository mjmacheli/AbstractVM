#include "VMStack.h"

std::string getValue( std::string str )
{
    str = str.substr(0, str.size() - 1 );
    return (str);
}

eOperandType getType( std::string const typ )
{
    if ( typ == "int8" )
        return eOperandType::INT8;
    else if ( typ == "int16" )
        return eOperandType::INT16;
    else if ( typ == "int32" )
        return eOperandType::INT32;
    else if ( typ == "float" )
        return eOperandType::FLOAT;
    return eOperandType::DOUBLE;
}

bool precheck( std::string str )
{
    auto tmp = atoll(str.c_str());
    return ( (std::to_string( tmp ) == str ) ? true : false );
}

void checkValue(eOperandType const& type, std::string const & val )
{
    try
    {
        switch ( type )
        {
            case eOperandType::INT8 :
            {
                if ( !precheck( val )) throw SyntaxException(); //Validate Value
                if (std::atoll(val.c_str()) < INT8_MIN ) throw UnderflowException();
                if (std::atoll(val.c_str()) > INT8_MAX ) throw OverflowException();
                break ;
            }
            case eOperandType::INT16 :
            {
                if ( !precheck( val )) throw SyntaxException(); //Validate Value
                if (std::atoll(val.c_str()) < INT16_MIN ) throw UnderflowException();
                if (std::atoll(val.c_str()) > INT16_MAX ) throw OverflowException();
                break ;
            }
            case eOperandType::INT32 :
            {
                if ( !precheck( val )) throw SyntaxException(); //Validate Value
                if (std::atoll(val.c_str()) < INT32_MIN ) throw UnderflowException();
                if (std::atoll(val.c_str()) > INT32_MAX ) throw OverflowException();
                break ;
            }
            case eOperandType::DOUBLE :
            {
                double tmp = std::stod(val.c_str());
                if (std::to_string(tmp) == val ) throw UnderflowException();
                break ;
            }
            case eOperandType::FLOAT :
            {
                float tmp = std::atof(val.c_str());
                if (std::to_string(tmp) == val ) throw UnderflowException();
                break ;
            }
        }
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
}