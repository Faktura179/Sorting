#include "Button.h"

bool Button::_fontInit = false;
sf::Font Button::_font;
Button::Button(){
    if(!_fontInit){
        _font.loadFromFile("assets/arial.ttf");
        _fontInit=true;
    }
    _text.setFont(_font);
    _text.setString("Guzik");
    _text.setFillColor(sf::Color::White);
    _text.setCharacterSize(20);
    _text.setPosition(100,100);
    _text.setStyle(sf::Text::Bold);
    _rect.setPosition(95,95);
    _rect.setFillColor(sf::Color::Red);
    _rect.setSize(sf::Vector2f(150,30));
}
Button::Button(std::string txt, sf::Color textColor, sf::Vector2f position, sf::Color background){
    if(!_fontInit){
        _font.loadFromFile("assets/arial.ttf");
        _fontInit=true;
    }
    _text.setFont(_font);
    _text.setString(txt);
    _text.setFillColor(textColor);
    _text.setCharacterSize(20);
    _text.setPosition(position);
    _text.setStyle(sf::Text::Bold);
    _rect.setPosition(position);
    _rect.setFillColor(background);
    _rect.setSize(sf::Vector2f(150,30));
}
void Button::draw(sf::RenderTarget& target, sf::RenderStates states) const{ 
    target.draw(_rect, states);
    target.draw(_text, states);
}
Button::~Button(){

}