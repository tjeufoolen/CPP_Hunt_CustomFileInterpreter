#ifndef CPPLS1_EINDOPDRACHT_GOTOIFNOTEQUALEXPRESSION_H
#define CPPLS1_EINDOPDRACHT_GOTOIFNOTEQUALEXPRESSION_H


#include <expressions/AbstractExpression.h>

class GotoIfNotEqualExpression : public AbstractExpression
{
    public:
        void Interpret(Context& context) override;
};


#endif //CPPLS1_EINDOPDRACHT_GOTOIFNOTEQUALEXPRESSION_H
