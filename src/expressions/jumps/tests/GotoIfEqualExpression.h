#ifndef CPPLS1_EINDOPDRACHT_GOTOIFEQUALEXPRESSION_H
#define CPPLS1_EINDOPDRACHT_GOTOIFEQUALEXPRESSION_H


#include <expressions/IExpression.h>

class GotoIfEqualExpression : public IExpression
{
    private:
        int* rule;
    public:
        GotoIfEqualExpression(int* currentRule);
        void Interpret(Context& context) override;
};


#endif //CPPLS1_EINDOPDRACHT_GOTOIFEQUALEXPRESSION_H
