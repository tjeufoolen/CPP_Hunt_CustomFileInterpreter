#ifndef CPPLS1_EINDOPDRACHT_LENGTHEXPRESSION_H
#define CPPLS1_EINDOPDRACHT_LENGTHEXPRESSION_H


#include <expressions/IExpression.h>

class LengthExpression : public IExpression
{
    public:
        void Interpret(Context& context) override;
};


#endif //CPPLS1_EINDOPDRACHT_LENGTHEXPRESSION_H
