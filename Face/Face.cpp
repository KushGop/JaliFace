#include "Face.h"

/// <summary>
/// Initializes dots in component
/// </summary>
/// <param name="offset">offset from origin</param>
/// <param name="component">component reference</param>
/// <param name="count">number of dots</param>
/// <param name="spacing">spacing between dots</param>
void Face::componentInit(sf::Vector2f offset, std::vector<sf::CircleShape>& component, int count, float spacing)
{
	for (int i = 0;i < count;i++) {
		sf::CircleShape point;
		point.setFillColor(sf::Color::Black);
		point.setRadius(10.f);
		point.setOrigin({ (i * spacing),0 });
		point.setPosition({ offset.x - 10.f, offset.y - 10.f });
		component.push_back(point);
	}
}

/// <summary>
/// Sets the face background and initializes components
/// </summary>
Face::Face()
{
	face.setFillColor(sf::Color::Yellow);
	face.setRadius(150.f);

	sf::Vector2f origin = { 150.f,150.f };
	float spacing = 5.f;
	int count = 11;
	componentInit({ origin.x - 75.f,origin.y - 50.f }, leftEye, count, -spacing);
	componentInit({ origin.x + 75.f,origin.y - 50.f }, rightEye, count, spacing);
	count = 21;
	componentInit({ origin.x + ((count - 1) * (spacing / 2)),origin.y + 50.f }, mouth, count, spacing);
}

Face::~Face()
{
	leftEye.clear();
	rightEye.clear();
	mouth.clear();
}

/// <summary>
/// renders all components
/// </summary>
/// <param name="window"></param>
void Face::render(sf::RenderWindow* window) {
	window->draw(face);
	for (auto& point : leftEye)
		window->draw(point);
	for (auto& point : rightEye)
		window->draw(point);
	for (auto& point : mouth)
		window->draw(point);

}
