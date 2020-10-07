#include "SubtractExpression.h"

void SubtractExpression::Interpret(Context &context)
{
    int val1 = stoi(*context.popStack());
    int val2 = stoi(*context.popStack());

    context.pushToStack(std::to_string(val2 - val1));
}
