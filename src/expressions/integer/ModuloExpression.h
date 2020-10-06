#ifndef CPPLS1_EINDOPDRACHT_MODULOEXPRESSION_H
#define CPPLS1_EINDOPDRACHT_MODULOEXPRESSION_H


#include <expressions/AbstractExpression.h>

class ModuloExpression : public AbstractExpression
{
    public:
        void Interpret(Context& context) override;
};


#endif //CPPLS1_EINDOPDRACHT_MODULOEXPRESSION_H
