#ifndef CPPLS1_EINDOPDRACHT_RETURNEXPRESSION_H
#define CPPLS1_EINDOPDRACHT_RETURNEXPRESSION_H


#include <expressions/IExpression.h>

class ReturnExpression : public IExpression
{
    private:
        int &rule;
    public:
        ReturnExpression() = delete;
        ReturnExpression(int &currentRule);
        void Interpret(Context& context) override;
};


#endif //CPPLS1_EINDOPDRACHT_RETURNEXPRESSION_H
