#ifndef CPPLS1_EINDOPDRACHT_GOTOIFNOTEQUALEXPRESSION_H
#define CPPLS1_EINDOPDRACHT_GOTOIFNOTEQUALEXPRESSION_H


#include <expressions/IExpression.h>

class GotoIfNotEqualExpression : public IExpression
{
    private:
        int &rule;
    public:
        GotoIfNotEqualExpression() = delete;
        GotoIfNotEqualExpression(int &currentRule);
        void Interpret(Context& context) override;
};


#endif //CPPLS1_EINDOPDRACHT_GOTOIFNOTEQUALEXPRESSION_H
