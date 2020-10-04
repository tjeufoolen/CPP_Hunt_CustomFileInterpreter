#include "TextExpression.h"

TextExpression::TextExpression(const std::string& text)
    : text(text) {}

void TextExpression::Interpret(Context& context)
{
    context.pushToStack(text);
}
