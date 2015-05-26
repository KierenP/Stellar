#pragma once
#include "Entity.h"
#include "SFML\Graphics.hpp"

class DrawableEntity :
	public Entity
{
public:
	DrawableEntity();
	virtual ~DrawableEntity();

	sf::Drawable* DrawObj;							//DrawObj can point to any child of sf::drawable including Shape, Sprite, Text and Vertex Aray 
	void Render(sf::RenderTarget& pTarget);			//pTarget is the current display window
};

