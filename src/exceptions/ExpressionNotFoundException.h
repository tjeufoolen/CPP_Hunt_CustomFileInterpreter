#include <exception>

struct ExpressionNotFoundException : public std::exception
{
    const char* what() const throw ()
    {
        return "The used expression does not exist.";
    }
};
