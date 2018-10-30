#include "../Declarations/position.h"

position::position() {
    this->_x = 0;
    this->_y = 0;
}

position::position(int x, int y) {
    this->_x = x;
    this->_y = y;
}

void position::print_pos() const {
    printf("Position: (%d,%d)\n", this->_x, this->_y);
}

int position::get_x() const {
    return _x;
}

void position::set_x(int _x) {
    position::_x = _x;
}

int position::get_y() const {
    return _y;
}

void position::set_y(int _y) {
    position::_y = _y;
}
