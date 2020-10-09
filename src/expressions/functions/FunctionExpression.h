#ifndef CPPLS1_EINDOPDRACHT_FUNCTIONEXPRESSION_H
#define CPPLS1_EINDOPDRACHT_FUNCTIONEXPRESSION_H


#include <expressions/IExpression.h>

class FunctionExpression : public IExpression
{
    private:
        int &rule;
    public:
        FunctionExpression() = delete;
        FunctionExpression(int &rule);
        void Interpret(Context& context) override;
};


#endif //CPPLS1_EINDOPDRACHT_FUNCTIONEXPRESSION_H
