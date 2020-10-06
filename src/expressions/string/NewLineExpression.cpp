#include "NewLineExpression.h"

void NewLineExpression::Interpret(Context &context)
{
    auto str = context.popStack();
    context.pushToStack(*str + '\n');
}
