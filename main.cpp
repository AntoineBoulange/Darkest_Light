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
    //test_sfml();
    player p;
    /*while(!p.is_dead()){
        p.hunger_decrease();
    }
    p.get_pos().print_pos();*/

    //TEST DISPLAY
    sf::RenderWindow window(sf::VideoMode(1200, 500), "SFML works");
    sf::RectangleShape shape(sf::Vector2f(p.get_width(), p.get_height()));
    shape.setFillColor(sf::Color::Red);
    p.set_pos(50, 0);
    p.set_mvt(10, 10);
    shape.setPosition(p.get_pos().get_x(), p.get_pos().get_y());
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        //p.jump();
        p.move();
        p.get_pos().print_pos();
        shape.setPosition(p.get_pos().get_x(), p.get_pos().get_y());
        window.clear();
        window.draw(shape);
        window.display();
        if(p.get_pos().get_x() == 1150)
            p.set_mvt(-10, -10);
        else if(p.get_pos().get_x() == 0)
            p.set_mvt(10, 10);
    }

    /*
    // TEST JUMP
    p.set_pos(50, 500);
    p.set_mvt(10, 10);
    do {
        p.jump();
        p.get_pos().print_pos();
        p.jump();
        p.get_pos().print_pos();
    } while(p.get_pos().get_y() != 500);*/
}
