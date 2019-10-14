#ifndef SCANNER_H
#define SCANNER_H

#include <fstream>
#include <iostream>
#include <functional>

class Scanner : public std::ifstream
{
public:

    struct Position{
        int line;
        int column;
    };

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

    virtual char getChar(){
        peekBuffer = -1;
        try                                     {   return updatePosition(this->get()); }
        catch(const std::ifstream::failure &e)  {   return EOF;                         }
    }

    virtual char peekChar(){
        try                                     {       return this->peek();    }
        catch(const std::ifstream::failure &e)  {       return EOF;             }
    }

    virtual const Position &getCurrentPosition(){
        return pos;
    }

private:
    virtual char updatePosition(char c){

        if (c == '\n')
        {
            ++pos.line;     pos.column = 1;
        }
        else
            ++pos.column;
        return c;
    }

private:
    Position pos{0, 0};

};

#endif