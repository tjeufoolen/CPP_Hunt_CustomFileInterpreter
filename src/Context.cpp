#include <utils/Logger.h>
#include "Context.h"

Context::Context() {}

void Context::pushToStack(const std::string &str)
{
    stack.push_back(str);
    Logger::getInstance().debug("added " + str + " to the stack.");
}

std::unique_ptr<std::string> Context::popStack()
{
    auto str = std::make_unique<std::string>(stack.back());
    stack.pop_back();
    Logger::getInstance().debug("removed and returned " + *str + " from the stack.");
    return str;
}

const std::string& Context::backStack()
{
    Logger::getInstance().debug("returned " + stack.back() + " from the stack.");
    return stack.back();
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
