#include "AbsoluteExpression.h"

void AbsoluteExpression::Interpret(Context &context)
{
    int val = stoi(*context.popStack());
    context.pushToStack(std::to_string(abs(val)));
}
