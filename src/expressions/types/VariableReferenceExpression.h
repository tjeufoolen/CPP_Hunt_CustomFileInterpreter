#ifndef CPPLS1_EINDOPDRACHT_VARIABLEREFERENCEEXPRESSION_H
#define CPPLS1_EINDOPDRACHT_VARIABLEREFERENCEEXPRESSION_H


#include <expressions/AbstractExpression.h>

class VariableReferenceExpression : public AbstractExpression
{
    private:
        const std::string& label;
    public:
        VariableReferenceExpression(const std::string& label);
        void Interpret(Context& context) override;
};


#endif //CPPLS1_EINDOPDRACHT_VARIABLEREFERENCEEXPRESSION_H
