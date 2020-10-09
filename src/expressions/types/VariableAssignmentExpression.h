#ifndef CPPLS1_EINDOPDRACHT_VARIABLEASSIGNMENTEXPRESSION_H
#define CPPLS1_EINDOPDRACHT_VARIABLEASSIGNMENTEXPRESSION_H


#include <expressions/IExpression.h>

class VariableAssignmentExpression : public IExpression
{
    private:
        const std::string& label;
        const std::string& value;
    public:
        VariableAssignmentExpression() = delete;
        VariableAssignmentExpression(const std::string& label, const std::string& value);
        void Interpret(Context& context) override;
};


#endif //CPPLS1_EINDOPDRACHT_VARIABLEASSIGNMENTEXPRESSION_H
