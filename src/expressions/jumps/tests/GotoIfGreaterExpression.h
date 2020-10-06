#ifndef CPPLS1_EINDOPDRACHT_GOTOIFGREATEREXPRESSION_H
#define CPPLS1_EINDOPDRACHT_GOTOIFGREATEREXPRESSION_H


#include <expressions/AbstractExpression.h>

class GotoIfGreaterExpression : public AbstractExpression
{
    private:
        int* rule;
    public:
        GotoIfGreaterExpression(int* currentRule);
        void Interpret(Context& context) override;
};


#endif //CPPLS1_EINDOPDRACHT_GOTOIFGREATEREXPRESSION_H
