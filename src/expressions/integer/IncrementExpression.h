#ifndef CPPLS1_EINDOPDRACHT_INCREMENTEXPRESSION_H
#define CPPLS1_EINDOPDRACHT_INCREMENTEXPRESSION_H


#include <expressions/IExpression.h>

class IncrementExpression : public IExpression
{
    public:
        void Interpret(Context& context) override;
};


#endif //CPPLS1_EINDOPDRACHT_INCREMENTEXPRESSION_H
