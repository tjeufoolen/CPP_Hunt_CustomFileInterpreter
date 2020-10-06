#ifndef CPPLS1_EINDOPDRACHT_ADDEXPRESSION_H
#define CPPLS1_EINDOPDRACHT_ADDEXPRESSION_H


#include <expressions/IExpression.h>

class AddExpression : public IExpression
{
    public:
        void Interpret(Context& context) override;
};


#endif //CPPLS1_EINDOPDRACHT_ADDEXPRESSION_H
