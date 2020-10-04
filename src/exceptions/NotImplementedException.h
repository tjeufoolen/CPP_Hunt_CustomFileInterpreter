#include <exception>

struct NotImplementedException : public std::exception
{
    const char* what() const throw ()
    {
        return "This code isn't implemented yet.";
    }
};
