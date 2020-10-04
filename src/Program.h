#ifndef CPPLS1_EINDOPDRACHT_PROGRAM_H
#define CPPLS1_EINDOPDRACHT_PROGRAM_H

#include <vector>
#include <string>
#include <map>
#include "../Context.h"

class Program
{
    private:
        bool foundSolution;
        std::string baseUrl;
    public:
        Program();
        Program(const std::string& baseUrl);
        std::string solve(const std::string& endpoint);
    private:
        void handleExpression(const std::string& expression, Context& context, int rule);
};


#endif //CPPLS1_EINDOPDRACHT_PROGRAM_H
