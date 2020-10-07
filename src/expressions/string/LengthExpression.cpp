#include "LengthExpression.h"

void LengthExpression::Interpret(Context &context)
{
    int val = (*context.popStack()).length();
    context.pushToStack(std::to_string(val));
}
