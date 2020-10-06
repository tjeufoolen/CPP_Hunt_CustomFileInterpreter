#ifndef CPPLS1_EINDOPDRACHT_LABELDEFINITIONEXPRESSION_H
#define CPPLS1_EINDOPDRACHT_LABELDEFINITIONEXPRESSION_H


#include <expressions/AbstractExpression.h>

class LabelDefinitionExpression : public AbstractExpression
{
    private:
        const std::string& label;
        int rule;
    public:
        LabelDefinitionExpression(const std::string& label, int rule);
        void Interpret(Context& context) override;
};


#endif //CPPLS1_EINDOPDRACHT_LABELDEFINITIONEXPRESSION_H
