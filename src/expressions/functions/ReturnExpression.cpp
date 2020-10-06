#include "ReturnExpression.h"

ReturnExpression::ReturnExpression(int *currentRule)
    : rule(currentRule) {}

void ReturnExpression::Interpret(Context &context)
{
    *rule = stoi(*context.popCallStack());
}
