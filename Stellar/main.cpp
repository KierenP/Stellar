#include <SFML/Graphics.hpp>
#include "GenShip.h"

void PollEvent();
void Render();
void Update();

sf::RenderWindow window(sf::VideoMode(1920, 1080), "Stellar");

GenShip MyShip;
sf::Texture ShipTexture;

int main()
{
	MyShip.SetParam(0, 1, 10, 100, 100, 0, 0);
	MyShip.Targetx = 200;
	MyShip.Targety = 150;

	ShipTexture.loadFromFile("Scout.png");
	MyShip.DrawObj = *(new sf::Sprite(ShipTexture));

	MyShip.DrawObj.setOrigin(ShipTexture.getSize().x / 2, ShipTexture.getSize().y / 2);

	while (window.isOpen())
	{
		PollEvent();
		Render();
		Update();
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
			MyShip.Targetx = sf::Mouse::getPosition().x;
			MyShip.Targety = sf::Mouse::getPosition().y;
		}
	}
}

void Update()
{
	MyShip.Update();
}

void Render()
{
	window.clear();
	window.draw(MyShip.DrawObj);
	window.display();
}
