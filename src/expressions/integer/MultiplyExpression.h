#ifndef CPPLS1_EINDOPDRACHT_MULTIPLYEXPRESSION_H
#define CPPLS1_EINDOPDRACHT_MULTIPLYEXPRESSION_H


#include <expressions/AbstractExpression.h>

class MultiplyExpression : public AbstractExpression
{
    public:
        void Interpret(Context& context) override;
};


#endif //CPPLS1_EINDOPDRACHT_MULTIPLYEXPRESSION_H
