#ifndef CPPLS1_EINDOPDRACHT_GOTOIFLESSEXPRESSION_H
#define CPPLS1_EINDOPDRACHT_GOTOIFLESSEXPRESSION_H


#include <expressions/AbstractExpression.h>

class GotoIfLessExpression : public AbstractExpression
{
    public:
        void Interpret(Context& context) override;
};


#endif //CPPLS1_EINDOPDRACHT_GOTOIFLESSEXPRESSION_H
