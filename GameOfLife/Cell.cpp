#include "Cell.h"

Cell::Cell(sf::Vector2f position, bool isAlive) : m_cellPosition(position), m_isAlive(isAlive)
{
}

void Cell::Render(sf::RenderWindow &window)
{
	m_cellShape.setSize(m_cellSize);
	m_cellShape.setPosition(m_cellPosition);
	m_cellShape.setOutlineColor(sf::Color::Black);

	if (m_isAlive)
		m_cellShape.setFillColor(sf::Color::Black);
	else
		m_cellShape.setFillColor(sf::Color::White);

	window.draw(m_cellShape);
}
