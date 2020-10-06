#ifndef CPPLS1_EINDOPDRACHT_REVERSEEXPRESSION_H
#define CPPLS1_EINDOPDRACHT_REVERSEEXPRESSION_H


#include <expressions/IExpression.h>

class ReverseExpression : public IExpression
{
    public:
        void Interpret(Context& context) override;
};


#endif //CPPLS1_EINDOPDRACHT_REVERSEEXPRESSION_H
