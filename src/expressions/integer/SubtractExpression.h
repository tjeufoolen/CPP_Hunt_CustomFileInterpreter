#ifndef CPPLS1_EINDOPDRACHT_SUBTRACTEXPRESSION_H
#define CPPLS1_EINDOPDRACHT_SUBTRACTEXPRESSION_H


#include <expressions/AbstractExpression.h>

class SubtractExpression : public AbstractExpression
{
    public:
        void Interpret(Context& context) override;
};


#endif //CPPLS1_EINDOPDRACHT_SUBTRACTEXPRESSION_H
