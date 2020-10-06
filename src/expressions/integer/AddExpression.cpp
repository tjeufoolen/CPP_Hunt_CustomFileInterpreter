#include "AddExpression.h"

void AddExpression::Interpret(Context &context)
{
    int val2 = stoi(*context.popStack());
    int val1 = stoi(*context.popStack());

    context.pushToStack(std::to_string(val1 + val2));
}
