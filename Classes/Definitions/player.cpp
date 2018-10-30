#include <cstdio>
#include "../Declarations/player.h"

#define MAX_HUNGER 100
#define DEC_HUNGER 20
#define MAX_LIFE 3
#define GRAVITY 9.81
#define PI 3.14

player::player(): _hunger{MAX_HUNGER},
                  _life{MAX_LIFE},
                  _forward{true},
                  _reduction{false},
                  _timer{0},
                  _height{0},
                  _width{0},
                  _status{0}
{}

// TODO : Déplacer cette fonction dans le controller
// TODO : Harmoniser la réduction de _hunger et celle de _life (fonction ou pas ?)
// TODO : Forker cette fonction pour avoir le "vrai" jeu en parallèle
void player::hunger_decrease() {
    time_t timer = time(nullptr);

    while(this->_hunger != 0){
        if(timer != time(nullptr)){
            timer = time(nullptr);
            this->_hunger = this->_hunger - DEC_HUNGER;
            print_hunger();
        }
    }
    while(this->_life != 0 && this->_hunger == 0){
        if(timer != time(nullptr)){
            timer = time(nullptr);
            life_decrease();
            print_life();
        }
    }
}

void player::move() {
    int nextX = _pos.get_x() + _mvt.get_x();
    switch (_status){
        case 0:
            if(nextX >= 0 && nextX <= 1200){
                if(nextX <= 0)
                    _pos.set_x(0);
                else if(nextX + _width >= 1200)
                    _pos.set_x(1200 - _width);
                else
                    _pos.set_x(nextX);
            }
            break;

        case 1:
        case 2:
            jump();
            break;

        default:
            break;
    }
}

void player::jump(){
    // TESTS TODO delete
    _beginJump = _pos;
    // FIN TESTS

    double theta;

    if(_forward)
        theta = PI / 3;
    else
        theta = 2 * PI / 3;

    auto newX = (int)round(_beginJump.get_x() + ((fabs(_mvt.get_x()) * cos(theta) * _timer) * 0.04));

    if(_reduction)
        _pos.set_x((int)round((newX) - ((newX - _pos.get_x()) * 0.9)));
    else
        _pos.set_x(newX);

    _pos.set_y((int)round((_beginJump.get_y() - _height/2) - ((((-1) * GRAVITY * (_timer * _timer) / 2000) + (_mvt.get_y() * sin(theta) * _timer) + (_height / 2)) * 0.08)));

    _timer += 100;

    if(_pos.get_x() < 0 || _pos.get_x() > 1200 - _width){
        if(_pos.get_x() < 0)
            _pos.set_x(0);
        if(_pos.get_x() > 1200 - _width)
            _pos.set_x(1200 - _width);
    }

    if((_pos.get_y() + _height) > 500){
        _pos.set_y(500 - _height);
        _timer = 0;
        _status = 0;
    }
}

void player::print_hunger() const {
    printf("Hunger: %d\n", this->_hunger);
}

void player::print_life() const {
    printf("Life: %d\n", this->_life);
}

void player::life_decrease() {
    this->_life = this->_life - 1;
}

bool player::is_dead() const {
    return this->_life == 0;
}

const position &player::get_pos() const {
    return this->_pos;
}

void player::set_pos(const int x, const int y) {
    this->_pos.set_x(x);
    this->_pos.set_y(y);
}

int player::get_life() const {
    return this->_life;
}

void player::set_life(int life) {
    this->_life = life;
}

const position &player::get_mvt() const {
    return this->_mvt;
}

void player::set_mvt(int x, int y) {
    this->_mvt.set_x(x);
    this->_mvt.set_y(y);
}
