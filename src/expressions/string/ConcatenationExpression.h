#ifndef CPPLS1_EINDOPDRACHT_CONCATENATIONEXPRESSION_H
#define CPPLS1_EINDOPDRACHT_CONCATENATIONEXPRESSION_H


#include <expressions/AbstractExpression.h>

class ConcatenationExpression : public AbstractExpression
{
    public:
        void Interpret(Context& context) override;
};


#endif //CPPLS1_EINDOPDRACHT_CONCATENATIONEXPRESSION_H
