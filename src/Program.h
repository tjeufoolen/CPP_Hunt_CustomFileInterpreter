#ifndef CPPLS1_EINDOPDRACHT_PROGRAM_H
#define CPPLS1_EINDOPDRACHT_PROGRAM_H

#include <vector>
#include <string>
#include <map>
#include <Context.h>

class Program
{
    private:
        bool foundSolution{false};
        std::string baseUrl;
        int currentRule = 0;
    public:
        Program();
        Program(const std::string& baseUrl);
        std::string solve(const std::string& endpoint);
    private:
        void predefineLabels(const std::vector<std::string> &lines, Context& context);
        void handleExpressions(const std::vector<std::string> &lines, Context& context);
        void handleExpression(const std::string& expression, Context& context);
};


#endif //CPPLS1_EINDOPDRACHT_PROGRAM_H
