#ifndef CPPLS1_EINDOPDRACHT_GOTOIFGREATEREXPRESSION_H
#define CPPLS1_EINDOPDRACHT_GOTOIFGREATEREXPRESSION_H


#include <expressions/AbstractExpression.h>

class GotoIfGreaterExpression : public AbstractExpression
{
    public:
        void Interpret(Context& context) override;
};


#endif //CPPLS1_EINDOPDRACHT_GOTOIFGREATEREXPRESSION_H
