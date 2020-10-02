#include <iostream>
#include "src/curlwrapper.h"

int main()
{
    std::unique_ptr<cUrlWrapper> cUrl{};
    std::vector<std::string> lines = cUrl->getResponse("https://www.swiftcoder.nl/cpp1/start.txt");

    // Read response line by line
    for(auto const& line: lines) {
        std::cout << line << std::endl;
    }
}