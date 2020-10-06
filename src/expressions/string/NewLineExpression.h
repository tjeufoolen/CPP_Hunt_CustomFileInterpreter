#ifndef CPPLS1_EINDOPDRACHT_NEWLINEEXPRESSION_H
#define CPPLS1_EINDOPDRACHT_NEWLINEEXPRESSION_H


#include <expressions/IExpression.h>

class NewLineExpression : public IExpression
{
    public:
        void Interpret(Context& context) override;
};


#endif //CPPLS1_EINDOPDRACHT_NEWLINEEXPRESSION_H
