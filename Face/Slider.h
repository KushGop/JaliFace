#pragma once
#include "Face.h" 
#include "SFML/Graphics.hpp"

class Slider
{
private:
	float value;
	std::vector<sf::CircleShape>& control;
	sf::Vector2f origin;

public:
	Slider(sf::Vector2f pos, std::vector<sf::CircleShape>& con);
	virtual ~Slider();

	sf::RectangleShape back;
	sf::RectangleShape handle;

	void setOriginCenter(sf::RectangleShape& shape);
	void updateHandle(float v);
	void update();
	void render(sf::RenderWindow* window);
};

