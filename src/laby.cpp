#include <cstdlib>

#include "map.hpp"
#include "utils.hpp"

int main(int argc, char const *argv[]) {
    Map* m = new Map;
    try {
        m = m->loadMapFromFile("maps/map01");
    } catch(std::string const& e) {
        std::cerr << "ERREUR : " << e << std::endl;
        exit(EXIT_FAILURE);
    }

    m->drawMap();

    std::cout << std::endl << " ============ DEBUT DES OPERATIONS ========== " << std::endl << std::endl;

    std::cout << "Recuperation de l'operateur a gauche : " << Utils::operatorToChar(m->getOperator(Map::LEFT)) << std::endl;
    std::cout << "Recuperation de l'operateur a droite : " << Utils::operatorToChar(m->getOperator(Map::RIGHT)) << std::endl;
    std::cout << "Recuperation de l'operateur en dessous : " << Utils::operatorToChar(m->getOperator(Map::DOWN)) << std::endl;
    std::cout << "Recuperation de l'operateur au dessus : " << Utils::operatorToChar(m->getOperator(Map::UP)) << std::endl;

    delete m;

    return EXIT_SUCCESS;
}
