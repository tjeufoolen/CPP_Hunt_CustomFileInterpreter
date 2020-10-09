#ifndef CPPLS1_EINDOPDRACHT_GOTOEXPRESSION_H
#define CPPLS1_EINDOPDRACHT_GOTOEXPRESSION_H


#include <expressions/IExpression.h>

class GotoExpression : public IExpression
{
    private:
        int &rule;
    public:
        GotoExpression() = delete;
        GotoExpression(int &currentUrl);
        void Interpret(Context& context) override;
};


#endif //CPPLS1_EINDOPDRACHT_GOTOEXPRESSION_H
