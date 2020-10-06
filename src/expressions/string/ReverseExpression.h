#ifndef CPPLS1_EINDOPDRACHT_REVERSEEXPRESSION_H
#define CPPLS1_EINDOPDRACHT_REVERSEEXPRESSION_H


#include <expressions/AbstractExpression.h>

class ReverseExpression : public AbstractExpression
{
    public:
        void Interpret(Context& context) override;
};


#endif //CPPLS1_EINDOPDRACHT_REVERSEEXPRESSION_H
