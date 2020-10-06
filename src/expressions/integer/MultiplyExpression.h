#ifndef CPPLS1_EINDOPDRACHT_MULTIPLYEXPRESSION_H
#define CPPLS1_EINDOPDRACHT_MULTIPLYEXPRESSION_H


#include <expressions/IExpression.h>

class MultiplyExpression : public IExpression
{
    public:
        void Interpret(Context& context) override;
};


#endif //CPPLS1_EINDOPDRACHT_MULTIPLYEXPRESSION_H
