#ifndef CPPLS1_EINDOPDRACHT_ABSOLUTEEXPRESSION_H
#define CPPLS1_EINDOPDRACHT_ABSOLUTEEXPRESSION_H


#include <expressions/AbstractExpression.h>

class AbsoluteExpression : public AbstractExpression
{
    public:
        void Interpret(Context& context) override;
};


#endif //CPPLS1_EINDOPDRACHT_ABSOLUTEEXPRESSION_H
