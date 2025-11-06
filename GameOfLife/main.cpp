#include <SFML/Graphics.hpp>
#include <iostream>
#include "Cell.h"
#include "Button.h"
#include <random>


inline int Index(int x, int y, int width)
{
    return y * width + x;
}

int CountAliveNeigbors(const std::vector<Cell*>& grid, int x, int y, int width, int height)
{
    int neighborAlive = 0;

    for (int dx = -1; dx <= 1; dx++)
    {
        for (int dy = -1; dy <= 1; dy++)
        {
            if (dx == 0 && dy == 0)
                continue;

            int nx = dx + x;
            int ny = dy + y;

            if (nx >= 0 && nx < width && ny >= 0 && ny < height)
                if (grid[Index(nx, ny, width)]->GetCellState())
                    neighborAlive++;
        }
    }
    return neighborAlive;
}

void UpdateGrid(std::vector<Cell*>& grid, int width, int height)
{
    // Copy current state to compare against while updating
    std::vector<bool> nextStates(width * height);

    for (int y = 0; y < height; ++y)
    {
        for (int x = 0; x < width; ++x)
        {
            int aliveNeighbors = CountAliveNeigbors(grid, x, y, width, height);
            bool alive = grid[Index(x, y, width)]->GetCellState();

            bool nextAlive = (alive && (aliveNeighbors == 2 || aliveNeighbors == 3)) ||
                (!alive && aliveNeighbors == 3);

            nextStates[Index(x, y, width)] = nextAlive;
        }
    }

    // Apply next states
    for (int i = 0; i < width * height; ++i)
    {
        grid[i]->SetCellState(nextStates[i]);
    }
}

int main()
{
    unsigned int kScreenWidth = 500;
    unsigned int kScreenHeight = 500;

    bool start = false;
    int cellSize = 10;
    int width = kScreenWidth / cellSize;
    int height = kScreenHeight / cellSize;
    int offsetUI = 50;

    sf::RenderWindow window(sf::VideoMode(kScreenWidth, kScreenHeight + offsetUI), "Game Of Life");
    window.setFramerateLimit(60);

    sf::Color backgroundColour(200, 200, 200);


    //UI 
    std::vector<std::shared_ptr<Button>> buttons;
    auto startButton = std::make_shared<Button>("Start", sf::Vector2f(kScreenWidth / 2, 25));
    auto resetButton = std::make_shared<Button>("Reset", sf::Vector2f(kScreenWidth / 1.2, 25));
    buttons.push_back(startButton);
    buttons.push_back(resetButton);

    // Create grid of Cell pointers
    std::vector<Cell*> grid;
    grid.reserve(width * height);

    for (int y = 0; y < height; y++)
    {
        for (int x = 0; x < width; x++)
        {
            grid.push_back(new Cell(sf::Vector2f(x * cellSize, y * cellSize + offsetUI), false, cellSize));
        }
    }

    // Clock to control update speed
    sf::Clock clock;
    float updateInterval = 0.15f;

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();

            // Handle mouse click to toggle cells
            if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left)
            {
                sf::Vector2f worldPos = window.mapPixelToCoords(sf::Mouse::getPosition(window));
                for (Cell* cell : grid)
                {
                    if (cell->GetCellBounds().contains(worldPos))
                    {
                        cell->SetCellState(!cell->GetCellState());
                        break;
                    }
                }
                if (startButton->buttonBounds.contains(worldPos))
                {
                    start = !start;
                    if (start)
                        startButton->SetButtonText("Stop");
                    else
                        startButton->SetButtonText("Start");
                    break;
                }
                if (resetButton->buttonBounds.contains(worldPos))
                {
                    start = false;
                    for (Cell* cell : grid)
                        cell->SetCellState(false);
                    break;
                }
            }         
        }

        // Start simulation on space key
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
            start = true;

        // Update grid every 0.15 seconds if started
        if (start && clock.getElapsedTime().asSeconds() > updateInterval)
        {
            UpdateGrid(grid, width, height);
            clock.restart();
        }

        // Draw
        window.clear(backgroundColour);

        for (Cell* cell : grid)
        {
            cell->Render(window);
        }

        for (auto button: buttons)
        {
            button->Render(window);
        }

        window.display();
    }

    // Cleanup
    for (Cell* cell : grid)
        delete cell;

    return 0;
}