#ifndef CPPLS1_EINDOPDRACHT_LOGGER_H
#define CPPLS1_EINDOPDRACHT_LOGGER_H


#include <string>

class Logger
{
    private:
        static Logger* instance;
        bool showDebug = false;
    private:
        Logger();
    public:
        static Logger* getInstance();
        void toggleDebugMessages(bool show);
        void debug(const std::string& message);
        void info(const std::string& message);
};


#endif //CPPLS1_EINDOPDRACHT_LOGGER_H
