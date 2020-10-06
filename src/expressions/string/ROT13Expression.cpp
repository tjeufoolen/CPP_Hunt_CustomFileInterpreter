#include "ROT13Expression.h"

void ROT13Expression::Interpret(Context &context)
{
    std::string a = *context.popStack();

    int z = a.length(), i=0;
    for(i=0; i<=(z); i++) //Rot13 Algorithm
    {
        if(a[i] < 91 && a[i] > 64) //uppercase
        {
            if(a[i] < 78)
                a[i] = a[i] + 13;
            else
                a[i] = a[i] - 13;
        }
        if(a[i] < 123 && a[i] > 96) //lowercase
        {
            if(a[i] < 110)
                a[i] = a[i] + 13;
            else
                a[i] = a[i] - 13;
        }
    }

    context.pushToStack(a);
}
