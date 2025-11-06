#pragma once
#include <SFML/Graphics.hpp>

class Cell
{
private:
	//Render
	sf::RectangleShape m_cellShape;
	sf::Vector2f m_cellPosition;
	sf::Vector2f m_cellSize;
	bool m_isAlive = false;

public:
	Cell(sf::Vector2f position, bool isAlive, int cellSize);

	void Render(sf::RenderWindow &window);

	sf::Vector2f GetCellPosition() const { return m_cellPosition; };
	sf::FloatRect GetCellBounds() { return m_cellShape.getGlobalBounds(); }
	bool GetCellState() { return m_isAlive; };
	void SetCellState(bool state) { m_isAlive = state; };
};

