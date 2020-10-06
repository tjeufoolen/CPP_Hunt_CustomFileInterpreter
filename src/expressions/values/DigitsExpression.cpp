#include "DigitsExpression.h"
#include <expressions/integer/NegateExpression.h>

DigitsExpression::DigitsExpression(const std::string &expression)
    : expression(expression) {}

void DigitsExpression::Interpret(Context &context)
{
    if (int value = stoi(expression) < 0)
    {
        value=abs(value);
        context.pushToStack(std::to_string(value));
        NegateExpression{}.Interpret(context);
    }

    context.pushToStack(expression);
}
