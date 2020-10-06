#ifndef CPPLS1_EINDOPDRACHT_LABELREFERENCEEXPRESSION_H
#define CPPLS1_EINDOPDRACHT_LABELREFERENCEEXPRESSION_H


#include <expressions/AbstractExpression.h>

class LabelReferenceExpression : public AbstractExpression
{
    public:
        void Interpret(Context& context) override;
};


#endif //CPPLS1_EINDOPDRACHT_LABELREFERENCEEXPRESSION_H
