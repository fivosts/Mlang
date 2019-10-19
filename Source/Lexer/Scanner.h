#ifndef SCANNER_H
#define SCANNER_H

#include <fstream>
#include <iostream>
#include <functional>

class Scanner : public std::ifstream
{
public:

    // struct Position{
    //     int line;
    //     int column;
    // };

    using std::pair<int, int> = Position;

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

    virtual char nextChar()
    {
        try                                     {   return updatePosition(this->get()); }
        catch(const std::ifstream::failure &e)  {   return EOF;                         }
    }

    virtual char peekChar()
    {
        try                                     {       return this->peek();    }
        catch(const std::ifstream::failure &e)  {       return EOF;             }
    }

    virtual const Position &getCurrentPosition() const
    {
        return pos;
    }

private:
    virtual char updatePosition(char c)
    {
        if (c == '\n')
        {
            ++pos.first;     pos.second = 1;
        }
        else
            ++pos.second;
        return c;
    }

// private:
public:
    Position pos{0, 0};

};

#endif