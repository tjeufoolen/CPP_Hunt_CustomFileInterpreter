#include "NegateExpression.h"

void NegateExpression::Interpret(Context &context)
{
    int val = stoi(*context.popStack());

    if (val > 0) val=-abs(val);
    else if (val < 0) val=abs(val);

    context.pushToStack(std::to_string(val));
}
