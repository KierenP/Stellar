#include "DrawableSpriteEntity.h"


DrawableSpriteEntity::DrawableSpriteEntity()
{
}


DrawableSpriteEntity::~DrawableSpriteEntity()
{
}

void DrawableSpriteEntity::Render(sf::RenderTarget& pTarget)
{
	pTarget.draw(DrawObj);
}

