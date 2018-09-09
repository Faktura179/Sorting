#include <iostream>
#include "State.h"


inline AbstractState::~AbstractState(){}

SplashState::SplashState(){
    if(!_font.loadFromFile("assets/arial.ttf")){
        std::cerr << "Error while loading a font\n";
    }
    _txt.setFont(_font);
    _txt.setString("Sorting!");
    _txt.setFillColor(sf::Color::White);
    _txt.setCharacterSize(30);
    _txt.setPosition(350,260);
    _txt.setStyle(sf::Text::Bold);
}
void SplashState::draw(sf::RenderWindow* window){
    window->draw(_txt);
}
void SplashState::update(Machine* machine){
    if(_clock.getElapsedTime().asSeconds() > 3.f){
        machine->setState(new MenuState());
    }
}
void SplashState::handleEvents(sf::Event event, Machine* machine){

}
SplashState::~SplashState(){
    
}

MenuState::MenuState(){
    _btn = new Button();
    _rect.setFillColor(sf::Color::Magenta);
    _rect.setSize(sf::Vector2f(700,500));
    _rect.move(50,50);
}
void MenuState::draw(sf::RenderWindow* window){
    window->draw(_rect);
    window->draw(*_btn);
}
void MenuState::update(Machine* machine){
    _btn->hover(machine->getWindow());
}
void MenuState::handleEvents(sf::Event event, Machine* machine){
    if(event.type == sf::Event::MouseButtonPressed){
        if(event.mouseButton.button==sf::Mouse::Left)
            _btn->onClick(machine, [](Machine* machine){machine->setState(new SplashState());});
    }
}
MenuState::~MenuState(){
    delete _btn;
}