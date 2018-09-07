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
    _rect.setPosition(_text.getPosition());
    _fill=sf::Color(0,0,0);
    _rect.setFillColor(_fill);
    _rect.setSize(sf::Vector2f(_text.getGlobalBounds().width,_text.getGlobalBounds().height + 10));
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
    _rect.setSize(sf::Vector2f(_text.getGlobalBounds().width,_text.getGlobalBounds().height + 10));
}
void Button::draw(sf::RenderTarget& target, sf::RenderStates states) const{ 
    target.draw(_rect, states);
    target.draw(_text, states);
}
void Button::onClick(sf::RenderWindow* window, std::function<void()> function){
    if(_rect.getGlobalBounds().contains(sf::Mouse::getPosition(*window).x,sf::Mouse::getPosition(*window).y)){
        function();
    }
}
void Button::hover(sf::RenderWindow* window){
    _rect.setFillColor(_fill);
    if(_rect.getGlobalBounds().contains(sf::Mouse::getPosition(*window).x,sf::Mouse::getPosition(*window).y)){
        _rect.setFillColor(sf::Color(0,255,0));
    }
}
Button::~Button(){

}