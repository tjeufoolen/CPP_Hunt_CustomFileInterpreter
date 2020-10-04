#ifndef CPPLS1_EINDOPDRACHT_CURLWRAPPER_H
#define CPPLS1_EINDOPDRACHT_CURLWRAPPER_H


#include <curl/curl.h>
#include <string>
#include <vector>
#include <sstream>

class cUrlWrapper
{
    private:
        static std::size_t callback(const char* in, std::size_t size, std::size_t num, std::string* out);
        std::vector<std::string> getLinesFromText(const std::string& text);
    public:
        cUrlWrapper();
        ~cUrlWrapper();
        std::vector<std::string> getResponse(const std::string& url);
};


#endif //CPPLS1_EINDOPDRACHT_CURLWRAPPER_H
