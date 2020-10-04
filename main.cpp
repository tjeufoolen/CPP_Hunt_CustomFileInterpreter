#include <program.h>
#include <utils/Logger.h>

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
    // prepare
//    Logger::getInstance()->toggleDebugMessages(true);
    Program program{};

    // solve
    std::string result = program.solve("start.txt");
    Logger::getInstance()->info("result: " + result);

    return 0;
}

