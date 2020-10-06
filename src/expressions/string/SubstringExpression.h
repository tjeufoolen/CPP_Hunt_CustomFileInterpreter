#ifndef CPPLS1_EINDOPDRACHT_SUBSTRINGEXPRESSION_H
#define CPPLS1_EINDOPDRACHT_SUBSTRINGEXPRESSION_H


#include <expressions/AbstractExpression.h>

class SubstringExpression : public AbstractExpression
{
    public:
        void Interpret(Context& context) override;
};


#endif //CPPLS1_EINDOPDRACHT_SUBSTRINGEXPRESSION_H
