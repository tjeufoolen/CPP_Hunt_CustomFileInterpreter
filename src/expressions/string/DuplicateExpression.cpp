#include "DuplicateExpression.h"

void DuplicateExpression::Interpret(Context &context)
{
    context.pushToStack(context.backStack());
}
