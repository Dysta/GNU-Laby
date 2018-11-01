#ifndef H_MAP
#define H_MAP

#include <fstream>
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <string>

class Map {

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
        char opcode;
    } u_case;

    public:
        Map(void);
        Map(int level, int size, int goalScore, int position);
        Map(const std::string filename);
        ~Map(void);
        void loadMapFromFile(std::string file);
        void drawMap(void);
        int getScore(void);
        e_operator getOperator(e_direction dir);
        bool applyOpreator(e_direction dir);
        e_direction* resolve(void);

    private:
        int _level;
        int _size;
        unsigned int _position;
        int _goalScore;
        int _score;
        u_case* _grid;
    
};

#endif // !H_MAP