#include "GotoIfLessExpression.h"

GotoIfLessExpression::GotoIfLessExpression(int *currentRule)
    : rule(currentRule) {}

void GotoIfLessExpression::Interpret(Context &context)
{
    auto labelValue = context.popStack();
    int val2 = stoi(*context.popStack());
    int val1 = stoi(*context.popStack());

    if (val1 < val2)
    {
        *rule = stoi(*labelValue);
    }
}
