#ifndef VARIABLE_H
#define VARIABLE_H

#include "term.h"
#include <string>
using std::string;

class Variable: public Term
{
public:
    Variable(string s):Term(s), _assignable(true){}
    virtual bool match(Term& term)
    {
        if(isAssignable())
        {
            setValue(term.value());
            disAssignable();
            return true;
        }
        else
        {
            return value() == term.value();
        }
    }

    void setValue(string s){_value = s;}
    bool isAssignable(){return _assignable;}
    void disAssignable(){_assignable = false;}

private:
    bool _assignable;
};

#endif