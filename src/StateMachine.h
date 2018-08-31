#ifndef StateMachine_H
#define StateMachine_H

#include "State.h"

class AbstractState;
class Machine{
private:
    AbstractState* _state;
    sf::RenderWindow _window;
public:
    Machine();
    void draw();
    void update();
    void setState(AbstractState*);
    void handleEvents();
    bool windowIsOpen();
    void windowDisplay();
    ~Machine();
};
#endif