#pragma once
#include <iostream>
#include"SFML/Graphics.hpp"

class Face
{
private:
	void componentInit(sf::Vector2f offset, std::vector<sf::CircleShape>& component, int count, float spacing);

public:
	sf::CircleShape face;
	std::vector<sf::CircleShape> leftEye;
	std::vector<sf::CircleShape> rightEye;
	std::vector<sf::CircleShape> mouth;

	Face();
	void render(sf::RenderWindow* window);
};

