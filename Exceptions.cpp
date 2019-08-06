#include "Exceptions.h"

AVMException::AVMException( const char* ex ) throw(): _ex( ex ) {}

const char*   AVMException::what() const throw() { return ( this->_ex ); }

AVMException::~AVMException( void ) throw() {}

EmptyStackException::EmptyStackException() throw () 
    : AVMException( "Can not perform the action on an Empty stack!" ) 
{}

EmptyStackException::~EmptyStackException( void ) throw() {}

FewElemsOnStackException::FewElemsOnStackException() throw () 
    : AVMException( "Too few elements on stack !" ) 
{}

FewElemsOnStackException::~FewElemsOnStackException( void ) throw() {}

OverflowException::OverflowException( void ) throw ()
    : AVMException( "Error: Value Overflow! " )
{}

OverflowException::~OverflowException( void ) throw() {}

UnderflowException::UnderflowException( void ) throw ()
    : AVMException( "Error: Value Underflow! " )
{}

UnderflowException::~UnderflowException( void ) throw() {}

OpNotPermittedException::OpNotPermittedException( void ) throw ()
    : AVMException( "Operation Not premitted on the values ! " )
{}

OpNotPermittedException::~OpNotPermittedException( void ) throw() {}

UnknownInstructionException::UnknownInstructionException( void ) throw ()
    : AVMException( "Unknown Instruction! " )
{}

UnknownInstructionException::~UnknownInstructionException( void ) throw() {}

AssertionException::AssertionException( void ) throw ()
    : AVMException( "Assertion Error ! " )
{}

AssertionException::~AssertionException( void ) throw() {}

NoExitException::NoExitException( void ) throw ()
    : AVMException( "No Exit Command ! " )
{}

NoExitException::~NoExitException( void ) throw() {}

printAssertFailed::printAssertFailed( void ) throw ()
    : AVMException( "Print Assertion Error ! " )
{}

printAssertFailed::~printAssertFailed( void ) throw() {}

DivisionByZeroException::DivisionByZeroException( void ) throw ()
    : AVMException( "Error: Cannot divide by 0! " )
{}

DivisionByZeroException::~DivisionByZeroException( void ) throw() {}

CantOpenFileException::CantOpenFileException( void ) throw ()
    : AVMException( "Error: Cannot Open File! " )
{}

CantOpenFileException::~CantOpenFileException( void ) throw() {}

SyntaxException::SyntaxException( void ) throw ()
    : AVMException( "Error: Syntax Bro ! " )
{}

SyntaxException::~SyntaxException( void ) throw() {}