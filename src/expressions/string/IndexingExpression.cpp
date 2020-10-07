#include "IndexingExpression.h"

void IndexingExpression::Interpret(Context &context)
{
    int index = stoi(*context.popStack());
    std::string str = *context.popStack();
    char idx = str.at(index);

    context.pushToStack(std::string(1, idx));
}
