#ifndef CPPLS1_EINDOPDRACHT_GOTOIFLESSOREQUALEXPRESSION_H
#define CPPLS1_EINDOPDRACHT_GOTOIFLESSOREQUALEXPRESSION_H


#include <expressions/AbstractExpression.h>

class GotoIfLessOrEqualExpression : public AbstractExpression
{
    public:
        void Interpret(Context& context) override;
};


#endif //CPPLS1_EINDOPDRACHT_GOTOIFLESSOREQUALEXPRESSION_H
