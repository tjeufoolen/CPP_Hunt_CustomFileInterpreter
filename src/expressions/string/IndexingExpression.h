#ifndef CPPLS1_EINDOPDRACHT_INDEXINGEXPRESSION_H
#define CPPLS1_EINDOPDRACHT_INDEXINGEXPRESSION_H


#include <expressions/AbstractExpression.h>

class IndexingExpression : public AbstractExpression
{
    public:
        void Interpret(Context& context) override;
};


#endif //CPPLS1_EINDOPDRACHT_INDEXINGEXPRESSION_H
