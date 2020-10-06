#ifndef CPPLS1_EINDOPDRACHT_ADDEXPRESSION_H
#define CPPLS1_EINDOPDRACHT_ADDEXPRESSION_H


#include <expressions/AbstractExpression.h>

class AddExpression : public AbstractExpression
{
    public:
        void Interpret(Context& context) override;
};


#endif //CPPLS1_EINDOPDRACHT_ADDEXPRESSION_H
