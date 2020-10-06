#ifndef CPPLS1_EINDOPDRACHT_NEWLINEEXPRESSION_H
#define CPPLS1_EINDOPDRACHT_NEWLINEEXPRESSION_H


#include <expressions/AbstractExpression.h>

class NewLineExpression : public AbstractExpression
{
    public:
        void Interpret(Context& context) override;
};


#endif //CPPLS1_EINDOPDRACHT_NEWLINEEXPRESSION_H
