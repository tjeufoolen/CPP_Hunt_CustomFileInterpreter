#ifndef CPPLS1_EINDOPDRACHT_LOGGER_H
#define CPPLS1_EINDOPDRACHT_LOGGER_H


#include <string>

class Logger
{
    private:
        static Logger instance;
        bool showDebug = false;
    public:
        static Logger& getInstance();
        void toggleDebugMessages(bool show);
        void error(const std::string& message);
        void debug(const std::string& message);
        void info(const std::string& message);
    private:
        Logger();
};


#endif //CPPLS1_EINDOPDRACHT_LOGGER_H
