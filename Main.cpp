
//INCLUDES//---------------------------------
#include <SFML/Graphics.hpp>
#include <cstdlib>
#include <ctime>
#include <string>

#include "Critter.h"
//END INCLUDES//-----------------------------

int main()
{

	//GAME SET UP//--------------------------
	// Make a variable called gameWindow of type RenderWindow
	sf::RenderWindow window;
	window.create(sf::VideoMode::getDesktopMode(), "Whack A Critter",
		sf::Style::Titlebar | sf::Style::Close);

	// Timer functionality
	sf::Clock gameClock;

	// Seed random number generator
	srand(time(NULL));

	//Create an Instance of Critter Class
	Critter walrus;
	walrus.Setup("graphics/walrus.png", 10);
	Critter whale;
	whale.Setup("graphics/whale.png", 5);


	//Game Font
	sf::Font gameFont;
	gameFont.loadFromFile("fonts/mainfont.ttf");

	// Score tracking
	int score = 0;
	sf::Text scoreText;
	scoreText.setFont(gameFont);
	scoreText.setString("Score: " + std::to_string(score));
	scoreText.setCharacterSize(50);
	scoreText.setFillColor(sf::Color::White);
	scoreText.setPosition(50, 50);
	
	//END GAME SETUP//-----------------------
	/////////////////////////////////////////
	//GAME LOOP//----------------------------
	while (window.isOpen())
	{
		//INPUT//----------------------------
		sf::Event event;
		while (window.pollEvent(event))
		{
			//Process input on Critter
			walrus.Input(event);
			whale.Input(event);

			if (event.type == sf::Event::Closed) 
			{
				window.close();
			}//end if
				

		}//end while

		//END INPUT//------------------------
		/////////////////////////////////////
		//UPDATE//---------------------------
		sf::Time frameTime = gameClock.restart();

		score += walrus.GetPendingScore();
	    scoreText.setString("Score: " + std::to_string(score));
		walrus.ClearPendingScore();
		whale.ClearPendingScore();

		//END UPDATE//-----------------------
		/////////////////////////////////////
		//DRAW//-----------------------------
		
		// clears window before playing
		window.clear();

		// draw everything
		walrus.Draw(window);
		whale.Draw(window);
		window.draw(scoreText);

		// displays window
		window.display();

		//END DRAW//-------------------------

	}//end while 

	//END GAME LOOP//------------------------

	return 0;
}
