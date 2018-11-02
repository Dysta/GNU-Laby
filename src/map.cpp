#include "map.hpp"
#include "utils.hpp"

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
void Map::loadMapFromFile(std::string const& filename) {
    std::ifstream file(filename.c_str());
    if ( file.fail() ) {
        throw std::string("Canno't open file : " + filename);
    }

    // read the level
    file >> this->_level;

    // read the width/height
    file >> this->_size;
    if ( this->_size % 2 == 0 ) {
        throw std::string(filename + " : invalide map size");
    }

    // read the goal score
    file >> this->_goalScore;

    // read the start position
    file >> this->_position;
    if ( this->_position % 2 == 1 ) {
        throw std::string(filename + " : invalide start position");
    }
    
    // allocating memory
    this->_grid = new Map::u_case[_size * _size];
    // read the integer of the grid
    for ( int i = 0; i < this->_size * this->_size; i+=2 ) {
        if ( i != 0 && i % this->_size - 1 == 0 ) 
            i+= this->_size - 1;
        file >> this->_grid[i].number;
    }

    // read the opcode of the grid
    char c;
    for ( int i = 1; i < this->_size * this->_size; i+=2) {
        file >> c;
        this->_grid[i].opcode = Utils::charToOperator(c);
    }

    // init the starting score
    this->_startingScore = this->_grid[this->_position].number;
    
    file.close();
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
    std::cout << "Level " << this->_level << " : " << this->_startingScore << " -> " << this->_goalScore << " : " << this->getActualValue() << std::endl;
    for ( int i = 0, evenLine = true; i < this->_size * this->_size; i++ ) {
        if ( evenLine ) {
            if ( i % 2 == 0 )
                std::cout << this->_grid[i].number << ((int) this->_position == i ? "^" : " " ) << std::setw((this->_grid[i].number > 9) ? ((this->_grid[i].number > 99) ? 2 : 3) : 4);
            else
                std::cout << Utils::operatorToChar(this->_grid[i].opcode) << std::setw(5);
        } else {
            if ( i % 2 != 0 )
                std::cout << Utils::operatorToChar(this->_grid[i].opcode) << std::setw(10);
        }

        if ( (i + 1) % this->_size == 0 ) {
            std::cout << std::setw(0) << std::endl;
            evenLine = !evenLine;
        }
    }
}

/*
* This function returns the actual score of a labyMap.
* 
* \return the actual score corresponding to the content of the actual cell.
*/
int Map::getActualValue() {
    return this->_grid[this->_position].number;
}


/*
* This function returns the actual operand in a given direction of the actual position in a labyMap.
* 
* \param d a direction.
* \return the operand in the direction d of the actual position.
*/
Map::e_operator Map::getOperator(e_direction dir) {
    if ( dir == UP ) {
        if ( this->_position < this->_size ) {
            return OP_UNDEFINED;
        } else {
            return this->_grid[this->_position - this->_size].opcode;
        }
    }

    if ( dir == DOWN ) {
        if ( this->_position + this->_size >= this->_size * this->_size ) {
            return OP_UNDEFINED;
        } else {
            return this->_grid[this->_position + this->_size].opcode;
        }
    }

    if ( dir == LEFT ) {
        if ( this->_position % this->_size == 0 ) {
            return OP_UNDEFINED;
        } else {
            return this->_grid[this->_position - 1].opcode;
        }
    }

    if ( dir == RIGHT ) {
        if ( (this->_position + 1) % this->_size == 0 ) {
            return OP_UNDEFINED;
        } else {
            return this->_grid[this->_position + 1].opcode;
        }
    }

    return OP_UNDEFINED;
}

Map::~Map() {
    delete _grid;
}
