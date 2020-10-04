#ifndef CPPLS1_EINDOPDRACHT_PROGRAM_H
#define CPPLS1_EINDOPDRACHT_PROGRAM_H

#include <vector>
#include <string>
#include <map>

class Program
{
    private:
        bool foundSolution;
        std::string baseUrl;
        std::vector<std::string> stack;
        std::map<std::string, int> labels;
        std::map<std::string, std::string> variables;
    public:
        Program();
        Program(const std::string& baseUrl);
        std::string solve(const std::string& endpoint);
    private:
        void handleExpression(const std::string& expression, const std::vector<std::string>& lines, int rule);
};


#endif //CPPLS1_EINDOPDRACHT_PROGRAM_H
