#ifndef CPPLS1_EINDOPDRACHT_SUBSTRINGEXPRESSION_H
#define CPPLS1_EINDOPDRACHT_SUBSTRINGEXPRESSION_H


#include <expressions/IExpression.h>

class SubstringExpression : public IExpression
{
    public:
        void Interpret(Context& context) override;
};


#endif //CPPLS1_EINDOPDRACHT_SUBSTRINGEXPRESSION_H
