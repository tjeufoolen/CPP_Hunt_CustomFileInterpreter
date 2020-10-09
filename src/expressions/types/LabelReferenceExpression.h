#ifndef CPPLS1_EINDOPDRACHT_LABELREFERENCEEXPRESSION_H
#define CPPLS1_EINDOPDRACHT_LABELREFERENCEEXPRESSION_H


#include <expressions/IExpression.h>

class LabelReferenceExpression : public IExpression
{
    private:
        const std::string& label;
    public:
        LabelReferenceExpression() = delete;
        LabelReferenceExpression(const std::string& label);
        void Interpret(Context& context) override;
};


#endif //CPPLS1_EINDOPDRACHT_LABELREFERENCEEXPRESSION_H
