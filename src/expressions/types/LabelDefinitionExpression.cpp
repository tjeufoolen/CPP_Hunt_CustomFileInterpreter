#include "LabelDefinitionExpression.h"

LabelDefinitionExpression::LabelDefinitionExpression(const std::string &label, int &rule)
    : label(label), rule(rule) {}

void LabelDefinitionExpression::Interpret(Context &context)
{
    context.setLabel(label, rule);
}


