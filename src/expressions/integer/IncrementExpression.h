#ifndef CPPLS1_EINDOPDRACHT_INCREMENTEXPRESSION_H
#define CPPLS1_EINDOPDRACHT_INCREMENTEXPRESSION_H


#include <expressions/AbstractExpression.h>

class IncrementExpression : public AbstractExpression
{
    public:
        void Interpret(Context& context) override;
};


#endif //CPPLS1_EINDOPDRACHT_INCREMENTEXPRESSION_H
