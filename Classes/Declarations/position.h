#include <cstdio>

#ifndef GAMEJAM_1_ENSEIRB_POSITION_H
#define GAMEJAM_1_ENSEIRB_POSITION_H


class position {
private:
    // Attributes
    int _x;
    int _y;

public:
    // Constructors
    position();
    position(int x, int y);

    // Functions
    void print_pos() const;

    // Getter
    int get_x() const;
    int get_y() const;

    // Setter
    void set_x(int x);
    void set_y(int y);
};


#endif //GAMEJAM_1_ENSEIRB_POSITION_H
