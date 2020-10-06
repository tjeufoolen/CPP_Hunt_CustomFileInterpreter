#ifndef CPPLS1_EINDOPDRACHT_DECREMENTEXPRESSION_H
#define CPPLS1_EINDOPDRACHT_DECREMENTEXPRESSION_H


#include <expressions/AbstractExpression.h>

class DecrementExpression : public AbstractExpression
{
    public:
        void Interpret(Context& context) override;
};


#endif //CPPLS1_EINDOPDRACHT_DECREMENTEXPRESSION_H
