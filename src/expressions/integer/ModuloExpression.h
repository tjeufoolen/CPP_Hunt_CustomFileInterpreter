#ifndef CPPLS1_EINDOPDRACHT_MODULOEXPRESSION_H
#define CPPLS1_EINDOPDRACHT_MODULOEXPRESSION_H


#include <expressions/IExpression.h>

class ModuloExpression : public IExpression
{
    public:
        void Interpret(Context& context) override;
};


#endif //CPPLS1_EINDOPDRACHT_MODULOEXPRESSION_H
