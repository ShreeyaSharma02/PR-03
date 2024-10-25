#ifndef GAME_HPP
#define GAME_HPP

#include <iostream>
#include <vector>
#include <utility> 
#include "Scientist.hpp"
#include "Goal.hpp"
#include "Experiment.hpp"
#include "Helper.hpp" 


enum GameState { WIN, LOSE, PLAYING };

class Game {
private:
    int width, height;                    
    Scientist player;                     
    Goal goal;                            
    std::vector<Experiment> experiments;  
    GameState state;                      

public:
    Game(int width, int height, std::vector<std::pair<int, int>> experimentCoordinates)
        : width(width), height(height), player(Scientist(width, height)), goal(Goal(width, height)), state(PLAYING) {

        for (auto& coord : experimentCoordinates) {
            if (!(coord.first == 0 && coord.second == 0) && !(coord.first == width - 1 && coord.second == height - 1)) {
                experiments.emplace_back(coord.first, coord.second, width, height);
            }
        }
    }

    bool displayState() {
        switch (state) {
            case WIN:
                std::cout << "You win!" << std::endl;
                return true;
            case LOSE:
                std::cout << "You lose :(" << std::endl;
                return true;
            case PLAYING:
                std::cout << "Game on" << std::endl;
                return false;
        }
        return false; 
    }

    void movePlayer(int dx, int dy) {
        if (state == PLAYING) {
            if (player.move(dx, dy)) {
                for (auto& experiment : experiments) {
                    if (Helper::manhattanDistance(experiment.getCoordinates(), player.getCoordinates()) == 0) {
                        experiment.interact(&player); 
                    }
                }

                if (goal.interact(&player)) {
                    state = WIN;  
                } else if (player.getExperimentCount() > 3) {
                    state = LOSE;  
                }
            }
        }
    }

    void printGrid() {

        std::vector<std::vector<char>> grid(height, std::vector<char>(width, '_'));

        grid[goal.getCoordinates().second][goal.getCoordinates().first] = 'G';

        for (auto& experiment : experiments) {
            grid[experiment.getCoordinates().second][experiment.getCoordinates().first] = 'E';
        }

        grid[player.getCoordinates().second][player.getCoordinates().first] = 'P';

        for (const auto& row : grid) {
            for (char cell : row) {
                std::cout << cell;
            }
            std::cout << std::endl;
        }
    }
};

#endif
