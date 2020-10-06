#ifndef CPPLS1_EINDOPDRACHT_ROT13EXPRESSION_H
#define CPPLS1_EINDOPDRACHT_ROT13EXPRESSION_H


#include <expressions/IExpression.h>

class ROT13Expression : public IExpression
{
    public:
        void Interpret(Context& context) override;
};


#endif //CPPLS1_EINDOPDRACHT_ROT13EXPRESSION_H
