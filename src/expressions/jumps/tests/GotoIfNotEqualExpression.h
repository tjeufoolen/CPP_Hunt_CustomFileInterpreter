#ifndef CPPLS1_EINDOPDRACHT_GOTOIFNOTEQUALEXPRESSION_H
#define CPPLS1_EINDOPDRACHT_GOTOIFNOTEQUALEXPRESSION_H


#include <expressions/AbstractExpression.h>

class GotoIfNotEqualExpression : public AbstractExpression
{
    private:
        int* rule;
    public:
        GotoIfNotEqualExpression(int* currentRule);
        void Interpret(Context& context) override;
};


#endif //CPPLS1_EINDOPDRACHT_GOTOIFNOTEQUALEXPRESSION_H
