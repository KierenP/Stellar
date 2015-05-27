#include "DrawableEntity.h"


DrawableEntity::DrawableEntity()
{
}


DrawableEntity::~DrawableEntity()
{
}

void DrawableEntity::Render(sf::RenderTarget& pTarget)
{
	pTarget.draw(*DrawObj);
}

