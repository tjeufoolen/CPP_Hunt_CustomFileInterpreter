#include "VariableReferenceExpression.h"

VariableReferenceExpression::VariableReferenceExpression(const std::string &label)
    : label(label) {}

void VariableReferenceExpression::Interpret(Context &context)
{
    context.pushToStack(context.getVariable(label));
}
