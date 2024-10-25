#include <iostream>
#include "Scientist.hpp"
#include "Goal.hpp"
#include "Experiment.hpp"

int main() {
    int gridWidth = 5, gridHeight = 5;

    Scientist player(gridWidth, gridHeight);

    Goal goal(gridWidth, gridHeight);

    Experiment experiment1(1, 0, gridWidth, gridHeight);
    Experiment experiment2(0, 2, gridWidth, gridHeight);
    Experiment experiment3(2, 2, gridWidth, gridHeight);

    player.move(1, 0);
    std::cout << "Scientist moved to: (" << player.getCoordinates().first << ", " << player.getCoordinates().second << ")\n";
    if (experiment1.interact(&player)) {
        std::cout << "Experiment 1 complete.\n";
    }

    player.move(-1, 2);
    std::cout << "Scientist moved to: (" << player.getCoordinates().first << ", " << player.getCoordinates().second << ")\n";
    if (experiment2.interact(&player)) {
        std::cout << "Experiment 2 complete.\n";
    }

    player.move(2, 0); 
    std::cout << "Scientist moved to: (" << player.getCoordinates().first << ", " << player.getCoordinates().second << ")\n";
    player.move(2, 2);
    std::cout << "Scientist moved to: (" << player.getCoordinates().first << ", " << player.getCoordinates().second << ")\n";
    player.move(0, 2);
    std::cout << "Scientist moved to: (" << player.getCoordinates().first << ", " << player.getCoordinates().second << ")\n";

    std::cout << "Goal coordinates: (" << goal.getCoordinates().first << ", " << goal.getCoordinates().second << ")\n";

    if (goal.interact(&player)) {
        std::cout << "Goal reached! You win!\n";
    } else {
        std::cout << "Goal not reached.\n";
    }

    return 0;
}
