#ifndef CPPLS1_EINDOPDRACHT_NEGATEEXPRESSION_H
#define CPPLS1_EINDOPDRACHT_NEGATEEXPRESSION_H


#include <expressions/AbstractExpression.h>

class NegateExpression : public AbstractExpression
{
    public:
        void Interpret(Context& context) override;
};


#endif //CPPLS1_EINDOPDRACHT_NEGATEEXPRESSION_H
