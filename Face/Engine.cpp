#include "Engine.h"
#include "Face.h"

#pragma region Initializers
void Engine::initVariables() {
	window = nullptr;
	currentSlider == nullptr;
	face = new Face();
	mouseHeld = false;
	mouseClick = false;
}
void Engine::initWindow()
{
	videoMode = { 800,600 };
	window = new sf::RenderWindow(videoMode, "Face", sf::Style::Titlebar | sf::Style::Close);

	window->setFramerateLimit(60);
}
/// <summary>
/// stores all components of face
/// </summary>
void Engine::initSliders()
{
	sliders.push_back(new Slider({ 400.f,100.f }, face->leftEye));
	sliders.push_back(new Slider({ 500.f,100.f }, face->rightEye));
	sliders.push_back(new Slider({ 600.f,100.f }, face->mouth));
}
#pragma endregion

Engine::Engine()
{
	initVariables();
	initWindow();
	initSliders();
}

Engine::~Engine()
{
	delete window;
}

const bool Engine::getWindowIsOpen()
{
	return window->isOpen();
}
void Engine::pollEvents()
{
	while (window->pollEvent(e)) {
		if (e.type == sf::Event::Closed || e.key.code == sf::Keyboard::Escape)
			window->close();
	}
}


#pragma region Mouse Funtion
/// <summary>
/// updates mouse position relative to view
/// </summary>
void Engine::updateMouse()
{
	mouseClickCheck();
	mousePos = sf::Mouse::getPosition(*window);
	mousePosView = window->mapPixelToCoords(mousePos);
}
/// <summary>
/// Adds mouse click and holing functionallity
/// </summary>
void Engine::mouseClickCheck()
{
	if (!mouseClick && sf::Mouse::isButtonPressed(sf::Mouse::Left) && !mouseHeld) {	//first clicked
		mouseClick = true;
		mouseHeld = true;
	}
	else if (mouseClick && sf::Mouse::isButtonPressed(sf::Mouse::Left) && mouseHeld)//next frame check
	{
		mouseClick = false;
		mouseHeld = true;
	}
	else if (!sf::Mouse::isButtonPressed(sf::Mouse::Left))							//button released
	{
		mouseClick = false;
		mouseHeld = false;
	}
}
#pragma endregion

/// <summary>
/// Handles movement of sliders
/// </summary>
void Engine::updateSliders()
{
	if (mouseClick) {
		for (auto& slider : sliders) {
			if (slider->handle.getGlobalBounds().contains(mousePosView)) {
				currentSlider = slider;
			}
		}
	}
	else if (mouseHeld && currentSlider != nullptr) {
		currentSlider->updateHandle(mousePosView.y);
	}
	else {
		currentSlider = nullptr;
	}
}
void Engine::update()
{
	pollEvents();
	updateMouse();
	updateSliders();
	for (auto& slider : sliders) {
		slider->update();
	}
}
void Engine::render()
{
	window->clear(sf::Color::White);
	face->render(window);
	for (auto& slider : sliders) {
		slider->render(window);
	}

	window->display();
}
