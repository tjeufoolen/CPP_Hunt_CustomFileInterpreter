#ifndef CPPLS1_EINDOPDRACHT_DIVIDEEXPRESSION_H
#define CPPLS1_EINDOPDRACHT_DIVIDEEXPRESSION_H


#include <expressions/AbstractExpression.h>

class DivideExpression : public AbstractExpression
{
    public:
        void Interpret(Context& context) override;
};


#endif //CPPLS1_EINDOPDRACHT_DIVIDEEXPRESSION_H
