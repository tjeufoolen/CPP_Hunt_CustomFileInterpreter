#include "GotoExpression.h"

GotoExpression::GotoExpression(int &currentUrl)
        : rule(currentUrl) {}

void GotoExpression::Interpret(Context &context)
{
    rule = stoi(*context.popStack());
}
