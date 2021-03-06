#include <iostream>
#include <SFML/OpenGL.hpp>
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
	// clear the buffers
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    _state -> draw(&_window);
}
void Machine::update(){
    _state -> update(this);
}
void Machine::setState(AbstractState* state){
	delete _state;
    _state = state;
}
void Machine::handleEvents(){
    sf::Event event;
    while (_window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				// end the program
				_window.close();
			}
			else if (event.type == sf::Event::Resized)
			{
				// adjust the viewport when the window is resized
				glViewport(0, 0, event.size.width, event.size.height);
			}
            _state->handleEvents(event, this);
        }
}
bool Machine::windowIsOpen(){
    return _window.isOpen();
}
void Machine::windowDisplay(){
    _window.display();
}
sf::RenderWindow* Machine::getWindow(){
	return &_window;
}
Machine::~Machine(){
    delete _state;
}