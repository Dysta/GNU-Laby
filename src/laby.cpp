#include <cstdlib>

#include "map.hpp"

int main(int argc, char const *argv[]) {
    Map* m = new Map("maps/map01");

    m->drawMap();

    delete m;

    return EXIT_SUCCESS;
}
