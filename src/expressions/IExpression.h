#ifndef CPPLS1_EINDOPDRACHT_IEXPRESSION_H
#define CPPLS1_EINDOPDRACHT_IEXPRESSION_H


#include "Context.h"

class IExpression
{
    public:
        virtual void Interpret(Context& context) = 0;
};


#endif //CPPLS1_EINDOPDRACHT_IEXPRESSION_H
