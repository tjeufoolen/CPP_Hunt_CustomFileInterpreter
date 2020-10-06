#ifndef CPPLS1_EINDOPDRACHT_GOTOIFGREATEROREQUALEXPRESSION_H
#define CPPLS1_EINDOPDRACHT_GOTOIFGREATEROREQUALEXPRESSION_H


#include <expressions/AbstractExpression.h>

class GotoIfGreaterOrEqualExpression : public AbstractExpression
{
    private:
        int* rule;
    public:
        GotoIfGreaterOrEqualExpression(int* currentRule);
        void Interpret(Context& context) override;
};


#endif //CPPLS1_EINDOPDRACHT_GOTOIFGREATEROREQUALEXPRESSION_H
