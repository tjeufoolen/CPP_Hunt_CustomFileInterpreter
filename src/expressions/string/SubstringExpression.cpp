#include "SubstringExpression.h"

void SubstringExpression::Interpret(Context &context)
{
    int to = stoi(*context.popStack());
    int from = stoi(*context.popStack());
    auto value = context.popStack();

    context.pushToStack(value->substr(from, to-from+1));
}
