#include <exceptions/NotImplementedException.h>
#include "GotoIfEqualExpression.h"

void GotoIfEqualExpression::Interpret(Context &context)
{
    auto labelValue = context.popStack();
    auto val2 = context.popStack();
    auto val1 = context.popStack();

    if (*val1 == *val2)
    {
        // Todo: Vervolg het interpreteren van instructies vanaf de locatie die gerepresenteerd wordt door de label-waarde
        throw NotImplementedException();
    }
}
