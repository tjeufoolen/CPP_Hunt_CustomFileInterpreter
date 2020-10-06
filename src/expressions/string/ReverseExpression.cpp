#include "ReverseExpression.h"

void ReverseExpression::Interpret(Context &context)
{
    auto str = context.popStack();
    reverse(str->begin(), str->end());
    context.pushToStack(*str);
}
