#ifndef SCANNER_H
#define SCANNER_H

#include <fstream>
#include <iostream>

class Scanner : public std::ifstream
{
public:
    Scanner() = delete;
    Scanner(std::string filePath)
    {
        this->exceptions(std::ifstream::failbit);
        
        try
        {this->open(filePath);}
        
        catch (const std::ifstream::failure &e)
        {/*TODO Send Error report*/}

        return;
    }
    ~Scanner()
    {
        this->close();
    }

    virtual int getChar(){
        try                                     {       return this->get(); }
        catch(const std::ifstream::failure &e)  {       return EOF;         }
    }

};

#endif