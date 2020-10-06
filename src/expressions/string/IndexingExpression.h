#ifndef CPPLS1_EINDOPDRACHT_INDEXINGEXPRESSION_H
#define CPPLS1_EINDOPDRACHT_INDEXINGEXPRESSION_H


#include <expressions/IExpression.h>

class IndexingExpression : public IExpression
{
    public:
        void Interpret(Context& context) override;
};


#endif //CPPLS1_EINDOPDRACHT_INDEXINGEXPRESSION_H
