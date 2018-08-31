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
	while (screens.windowIsOpen())
	{
		// handle events
		screens.handleEvents();

		//update
		screens.update();

		// clear the buffers
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		// draw...
		screens.draw();

		// end the current frame (internally swaps the front and back buffers)
		screens.windowDisplay();
	}

	// release resources...

	return 0;
}
