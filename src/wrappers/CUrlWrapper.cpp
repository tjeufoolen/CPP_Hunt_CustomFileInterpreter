#include <exceptions/FileNotFoundException.h>
#include "CUrlWrapper.h"

cUrlWrapper::cUrlWrapper()
{
    curl_global_init(CURL_GLOBAL_DEFAULT);
}


cUrlWrapper::~cUrlWrapper()
{
    curl_global_cleanup();
}


std::vector<std::string> cUrlWrapper::getResponse(const std::string& url)
{
    CURL *curl;
    CURLcode response;
    std::string readBuffer;

    curl = curl_easy_init();
    if (curl)
    {
        curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
        curl_easy_setopt(curl, CURLOPT_TIMEOUT, 10);
        curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1L);
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, callback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &readBuffer);
        curl_easy_setopt(curl, CURLOPT_FAILONERROR, true);

        /* Perform the request, res will get the return code */
        response = curl_easy_perform(curl);

        /* Check for errors */
        if (response == CURLE_HTTP_RETURNED_ERROR)
            throw FileNotFoundException();

        /* always cleanup */
        curl_easy_cleanup(curl);
    }

    return getLinesFromText(readBuffer);
}


std::size_t cUrlWrapper::callback(const char* in, std::size_t size, std::size_t num, std::string* out)
{
    const std::size_t totalBytes(size * num);
    out->append(in, totalBytes);
    return totalBytes;
}


std::vector<std::string> cUrlWrapper::getLinesFromText(const std::string& text)
{
    std::vector<std::string> lines;
    std::istringstream ss(text);

    while (!ss.eof())
    {
        std::string str;
        getline(ss, str);

        if (!str.empty())
            lines.push_back(str);
    }

    return lines;
}