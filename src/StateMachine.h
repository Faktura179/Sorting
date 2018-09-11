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
    Machine(const Machine&) = delete;
    Machine& operator=(const Machine) = delete;
    void draw();
    void update();
    void setState(AbstractState*);
    void handleEvents();
    sf::RenderWindow* getWindow();
    bool windowIsOpen();
    void windowDisplay();
    ~Machine();
};
#endif