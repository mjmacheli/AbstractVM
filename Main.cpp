#include <iostream>
#include <regex>
#include <algorithm>
#include <fstream>

#include "OperandCreator.h"
#include "VMStack.h"

//Parse a string vector and exe cmds
void parseInput(std::vector<std::string> *v)
{
    vmstack vm;
    //Chop off after exit
    try
    {
        if ( !std::any_of( v->begin(), v->end(), [](std::string s){ return( regex_search(s, std::regex("exit"))); } ))
            throw NoExitException();

        for (auto &in : *v)
        {
            if (regex_search(in, std::regex("push\\s\\w+")))
            {
                vm.push(&in);
            }
            else if (regex_search(in, std::regex("pop")))
            {
                vm.pop();
            }
            else if (regex_search(in, std::regex("add")))
            {
                vm.add();
            }
            else if (regex_search(in, std::regex("sub")))
            {
                vm.sub();
            }
            else if (regex_search(in, std::regex("mod")))
            {
                vm.sub();
            }
            else if (regex_search(in, std::regex("mul")))
            {
                vm.mul();
            }
            else if ( regex_search(in, std::regex("assert\\s\\w+")) )
            {
                vm.asset(in);
            }
            else if(regex_search(in, std::regex("dump")))
            {
                vm.dump();
            }
            else if(regex_search(in, std::regex("div")))
            {
                vm.div();
            }
            else if(regex_search(in, std::regex("print")))
            {
                vm.print();
            }
            else if ( regex_search(in, std::regex("exit")) ) 
            {
                break ;
            }
            else if (regex_match( in , std::regex("[;]\\s?...+")))
            {
                continue;
            }
            else throw UnknownInstructionException();
        }
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    } 
}

int main(int argc, char** argv)
{
    std::string line;
    std::vector<std::string> v;

    if ( argc > 1 ) // file passed
    {
        try
        {
            std::ifstream file(argv[1]);
            if (file.is_open())
            {
                while (getline( file, line ))
                    v.push_back( line );
            }
            else throw CantOpenFileException();
            file.close();
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
        }
    }
    else
    {
        while ( getline(std::cin,  line ))
        {
            if (regex_search( line, std::regex(";;")))
                break ;
            v.push_back( line );
        }
    }
    // send vector v to get cmd and values
    parseInput(&v);
    return (0);
}