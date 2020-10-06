#include <iostream>
#include "Logger.h"

Logger Logger::instance;


Logger& Logger::getInstance()
{
    return instance;
}


void Logger::toggleDebugMessages(bool show)
{
    showDebug = show;
}


void Logger::debug(const std::string &message)
{
    if (showDebug)
        std::cout << "[DEBUG] >> " << message << std::endl;
}


void Logger::info(const std::string &message)
{
    std::cout << "[INFO] >> " << message << std::endl;
}


Logger::Logger() {}
