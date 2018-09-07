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
void SplashState::handleEvents(sf::Event::EventType event, Machine* machine){

}
SplashState::~SplashState(){
    
}

MenuState::MenuState(){
    _rect.setFillColor(sf::Color::Magenta);
    _rect.setSize(sf::Vector2f(700,500));
    _rect.move(50,50);
}
void MenuState::draw(sf::RenderWindow* window){
    window->draw(_rect);
    window->draw(_btn);
}
void MenuState::update(Machine* machine){
    _btn.hover(machine->getWindow());
}
void MenuState::handleEvents(sf::Event::EventType event, Machine* machine){
    if(event == sf::Event::EventType::MouseButtonPressed){
        _btn.onClick(machine->getWindow(), [](){});
    }
}
MenuState::~MenuState(){

}