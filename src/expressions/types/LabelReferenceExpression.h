#ifndef CPPLS1_EINDOPDRACHT_LABELREFERENCEEXPRESSION_H
#define CPPLS1_EINDOPDRACHT_LABELREFERENCEEXPRESSION_H


#include <expressions/AbstractExpression.h>

class LabelReferenceExpression : public AbstractExpression
{
    private:
        const std::string& label;
    public:
        LabelReferenceExpression(const std::string& label);
        void Interpret(Context& context) override;
};


#endif //CPPLS1_EINDOPDRACHT_LABELREFERENCEEXPRESSION_H
