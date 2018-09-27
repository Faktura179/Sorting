// Sorting.cpp : Defines the entry point for the console application.
//

#include <SFML/Window.hpp>
#include <SFML/OpenGL.hpp>
#include <iostream>
#include "stdafx.h"

int main()
{
	//try{
		Machine screens;
		// load resources, initialize the OpenGL states, ...

		// run the main loop
		while (screens.windowIsOpen())
		{
			// handle events
			screens.handleEvents();

			//update
			screens.update();

			// draw...
			screens.draw();

			// end the current frame (internally swaps the front and back buffers)
			screens.windowDisplay();
		}
	//}catch(const std::exception &ex){
		//std::cerr<< ex.what()<<std::endl;
	//}
	// release resources...

	return 0;
}
