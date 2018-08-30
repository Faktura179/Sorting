// Sorting.cpp : Defines the entry point for the console application.
//

#include <SFML/Window.hpp>
#include <SFML/OpenGL.hpp>
#include "stdafx.h"

int main()
{
	Machine screens;
	// load resources, initialize the OpenGL states, ...

	// run the main loop
	bool running = true;
	while (running)
	{
		// handle events
		sf::Event event;
		while (screens._window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				// end the program
				running = false;
			}
			else if (event.type == sf::Event::Resized)
			{
				// adjust the viewport when the window is resized
				glViewport(0, 0, event.size.width, event.size.height);
			}
			screens.handleEvents(event.type);
		}
		//update
		screens.update();
		// clear the buffers
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		// draw...
		screens.draw();
		// end the current frame (internally swaps the front and back buffers)
		screens._window.display();
	}

	// release resources...

	return 0;
}
