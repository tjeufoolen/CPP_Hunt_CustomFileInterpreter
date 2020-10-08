#include <utils/Logger.h>
#include "Context.h"

void Context::pushToStack(const std::string &str)
{
    Logger::getInstance().debug("added " + str + " to the stack.");
    stack.push_back(str);
}

std::unique_ptr<std::string> Context::popStack()
{
    auto str = std::make_unique<std::string>(stack.back());
    Logger::getInstance().debug("removed and returned " + *str + " from the stack.");
    stack.pop_back();
    return str;
}

const std::string& Context::backStack()
{
    Logger::getInstance().debug("returned " + stack.back() + " from the stack.");
    return stack.back();
}

void Context::pushToCallStack(const std::string &str)
{
    Logger::getInstance().debug("added " + str + " to the call stack.");
    callStack.push_back(str);
}

std::unique_ptr<std::string> Context::popCallStack()
{
    auto str = std::make_unique<std::string>(callStack.back());
    Logger::getInstance().debug("removed and returned " + *str + " from the call stack.");
    callStack.pop_back();
    return str;
}

void Context::setVariable(const std::string &label, const std::string &value)
{
    Logger::getInstance().debug("set variable " + label + "=" + value);
    variables[label] = value;
}

const std::string& Context::getVariable(const std::string &label)
{
    Logger::getInstance().debug("returned variable " + label + " with value " + variables[label]);
    return variables[label];
}

void Context::setLabel(const std::string &label, int rule)
{
    Logger::getInstance().debug("set label " + label + "->" + std::to_string(rule));
    labels[label] = rule;
}

int Context::getLabel(const std::string &label)
{
    Logger::getInstance().debug("returned label " + label + " with value " + std::to_string(labels[label]));
    return labels[label];
}
