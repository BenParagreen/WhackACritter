#pragma once

//INCLUDES//---------------------------------
#include <SFML/Graphics.hpp>

//END INCLUDES//-----------------------------


class Critter 
{
	//BEHAVIOUR//----------------------------
public:

	//Constuctor
	Critter();

	// Render the critter to the target
	void Draw(sf::RenderTarget& _target);


	//END BEHAVIOUR//------------------------
	/////////////////////////////////////////
	//DATA//---------------------------------

private:
	sf::Sprite m_sprite;
	sf::Texture m_texture;

	//END DATA//-----------------------------

}; // end critter class