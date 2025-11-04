#include "Cell.h"

Cell::Cell(sf::Vector2f position, bool isAlive, int cellSize) : m_cellPosition(position), m_isAlive(isAlive), m_cellSize(sf::Vector2f(cellSize, cellSize))
{
}

void Cell::CheckNeighbors(std::vector<std::shared_ptr<Cell>> cells)
{
	for (auto cell : cells)
	{

	}
}

void Cell::Render(sf::RenderWindow &window)
{
	m_cellShape.setSize(m_cellSize);
	m_cellShape.setPosition(m_cellPosition);
	m_cellShape.setOutlineThickness(1.0f);
	m_cellShape.setOutlineColor(sf::Color(200,200,200));

	if (m_isAlive)
		m_cellShape.setFillColor(sf::Color::Black);
	else
		m_cellShape.setFillColor(sf::Color::White);

	window.draw(m_cellShape);
}
