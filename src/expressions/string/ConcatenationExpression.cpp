#include "ConcatenationExpression.h"

void ConcatenationExpression::Interpret(Context &context)
{
    auto str2 = context.popStack();
    auto str1 = context.popStack();

    context.pushToStack(*str1 + *str2);
}
