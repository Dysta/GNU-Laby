#include <cstdlib>

#include "map.hpp"
#include "utils.hpp"

int main(int argc, char *argv[]) {
    std::ignore = argc;
    std::ignore = argv;
    Map* m = new Map;
    try {
        m = Map::loadMapFromFile("../laby/maps/map01.txt");
    } catch(std::string const& e) {
        std::cerr << "ERREUR : " << e << std::endl;
        exit(EXIT_FAILURE);
    }

    m->drawMap();

    delete m;

    return EXIT_SUCCESS;
}
