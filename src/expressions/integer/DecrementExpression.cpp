#include "DecrementExpression.h"

void DecrementExpression::Interpret(Context &context)
{
    int val = stoi(*context.popStack());
    context.pushToStack(std::to_string(--val));
}
