#ifndef CPPLS1_EINDOPDRACHT_GOTOEXPRESSION_H
#define CPPLS1_EINDOPDRACHT_GOTOEXPRESSION_H


#include <expressions/AbstractExpression.h>

class GotoExpression : public AbstractExpression
{
    private:
        int* rule;
    public:
        GotoExpression(int* currentUrl);
        void Interpret(Context& context) override;
};


#endif //CPPLS1_EINDOPDRACHT_GOTOEXPRESSION_H
