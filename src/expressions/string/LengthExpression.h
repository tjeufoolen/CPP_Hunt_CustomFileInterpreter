#ifndef CPPLS1_EINDOPDRACHT_LENGTHEXPRESSION_H
#define CPPLS1_EINDOPDRACHT_LENGTHEXPRESSION_H


#include <expressions/AbstractExpression.h>

class LengthExpression : public AbstractExpression
{
    public:
        void Interpret(Context& context) override;
};


#endif //CPPLS1_EINDOPDRACHT_LENGTHEXPRESSION_H
