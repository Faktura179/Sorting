#ifndef State_H
#define State_H

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include "StateMachine.h"
#include "Button.h"
#include "SortingStates.h"
#include <random>
#include <functional>
class Machine;
class Button;


class AbstractState{
public:
    //AbstractState();  //unnecessary constructor (does nothing)
    void virtual draw(sf::RenderWindow*)=0;
    void virtual handleEvents(sf::Event, Machine*)=0;
    void virtual update(Machine*)=0;
    //~AbstractState(); //same here
};

class SplashState : public AbstractState{
    sf::Clock _clock;
    sf::Font _font;
    sf::Text _txt;
public:
    SplashState();
    void draw(sf::RenderWindow*);
    void handleEvents(sf::Event, Machine*);
    void update(Machine*);
    ~SplashState();
};

class MenuState : public AbstractState{
    sf::RectangleShape _rect;
    Button* _btn;
public:
    MenuState();
    MenuState(const MenuState&) = delete;
    MenuState& operator=(const MenuState) = delete;
    void draw(sf::RenderWindow*);
    void handleEvents(sf::Event, Machine*);
    void update(Machine*);
    ~MenuState();
};

class BubbleState : public AbstractState{
    sf::RectangleShape* _rect;
    Button* _btn;
    sf::Clock _clock;
public:
    BubbleState();
    void draw(sf::RenderWindow*);
    void handleEvents(sf::Event, Machine*);
    void update(Machine*);
    ~BubbleState();
};

#endif