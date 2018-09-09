#ifndef BUTTON_H
#define BUTTON_H

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <functional>
#include "StateMachine.h"
class Machine;


class Button: public sf::Drawable{
    static bool _fontInit;
    static sf::Font _font;
    sf::Text _text;
    sf::RectangleShape _rect;
    sf::Color _fill;
public:
    Button();
    void draw(sf::RenderTarget&, sf::RenderStates) const;
    void onClick(Machine*, std::function<void(Machine*)>);
    void hover(sf::RenderWindow*);
    ~Button();
};

#endif