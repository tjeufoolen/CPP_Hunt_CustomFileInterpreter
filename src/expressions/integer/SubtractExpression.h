#ifndef CPPLS1_EINDOPDRACHT_SUBTRACTEXPRESSION_H
#define CPPLS1_EINDOPDRACHT_SUBTRACTEXPRESSION_H


#include <expressions/IExpression.h>

class SubtractExpression : public IExpression
{
    public:
        void Interpret(Context& context) override;
};


#endif //CPPLS1_EINDOPDRACHT_SUBTRACTEXPRESSION_H
