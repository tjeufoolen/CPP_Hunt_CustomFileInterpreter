#include "IndexingExpression.h"

void IndexingExpression::Interpret(Context &context)
{
    int index = stoi(*context.popStack());
    auto str = context.popStack();

    context.pushToStack(std::to_string(str->at(index)));
}
