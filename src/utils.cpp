#include "map.hpp"

namespace Utils {
    char operatorToChar(Map::e_operator e) {
        switch ( e ) {
            case Map::PLUS: return '+';
            case Map::MINUS: return '-';
            case Map::DIVIDE: return '/';
            case Map::MULTIPLY: return '*';
            default: return '?';
        }
    }

    Map::e_operator charToOperator(char c) {
        switch ( c ) {
            case '+': return Map::PLUS;
            case '-': return Map::MINUS;
            case '/': return Map::DIVIDE;
            case '*': return Map::MULTIPLY;
            default: return Map::OP_UNDEFINED;
        }
    }
} // end namespace Utils