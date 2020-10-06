#ifndef CPPLS1_EINDOPDRACHT_DECREMENTEXPRESSION_H
#define CPPLS1_EINDOPDRACHT_DECREMENTEXPRESSION_H


#include <expressions/IExpression.h>

class DecrementExpression : public IExpression
{
    public:
        void Interpret(Context& context) override;
};


#endif //CPPLS1_EINDOPDRACHT_DECREMENTEXPRESSION_H
