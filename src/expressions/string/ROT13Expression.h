#ifndef CPPLS1_EINDOPDRACHT_ROT13EXPRESSION_H
#define CPPLS1_EINDOPDRACHT_ROT13EXPRESSION_H


#include <expressions/AbstractExpression.h>

class ROT13Expression : public AbstractExpression
{
    public:
        void Interpret(Context& context) override;
};


#endif //CPPLS1_EINDOPDRACHT_ROT13EXPRESSION_H
