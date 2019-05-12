#include "tests.hpp"

void test_load_map01() {
    std::cout << "FSDFSDFSDFSDF" << std::endl;
    Map* map = new Map;
    map = map->loadMapFromFile("maps/map01");
    assert(map->getLevel() == 1);
}

int main(int argc, char* argv[]) {
    test_load_map01();
    return EXIT_SUCCESS;
}