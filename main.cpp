#include "Classes/Declarations/player.h"
#include <SFML/Graphics.hpp>

void test_sfml(){
    sf::RenderWindow window(sf::VideoMode(200, 200), "SFML works");
    sf::CircleShape shape(100.f);
    shape.setFillColor(sf::Color::Green);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        window.draw(shape);
        window.display();
    }
}


int main(int argc, char** argv) {
    test_sfml();
    player p;
    /*while(!p.is_dead()){
        p.hunger_decrease();
    }
    p.get_pos().print_pos();*/

    // TEST JUMP
    p.set_pos(50, 500);
    p.set_mvt(10, 10);
    do {
        p.jump();
        p.get_pos().print_pos();
        p.jump();
        p.get_pos().print_pos();
    } while(p.get_pos().get_y() != 500);
}
