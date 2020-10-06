#ifndef CPPLS1_EINDOPDRACHT_DUPLICATEEXPRESSION_H
#define CPPLS1_EINDOPDRACHT_DUPLICATEEXPRESSION_H


#include <expressions/IExpression.h>

class DuplicateExpression : public IExpression
{
    public:
        void Interpret(Context& context) override;
};


#endif //CPPLS1_EINDOPDRACHT_DUPLICATEEXPRESSION_H
