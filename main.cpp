#include <Program.h>
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
    Logger::getInstance().toggleDebugMessages(true); // <-- todo: set to false when done.
    Program program{/*"https://www.swiftcoder.nl/cpp1/"*/};

    // solve
//    std::string solution = program.solve("start.txt");
    std::string solution = program.solve("4812-9-6727.txt");
    Logger::getInstance().info("solution: " + solution);

    return 0;
}

