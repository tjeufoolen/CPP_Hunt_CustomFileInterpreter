#ifndef CPPLS1_EINDOPDRACHT_GOTOIFLESSOREQUALEXPRESSION_H
#define CPPLS1_EINDOPDRACHT_GOTOIFLESSOREQUALEXPRESSION_H


#include <expressions/IExpression.h>

class GotoIfLessOrEqualExpression : public IExpression
{
    private:
        int &rule;
    public:
        GotoIfLessOrEqualExpression(int &currentRule);
        void Interpret(Context& context) override;
};


#endif //CPPLS1_EINDOPDRACHT_GOTOIFLESSOREQUALEXPRESSION_H
