
//INCLUDES//---------------------------------
#include <SFML/Graphics.hpp>


#include "Critter.h"
//END INCLUDES//-----------------------------

int main()
{

	//GAME SET UP//--------------------------
	// Make a variable called gameWindow of type RenderWindow
	sf::RenderWindow window;
	window.create(sf::VideoMode::getDesktopMode(), "Button Masher",
		sf::Style::Titlebar | sf::Style::Close);

	// Timer functionality
	sf::Clock gameClock;

	//Create an Instance of Critter Class
	Critter walrus;
	
	//END GAME SETUP//-----------------------
	/////////////////////////////////////////
	//GAME LOOP//----------------------------
	while (window.isOpen())
	{
		//INPUT//----------------------------
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed) 
			{
				window.close();
			}//end if
				

		}//end while

		//END INPUT//------------------------
		/////////////////////////////////////
		//UPDATE//---------------------------


		//END UPDATE//-----------------------
		/////////////////////////////////////
		//DRAW//-----------------------------
		
		// clears window before playing
		window.clear();

		// draw everything
		walrus.Draw(window);

		// displays window
		window.display();

		//END DRAW//-------------------------

	}//end while 

	//END GAME LOOP//------------------------

	return 0;
}
