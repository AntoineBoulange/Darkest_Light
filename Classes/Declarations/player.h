#include <ctime>
#include <cmath>
#include "position.h"

#ifndef GAMEJAM_1_ENSEIRB_PLAYER_H
#define GAMEJAM_1_ENSEIRB_PLAYER_H

class player {
private:
    // Attributes
    int _hunger;
    int _life;
    position _pos;
    position _beginJump;
    position _mvt;
    bool _toStop;
    bool _toChangeDirection;
    bool _forward;
    int _light;
    bool _reduction;
    int _timer;
    int _height;
    int _width;
    int _status;

public:
    // Constructors
    player();

    // Functions
    void hunger_decrease();
    void life_decrease();
    void print_hunger() const;
    void print_life() const;
    bool is_dead() const;
    void jump();
    void move();

    // Getter
    const position &get_pos() const;
    int get_life() const;
    const position &get_mvt() const;

    // Setter
    void set_pos(int x, int y);
    void set_mvt(int x, int y);
    void set_life(int life);
};


#endif //GAMEJAM_1_ENSEIRB_PLAYER_H
