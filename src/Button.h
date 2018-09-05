#ifndef BUTTON_H
#define BUTTON_H

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>


class Button: public sf::Drawable{
    static bool _fontInit;
    static sf::Font _font;
    sf::Text _text;
    sf::RectangleShape _rect;
public:
    Button();
    Button(std::string, sf::Color, sf::Vector2f, sf::Color);
    void draw(sf::RenderTarget&, sf::RenderStates) const;
    ~Button();
};

#endif