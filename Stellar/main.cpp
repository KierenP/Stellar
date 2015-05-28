#include <SFML/Graphics.hpp>
#include "GenShip.h"

void PollEvent();
void Render();
void Update(float pDeltaTime);

sf::RenderWindow window(sf::VideoMode(1920, 1080), "Stellar");

GenShip MyShip;
sf::Texture ShipTexture;

sf::Clock GameClock;
float DeltaTime = 0;

int main()
{
	MyShip.SetParam(1, 360, 100, 100, 0, 0);

	ShipTexture.loadFromFile("Scout.png");
	MyShip.DrawObj = *(new sf::Sprite(ShipTexture));

	MyShip.DrawObj.setOrigin(ShipTexture.getSize().x / 2, ShipTexture.getSize().y / 2);

	while (window.isOpen())
	{
		DeltaTime = GameClock.restart().asSeconds();
		PollEvent();
		Render();
		Update(DeltaTime);
	}
}

void PollEvent()
{
	sf::Event event;
	while (window.pollEvent(event))
	{
		if (event.type == sf::Event::Closed)
			window.close();
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
		{
			MyShip.SetTarget(sf::Mouse::getPosition().x, sf::Mouse::getPosition().y);
		}
	}
}

void Update(float pDeltaTime)
{
	MyShip.Update(pDeltaTime);
}

void Render()
{
	window.clear();
	window.draw(MyShip.DrawObj);
	window.display();
}
