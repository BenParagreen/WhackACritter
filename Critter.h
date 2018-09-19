#pragma once

//INCLUDES//---------------------------------
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
//END INCLUDES//-----------------------------


class Critter 
{
	//BEHAVIOUR//----------------------------
public:

	//Constuctor
	Critter();

	// Render the critter to the target
	void Draw(sf::RenderTarget& _target);

	// Process input on the Critter
	void Input(sf::Event _gameEvent);

	//Gets Pending Score
	int GetPendingScore();

	//Clears Pending Score
	void ClearPendingScore();


	//END BEHAVIOUR//------------------------
	/////////////////////////////////////////
	//DATA//---------------------------------

private:
	sf::Sprite m_sprite;
	sf::Texture m_texture;
	bool m_alive;
	sf::Sound m_deathsound;
	sf::SoundBuffer m_deathbuffer;
	int m_pendingScore;

	//END DATA//-----------------------------

}; // end critter class