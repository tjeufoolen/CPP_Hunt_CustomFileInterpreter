#ifndef CPPLS1_EINDOPDRACHT_DIGITSEXPRESSION_H
#define CPPLS1_EINDOPDRACHT_DIGITSEXPRESSION_H


#include <expressions/AbstractExpression.h>

class DigitsExpression : public AbstractExpression
{
    private:
        const std::string& expression;
    public:
        DigitsExpression(const std::string& expression);
        void Interpret(Context& context) override;
};


#endif //CPPLS1_EINDOPDRACHT_DIGITSEXPRESSION_H
