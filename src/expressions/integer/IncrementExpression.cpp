#include "IncrementExpression.h"

void IncrementExpression::Interpret(Context &context)
{
    int val = stoi(*context.popStack()) + 1;
    context.pushToStack(std::to_string(val));
}
