#include "LengthExpression.h"

void LengthExpression::Interpret(Context &context)
{
    int val = context.backStack().size(); context.popStack();
    context.pushToStack(std::to_string(val));
}
