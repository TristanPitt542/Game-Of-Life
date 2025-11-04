#include <SFML/Graphics.hpp>
#include <iostream>
#include "Cell.h"


void main()
{
    sf::VideoMode desktop = sf::VideoMode::getDesktopMode();
    unsigned int kScreenWidth = 500;
    unsigned int kScreenHeight = 500;
    sf::Color backgroundColour = sf::Color(200, 200, 200);
    sf::RenderWindow window(sf::VideoMode(kScreenWidth, kScreenHeight), "Game Of Life");
    
    //FPS & VSync
    window.setFramerateLimit(60);
    window.setVerticalSyncEnabled(true);

    //cell size
    int cellSize = 10;

    //Fill Board with Cells
    std::vector<std::shared_ptr<Cell>> cells;
    for (int i = 0; i < 50; i++)
    {
        for (int j = 0; j < 50; j++)
        {
            cells.push_back(std::make_shared<Cell>(sf::Vector2f(i * cellSize, j * cellSize), false));
        }
    }

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();

            //Update Cell
            if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left)
            {
                sf::Vector2i MousePos = sf::Mouse::getPosition(window);

                for (auto cell : cells)
                {
                    if (cell->GetCellBounds().contains(sf::Vector2f(MousePos)))
                    {
                        cell->SetCellState();
                    }
                }
            }
        }

        


        //clear screen
        window.clear(backgroundColour);

        // Render all Cells
        for (auto cell : cells)
        {
            cell->Render(window);
        }
        window.display();

        //std::cout << "FPS: " << fps << "\n";
    }
    return;
}