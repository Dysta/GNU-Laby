#ifndef H_MAP
#define H_MAP

#include <fstream>
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <string>

class Map {

    public:
        typedef enum {
            PLUS,
            MINUS,
            DIVIDE,
            MULTIPLY,
            OP_UNDEFINED
        } e_operator;

        typedef enum {
            UP,
            DOWN,
            LEFT,
            RIGHT,
            DIR_UNDEFINED
        } e_direction;

        typedef union {
            int number;
            e_operator opcode;
        } u_case;

        //Map(const std::string filename) ;
        ~Map(void);
        void loadMapFromFile(std::string const& file);
        void drawMap(void);
        int getActualValue(void);
        e_operator getOperator(e_direction dir);
        bool applyOpreator(e_direction dir);
        e_direction* resolve(void);

        int _position;
    private:
        int _level;
        int _size;
        int _goalScore;
        int _startingScore;
        u_case* _grid;
    
};

#endif // !H_MAP