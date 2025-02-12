#include "Slider.h"
/// <summary>
/// Sets variables and handle to zero
/// </summary>
/// <param name="pos"></param>
/// <param name="control"></param>

Slider::Slider(sf::Vector2f pos, std::vector<sf::CircleShape>& con) :control(con)
{
	value = 0;
	origin = pos;
	back.setSize({ 10.f,50.f });
	back.setFillColor(sf::Color::Green);
	setOriginCenter(back);
	back.setPosition(pos);
	handle.setSize({ 30.f,10.f });
	handle.setFillColor(sf::Color::Blue);
	setOriginCenter(handle);
	handle.setPosition(pos);
}

Slider::~Slider()
{
	control.clear();
}

/// <summary>
/// Sets shape origin to center
/// </summary>
/// <param name="shape"></param>
void Slider::setOriginCenter(sf::RectangleShape& shape) {
	shape.setOrigin({ shape.getSize().x / 2.f,shape.getSize().y / 2.f });
}

/// <summary>
/// Sets handle position
/// </summary>
/// <param name="posY"></param>
void Slider::updateHandle(float posY) {
	if (posY > (back.getSize().y / 2) + back.getPosition().y) {				//upper limit
		handle.setPosition(origin.x, origin.y + (back.getSize().y / 2));
	}
	else if (posY < (-back.getSize().y / 2) + back.getPosition().y) {		//lower limit
		handle.setPosition(origin.x, origin.y - (back.getSize().y / 2));
	}
	else {																	//default
		handle.setPosition(origin.x, posY);
	}
}

/// <summary>
/// Updates all points it controls
/// </summary>
void Slider::update() {
	//only update on change
	if (value != (back.getPosition().y - handle.getPosition().y) / (back.getSize().y / 2)) {
		//set value based on handleposition relative to back position
		value = (back.getPosition().y - handle.getPosition().y) / (back.getSize().y / 2);
		int size = control.size();
		float mag = 0;
		float scale = size;
		for (int i = 0;i < size - 1; i++) {
			//use oval function to determine y factor
			control[i].setPosition(control[i].getPosition().x, control[0].getPosition().y + (value * sqrt(1 - pow(mag - 1, 2)) * scale));
			mag += 2.f / (size - 1);
		}
	}
}

void Slider::render(sf::RenderWindow* window) {
	window->draw(back);
	window->draw(handle);
}