#ifndef CPPLS1_EINDOPDRACHT_GOTOIFGREATEROREQUALEXPRESSION_H
#define CPPLS1_EINDOPDRACHT_GOTOIFGREATEROREQUALEXPRESSION_H


#include <expressions/IExpression.h>

class GotoIfGreaterOrEqualExpression : public IExpression
{
    private:
        int &rule;
    public:
        GotoIfGreaterOrEqualExpression() = delete;
        GotoIfGreaterOrEqualExpression(int &currentRule);
        void Interpret(Context& context) override;
};


#endif //CPPLS1_EINDOPDRACHT_GOTOIFGREATEROREQUALEXPRESSION_H
