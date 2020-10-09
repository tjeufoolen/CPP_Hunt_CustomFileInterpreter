#ifndef CPPLS1_EINDOPDRACHT_GOTOIFGREATEREXPRESSION_H
#define CPPLS1_EINDOPDRACHT_GOTOIFGREATEREXPRESSION_H


#include <expressions/IExpression.h>

class GotoIfGreaterExpression : public IExpression
{
    private:
        int &rule;
    public:
        GotoIfGreaterExpression() = delete;
        GotoIfGreaterExpression(int &currentRule);
        void Interpret(Context& context) override;
};


#endif //CPPLS1_EINDOPDRACHT_GOTOIFGREATEREXPRESSION_H
