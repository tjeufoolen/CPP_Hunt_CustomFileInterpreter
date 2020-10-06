#ifndef CPPLS1_EINDOPDRACHT_GOTOIFEQUALEXPRESSION_H
#define CPPLS1_EINDOPDRACHT_GOTOIFEQUALEXPRESSION_H


#include <expressions/AbstractExpression.h>

class GotoIfEqualExpression : public AbstractExpression
{
    public:
        void Interpret(Context& context) override;
};


#endif //CPPLS1_EINDOPDRACHT_GOTOIFEQUALEXPRESSION_H
