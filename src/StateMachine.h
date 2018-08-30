#ifndef StateMachine_H
#define StateMachine_H

#include "State.h"

class AbstractState;
class Machine{
private:
    AbstractState* _state;

public:
    sf::RenderWindow _window;
    Machine();
    void draw();
    void update();
    void setState(AbstractState*);
    void handleEvents(sf::Event::EventType);
    ~Machine();
};
#endif