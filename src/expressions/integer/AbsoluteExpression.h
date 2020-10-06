#ifndef CPPLS1_EINDOPDRACHT_ABSOLUTEEXPRESSION_H
#define CPPLS1_EINDOPDRACHT_ABSOLUTEEXPRESSION_H


#include <expressions/IExpression.h>

class AbsoluteExpression : public IExpression
{
    public:
        void Interpret(Context& context) override;
};


#endif //CPPLS1_EINDOPDRACHT_ABSOLUTEEXPRESSION_H
