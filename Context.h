#ifndef CPPLS1_EINDOPDRACHT_CONTEXT_H
#define CPPLS1_EINDOPDRACHT_CONTEXT_H


#include <vector>
#include <string>
#include <map>

class Context
{
    private:
        std::vector<std::string> stack;
        std::map<std::string, std::string> variables;
        std::map<std::string, int> labels;
    public:
        Context();
        void pushToStack(const std::string& str);
        std::unique_ptr<std::string> popStack();
        const std::string& backStack();
        void setVariable(const std::string& label, const std::string& value);
        const std::string& getVariable(const std::string &label);
        void setLabel(const std::string& label, int rule);
        int getLabel(const std::string& label);
};


#endif //CPPLS1_EINDOPDRACHT_CONTEXT_H
