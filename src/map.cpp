#include "map.hpp"

Map::Map(void) {}

Map::Map(int level, int size, int goalScore, int position) :
    _level(level),
    _size(size),
    _position(position)
{
    this->_grid = new Map::u_case[_size * _size];
}

/*
* This function load a labyMap from a file containing the information in successive lines.
* The 1st line contains the level name. 
* The 2nd line contains the size of the map.
* The 3rd line contains the goal score.
* The 4th line conatins the start position.
* The 5th line contains the content of the cells of the map from up left to down right as 
* a list of integers separated by spaces.
* The 6th line contains the content of the cells of the map from up left to down right as 
* a list of characters.
* Note that the starting position also defines the starting score.
* 
* \param filename a File to read informations from.
* \return the adress of a labyMap allocated in the heap or NULL in case of error.
*
*/
Map::Map(const std::string filename) {
    std::ifstream file(filename.c_str());
    if ( file.fail() ) {
        std::cerr << "Canno't open file : " << filename << std::endl;
        return;
    }

    // read the level
    file >> this->_level;

    // read the width/height
    file >> this->_size;

    // read the goal score
    file >> this->_goalScore;

    // read the start position
    file >> this->_position; //FIXME: check if the start position is correct (on a integer not on a char)
    
    // allocating memory
    this->_grid = new Map::u_case[_size * _size];
    // read the integer of the grid
    for ( int i = 0; i < this->_size * this->_size; i+=2 ) {
        if ( i != 0 && i % this->_size - 1 == 0 ) 
            i+= this->_size - 1;
        file >> this->_grid[i].number;
    }

    // read the opcode of the grid
    for ( int i = 1; i < this->_size * this->_size; i+=2) {
        file >> this->_grid[i].opcode;
    }

}

/*
* This function draw an ASCII version of a labyMap as follows.
* Level <LEVEL_NAME> : <STARTING_SCORE> -> <GOAL_SCORE> : <ACTUAL_SCORE>
* <C00>  <C01>  <C02>  <C03>  <C04> 
* <C05> <SPACE> <C06> <SPACE> <C07> 
* <C08>  <C09>  <C10>  <C13>  <C11> 
* <C12> <SPACE> <C13> <SPACE> <C14> 
* <C15>  <C16>  <C17>  <C18>  <C19> 
*
* where <LEVEL_NAME>, <STARTING_SCORE> and <GOAL_SCORE> are replaced by the corresponding
* field values of the labyMap and <ACTUAL_SCORE> by the actual score.
* where <CXX> corresponds to the content of the XXth cell of the labyMap printed as a 5 characters
* string and <SPACE> are empty strings of 5 spaces. If <CXX> corresponds to the actual position in 
* the labyMap, an extra ^ symbol should be added to its right.
*
*/
void Map::drawMap() {
    std::cout << "Level " << this->_level << " : " << this->_score << " -> " << this->_goalScore << " : " << this->_score << std::endl;
    for ( int i = 0, evenLine = true; i <= this->_size * this->_size; i++ ) {
        if ( evenLine ) {
            if ( i % 2 == 0 )
                std::cout << this->_grid[i].number << ((int) this->_position == i ? "^" : " " ) << std::setw(4);
            else
                std::cout << this->_grid[i].opcode << std::setw(5);
        } else {
            if ( i % 2 != 0 )
                std::cout << this->_grid[i].opcode << std::setw(10);
        }

        if ( (i + 1) % this->_size == 0 ) {
            std::cout << std::setw(0) << std::endl;
            evenLine = !evenLine;
        }
    }

}

Map::~Map() {
    delete _grid;
}
