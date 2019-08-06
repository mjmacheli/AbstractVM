#ifndef __EXCEPTIONS__
#define __EXCEPTIONS__

#include <exception>


//Parent Exception class
class AVMException : public std::exception
{
    const char *_ex;

protected:
    explicit AVMException(const char *) throw();
    virtual ~AVMException(void) throw();

public:
    virtual const char *what() const throw();
};

//Empty stack elements
class EmptyStackException : public AVMException
{
public:
    EmptyStackException(void) throw();
    virtual ~EmptyStackException(void) throw();
};

//Few elements on Stack
class FewElemsOnStackException : public AVMException
{
public:
    FewElemsOnStackException(void) throw();
    virtual ~FewElemsOnStackException(void) throw();
};

//Overflow
class OverflowException : public AVMException
{
public:
    OverflowException(void) throw();
    virtual ~OverflowException(void) throw();
};

//Underflow
class UnderflowException : public AVMException
{
public:
    UnderflowException(void) throw();
    virtual ~UnderflowException(void) throw();
};

//Division/Modulo by Zero
class OpNotPermittedException : public AVMException
{
public:
    OpNotPermittedException(void) throw();
    virtual ~OpNotPermittedException(void) throw();
};

class UnknownInstructionException : public AVMException
{
public:
    UnknownInstructionException(void) throw();
    virtual ~UnknownInstructionException(void) throw();
};

class AssertionException : public AVMException
{
public:
    AssertionException(void) throw();
    virtual ~AssertionException(void) throw();
};

class NoExitException : public AVMException
{
public:
    NoExitException(void) throw();
    virtual ~NoExitException(void) throw();
};

class printAssertFailed : public AVMException
{
public:
    printAssertFailed(void) throw();
    virtual ~printAssertFailed(void) throw();
};

class DivisionByZeroException : public AVMException
{
public:
    DivisionByZeroException(void) throw();
    virtual ~DivisionByZeroException(void) throw();
};

class CantOpenFileException : public AVMException
{
public:
    CantOpenFileException(void) throw();
    virtual ~CantOpenFileException(void) throw();
};

class SyntaxException : public AVMException
{
public:
    SyntaxException(void) throw();
    virtual ~SyntaxException(void) throw();
};

#endif /* EXCEPTION */