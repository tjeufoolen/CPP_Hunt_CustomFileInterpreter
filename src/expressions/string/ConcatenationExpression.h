#ifndef CPPLS1_EINDOPDRACHT_CONCATENATIONEXPRESSION_H
#define CPPLS1_EINDOPDRACHT_CONCATENATIONEXPRESSION_H


#include <expressions/IExpression.h>

class ConcatenationExpression : public IExpression
{
    public:
        void Interpret(Context& context) override;
};


#endif //CPPLS1_EINDOPDRACHT_CONCATENATIONEXPRESSION_H
