#include "LabelReferenceExpression.h"

LabelReferenceExpression::LabelReferenceExpression(const std::string &label)
    : label(label) {}

void LabelReferenceExpression::Interpret(Context &context)
{
    context.pushToStack(std::to_string(context.getLabel(label)));
}
