#include <iostream>
#include "StateMachine.h"


Machine::Machine(){
    _state = new SplashState();

    // create the window
	_window.create(sf::VideoMode(800, 600), "Sorting", sf::Style::Default, sf::ContextSettings(32));
	_window.setVerticalSyncEnabled(true);

	// activate the window
	_window.setActive(true);
}
void Machine::draw(){
    _state -> draw(&_window);
}
void Machine::update(){
    _state -> update(this);
}
void Machine::setState(AbstractState* state){
    _state = state;
}
void Machine::handleEvents(sf::Event::EventType event){
    _state->handleEvents(event, this);
}
Machine::~Machine(){
    delete _state;
}