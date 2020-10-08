#ifndef CPPLS1_EINDOPDRACHT_TEXTEXPRESSION_H
#define CPPLS1_EINDOPDRACHT_TEXTEXPRESSION_H


#include <expressions/IExpression.h>
#include <string>

class TextExpression : public IExpression
{
    private:
        const std::string& text;
    public:
        TextExpression(const std::string& text);
        void Interpret(Context& context) override;
};


#endif //CPPLS1_EINDOPDRACHT_TEXTEXPRESSION_H
