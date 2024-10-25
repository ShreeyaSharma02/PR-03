#include "Game.hpp"

int main() {
    std::vector<std::pair<int, int>> experimentCoordinates = {{3, 0}, {0, 2}, {2, 2}};

    Game game(5, 5, experimentCoordinates);

    game.displayState();

    game.printGrid();

    game.movePlayer(1, 0); 
    game.printGrid();

    game.movePlayer(0, 2); 
    game.printGrid();

    game.movePlayer(-1, 0); 
    game.printGrid();

    game.movePlayer(4, 2);
    game.printGrid();

    game.displayState();

    return 0;
}
