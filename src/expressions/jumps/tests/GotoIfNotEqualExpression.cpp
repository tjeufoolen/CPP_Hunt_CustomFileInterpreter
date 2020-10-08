#include "GotoIfNotEqualExpression.h"

GotoIfNotEqualExpression::GotoIfNotEqualExpression(int &currentRule)
        : rule(currentRule) {}

void GotoIfNotEqualExpression::Interpret(Context &context)
{
    auto labelValue = context.popStack();
    auto val2 = context.popStack();
    auto val1 = context.popStack();

    if (*val1 != *val2)
    {
        rule = stoi(*labelValue);
    }
}
