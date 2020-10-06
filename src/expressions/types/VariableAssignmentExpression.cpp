#include "VariableAssignmentExpression.h"

VariableAssignmentExpression::VariableAssignmentExpression(const std::string &label, const std::string& value)
    : label(label), value(value) {}

void VariableAssignmentExpression::Interpret(Context &context)
{
    context.setVariable(label, value);
}
