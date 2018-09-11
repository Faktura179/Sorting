#include <iostream>
#include "State.h"


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
    _btn = new Button[7];
    _btn[0] = Button("Splash",sf::Vector2f(100,100));
    _btn[1] = Button("Bubble sort",sf::Vector2f(100,200));
    _btn[2] = Button("Merge sort",sf::Vector2f(100,300));
    _btn[3] = Button("Bucket sort",sf::Vector2f(100,400));
    _btn[4] = Button("Insertion sort",sf::Vector2f(100,500));
    _btn[5] = Button("Quick sort",sf::Vector2f(300,100));
    _btn[6] = Button("Exit",sf::Vector2f(700,500));
    _rect.setFillColor(sf::Color::Magenta);
    _rect.setSize(sf::Vector2f(700,500));
    _rect.move(50,50);
}
void MenuState::draw(sf::RenderWindow* window){
    window->draw(_rect);
    for(int i=0;i<7;i++){
        window->draw(_btn[i]);
    }

}
void MenuState::update(Machine* machine){
    for(int i=0;i<7;i++){
        _btn[i].hover(machine->getWindow());
    }
}
void MenuState::handleEvents(sf::Event event, Machine* machine){
    if(event.type == sf::Event::MouseButtonPressed){
        if(event.mouseButton.button==sf::Mouse::Left){
            _btn[0].onClick(machine, [](Machine* machine){machine->setState(new SplashState());});

            _btn[6].onClick(machine, [](Machine* machine){machine->getWindow()->close();});
        }
    }
}
MenuState::~MenuState(){
    delete[] _btn;
}