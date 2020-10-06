#include "GotoIfLessOrEqualExpression.h"

GotoIfLessOrEqualExpression::GotoIfLessOrEqualExpression(int* currentRule)
    : rule(currentRule) {}

void GotoIfLessOrEqualExpression::Interpret(Context &context)
{
    auto labelValue = context.popStack();
    int val2 = stoi(*context.popStack());
    int val1 = stoi(*context.popStack());

    if (val1 < val2 || val1 == val2)
    {
        *rule = stoi(*labelValue);
    }
}
