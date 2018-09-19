//INCLUDES//---------------------------------
#include "Critter.h"

#include <cstdlib>

//END INCLUDES//-----------------------------

Critter::Critter()
// initialisation list
	:m_sprite(), m_texture(), m_alive(true), m_deathsound(), m_deathbuffer(), m_pendingScore(0), m_scoreValue(1)
{

	// Set up death sound
	m_deathbuffer.loadFromFile("audio/buttonclick.ogg");
	m_deathsound.setBuffer(m_deathbuffer);
}


void Critter::Draw(sf::RenderTarget& _target)
{
	if (m_alive)
	_target.draw(m_sprite);
}

void Critter::Input(sf::Event _gameEvent)
{
	if (m_alive)
	{
		if (_gameEvent.type == sf::Event::MouseButtonPressed)
		{
			// Did they click on this critter?
			if (m_sprite.getGlobalBounds().contains(_gameEvent.mouseButton.x, _gameEvent.mouseButton.y))
			{
				// We die 
				m_alive = false;
				m_deathsound.play();
				m_pendingScore += m_scoreValue;
			}
		}// end event if state
	}
}

int Critter::GetPendingScore()
{
	return m_pendingScore;
}

void Critter::ClearPendingScore()
{
	m_pendingScore = 0;
}

void Critter::Setup(std::string _textureFile, int _pointValue)
{
	// set up sprite
	m_texture.loadFromFile(_textureFile);
	m_sprite.setTexture(m_texture);
	m_sprite.setPosition(rand() % sf::VideoMode::getDesktopMode().width,
		rand() % sf::VideoMode::getDesktopMode().height);

	m_scoreValue = _pointValue;
}