#pragma once
#include <SFML/Graphics.hpp>

class Cell
{
private:
	//Render
	sf::RectangleShape m_cellShape;
	sf::Vector2f m_cellPosition;
	sf::Vector2f m_cellSize = sf::Vector2f(10,10);
	bool m_isAlive = false;

public:
	Cell(sf::Vector2f position, bool isAlive);

	void Render(sf::RenderWindow &window);

	sf::Vector2f GetCellPostition() const { return m_cellPosition; };
	sf::FloatRect GetCellBounds() { return m_cellShape.getGlobalBounds(); }
	bool GetCellState() { return m_isAlive; };
	void SetCellState() { m_isAlive = !m_isAlive; };
};

