#include <iostream>
#include "src/curlwrapper.h"

/*
 *
 * Searching with
 * ,--. ,--.               ,--.
 * |  .'   /,--.--.,--.,--.|  |
 * |  .   ' |  .--'|  ||  ||  |
 * |  |\   \|  |   '  ''  '|  |
 * `--' '--'`--'    `----' `--'
 *
 * Made by Tjeu Foolen
 * Commissioned by Bob Polis (Teacher Avans Hogeschool at Den Bosch)
 * 29 October 2020
 */
int main()
{
    const std::string baseUrl = "https://www.swiftcoder.nl/cpp1/";

    std::unique_ptr<cUrlWrapper> cUrl{};
    std::vector<std::string> lines = cUrl->getResponse(baseUrl + "start.txt");

    // Read response line by line
    for(auto const& line: lines) {
        std::cout << line << std::endl;
    }
}