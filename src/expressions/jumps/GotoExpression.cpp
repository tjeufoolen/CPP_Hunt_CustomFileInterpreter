#include <exceptions/NotImplementedException.h>
#include "GotoExpression.h"

void GotoExpression::Interpret(Context &context)
{
    // todo: haal een waarde van de stack, interpreteer die als nodig om de volgende code van de regel te lezen die door deze label-waarde wordt gerepresenteerd.
    throw NotImplementedException();
}
