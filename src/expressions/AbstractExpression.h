#ifndef CPPLS1_EINDOPDRACHT_ABSTRACTEXPRESSION_H
#define CPPLS1_EINDOPDRACHT_ABSTRACTEXPRESSION_H


#include "Context.h"

class AbstractExpression
{
    public:
        virtual void Interpret(Context& context) = 0;
};


#endif //CPPLS1_EINDOPDRACHT_ABSTRACTEXPRESSION_H
