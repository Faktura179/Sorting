#ifndef State_H
#define State_H

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include "StateMachine.h"
class Machine;

class AbstractState{
public:
    void virtual draw(sf::RenderWindow*)=0;
    void virtual handleEvents(sf::Event::EventType, Machine*)=0;
    void virtual update(Machine*)=0;
    virtual ~AbstractState();
};

class SplashState : public AbstractState{
    sf::Clock _clock;
    sf::Font _font;
    sf::Text _txt;
public:
    SplashState();
    void draw(sf::RenderWindow*);
    void handleEvents(sf::Event::EventType, Machine*);
    void update(Machine*);
    ~SplashState();
};

class MenuState : public AbstractState{
    sf::RectangleShape _rect;
public:
    MenuState();
    void draw(sf::RenderWindow*);
    void handleEvents(sf::Event::EventType, Machine*);
    void update(Machine*);
    ~MenuState();
};
#endif