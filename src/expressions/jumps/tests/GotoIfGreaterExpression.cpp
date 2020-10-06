#include <exceptions/NotImplementedException.h>
#include "GotoIfGreaterExpression.h"

void GotoIfGreaterExpression::Interpret(Context &context)
{
    auto labelValue = context.popStack();
    int val2 = stoi(*context.popStack());
    int val1 = stoi(*context.popStack());

    if (val1 > val2)
    {
        // Todo: Vervolg het interpreteren van instructies vanaf de locatie die gerepresenteerd wordt door de label-waarde
        throw NotImplementedException();
    }
}
