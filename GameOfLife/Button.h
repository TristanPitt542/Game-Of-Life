#pragma once
#include <SFML/Graphics.hpp>

class Button
{
private:
	sf::Vector2f m_buttonSize = sf::Vector2f(100, 30);
	sf::Vector2f m_buttonPositon;
	std::string m_buttonText;
protected:
	sf::RectangleShape button;
	sf::Text text;
	sf::Font font;
	
public:
	sf::FloatRect buttonBounds = sf::FloatRect(m_buttonPositon.x - (m_buttonSize.x/2),m_buttonPositon.y - (m_buttonSize.y / 2),m_buttonSize.x, m_buttonSize.y);
	sf::Color m_buttonColor = sf::Color(220,220,220);

	void SetButtonText(std::string text) { m_buttonText = text; };

	Button(std::string text, sf::Vector2f position);
	void Render(sf::RenderWindow &window);
};

