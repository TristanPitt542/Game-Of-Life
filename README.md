A simple interactive implementation of Conway’s Game of Life, built using C++ and SFML.
This program simulates the evolution of cells based on Conway’s famous rules with controls to toggle cells, start/pause the simulation, and reset the grid.
Interactive Grid: Click on cells to toggle them between alive and dead.

<img width="1080" height="720" alt="GameOfLife" src="https://github.com/user-attachments/assets/aa0f2539-9209-4a47-889b-28ce25262cc2" />


 * Simulation Control: Start or pause the Game of Life simulation at any time.

 * Reset Option: Clear the grid to start fresh.

 * Visual Feedback: Each cell is rendered with SFML for a smooth graphical experience.
Each cell follows these rules every generation:

Rules:
 1. Any live cell with 2 or 3 live neighbors survives.

 2. Any dead cell with exactly 3 live neighbors becomes alive.

 3. All other live cells die, and dead cells stay dead.
