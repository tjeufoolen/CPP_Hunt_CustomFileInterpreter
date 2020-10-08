#include "GotoIfGreaterExpression.h"

GotoIfGreaterExpression::GotoIfGreaterExpression(int &currentRule)
    : rule(currentRule) {}

void GotoIfGreaterExpression::Interpret(Context &context)
{
    std::unique_ptr<std::string> labelValue = context.popStack();
    int val2 = stoi(*context.popStack());
    int val1 = stoi(*context.popStack());

    if (val1 > val2)
    {
        rule = stoi(*labelValue);
    }
}
