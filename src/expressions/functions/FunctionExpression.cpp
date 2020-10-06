#include <expressions/jumps/GotoExpression.h>
#include "FunctionExpression.h"

FunctionExpression::FunctionExpression(int* rule)
    : rule(rule) {}

void FunctionExpression::Interpret(Context &context)
{
    context.pushToCallStack(std::to_string(*rule));
    GotoExpression{rule}.Interpret(context);
}
