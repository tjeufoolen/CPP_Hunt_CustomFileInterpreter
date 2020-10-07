#include <exception>

struct FileNotFoundException : public std::exception
{
    const char* what() const throw ()
    {
        return "The requested file could not be found.";
    }
};
