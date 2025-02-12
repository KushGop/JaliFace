#pragma once

#include <iostream>;
#include "Face.h"
#include "Slider.h"
#include "SFML/Graphics.hpp"
#include "SFML/Window.hpp"
#include "SFML/System.hpp"


class Engine
{
private:
	//Window
	sf::RenderWindow* window;
	sf::VideoMode videoMode;
	sf::Event e;

	//Mouse
	sf::Vector2i mousePos;
	sf::Vector2f mousePosView;
	bool mouseHeld;
	bool mouseClick;

	std::vector<Slider*> sliders;
	Slider* currentSlider;
	Face* face;
	void initVariables();
	void initWindow();

	void initSliders();

public:
	//Accessors
	const bool getWindowIsOpen();

	void pollEvents();

	//Structors
	Engine();
	virtual ~Engine();

	//Updates
	void updateMouse();
	void mouseClickCheck();
	void updateSliders();
	void update();

	//Renders
	void render();
};

