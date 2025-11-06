A simple interactive implementation of Conway’s Game of Life, built using C++ and SFML.
This program simulates the evolution of cells based on Conway’s famous rules with controls to toggle cells, start/pause the simulation, and reset the grid.
Interactive Grid: Click on cells to toggle them between alive and dead.

![Adobe Express - 2025-11-06 07-30-28](https://github.com/user-attachments/assets/2dc148ea-e359-40c7-9b47-4051b39247f6)

 * Simulation Control: Start or pause the Game of Life simulation at any time.

 * Reset Option: Clear the grid to start fresh.

 * Visual Feedback: Each cell is rendered with SFML for a smooth graphical experience.
Each cell follows these rules every generation:

Rules:
 1. Any live cell with 2 or 3 live neighbors survives.

 2. Any dead cell with exactly 3 live neighbors becomes alive.

 3. All other live cells die, and dead cells stay dead.
