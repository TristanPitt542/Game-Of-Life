#include <SFML/Graphics.hpp>
#include <iostream>
#include "Cell.h"
#include "Button.h"


void main()
{
    sf::VideoMode desktop = sf::VideoMode::getDesktopMode();
    unsigned int kScreenWidth = 500;
    unsigned int kScreenHeight = 550;
    sf::Color backgroundColour = sf::Color(200, 200, 200);
    sf::RenderWindow window(sf::VideoMode(kScreenWidth, kScreenHeight), "Game Of Life");
    
    bool start = false;

    //FPS & VSync
    window.setFramerateLimit(60);
    window.setVerticalSyncEnabled(true);

    //cell size
    int cellSize = 10;

    //UI
    std::vector<std::shared_ptr<Button>> buttons;
    auto startButton = std::make_shared<Button>("Start", sf::Vector2f(kScreenWidth / 2, 25));
    auto resetButton = std::make_shared<Button>("Reset", sf::Vector2f(kScreenWidth / 1.2, 25));
    buttons.push_back(startButton);
    buttons.push_back(resetButton);

    //Fill Board with Cells
    std::vector<std::shared_ptr<Cell>> cells;
    for (int i = 0; i < 50; i++)
    {
        for (int j = 0; j < 50; j++)
        {
            cells.push_back(std::make_shared<Cell>(sf::Vector2f(i * cellSize, j * cellSize + 50), false, cellSize));
        }
    }

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        //Update Cell
        if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
        {
            sf::Vector2i MousePos = sf::Mouse::getPosition(window);

            for (auto cell : cells)
            {
                if (cell->GetCellBounds().contains(sf::Vector2f(MousePos)))
                {
                    cell->SetCellState(true);
                }
            }
        }
        if (sf::Mouse::isButtonPressed(sf::Mouse::Right))
        {
            sf::Vector2i MousePos = sf::Mouse::getPosition(window);

            for (auto cell : cells)
            {
                if (cell->GetCellBounds().contains(sf::Vector2f(MousePos)))
                {
                    cell->SetCellState(false);
                }
            }
        }

        if (startButton.get()->buttonBounds.contains(sf::Vector2f(sf::Mouse::getPosition(window))))
        {
            startButton.get()->m_buttonColor = sf::Color(150, 150, 150);
        }
        else
        {
            startButton.get()->m_buttonColor = sf::Color(220, 220, 220);
        }

        if (start)
        {
            for (auto cell : cells)
            {
                cell->CheckNeighbors(cells);
            }
        }

        // Clear screen
        window.clear(backgroundColour);

        // Render all Cells
        for (auto cell : cells)
        {
            cell->Render(window);
        }

        // Render all Buttons
        for (auto button : buttons)
        {
            button->Render(window);
        }

        window.display();
        //std::cout << "FPS: " << fps << "\n";
    }
    return;
}