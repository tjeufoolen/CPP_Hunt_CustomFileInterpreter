#ifndef CPPLS1_EINDOPDRACHT_GOTOIFLESSEXPRESSION_H
#define CPPLS1_EINDOPDRACHT_GOTOIFLESSEXPRESSION_H


#include <expressions/IExpression.h>

class GotoIfLessExpression : public IExpression
{
    private:
        int &rule;
    public:
        GotoIfLessExpression() = delete;
        GotoIfLessExpression(int &currentRule);
        void Interpret(Context& context) override;
};


#endif //CPPLS1_EINDOPDRACHT_GOTOIFLESSEXPRESSION_H
