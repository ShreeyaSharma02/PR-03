#ifndef EXPERIMENT_HPP
#define EXPERIMENT_HPP

#include "Interactable.hpp"
#include "Scientist.hpp"
#include "Helper.hpp"

class Experiment : public Interactable {
public:

    Experiment(int x, int y, int width, int height)
        : Interactable(x, y, width, height) {}

    bool interact(Scientist* player) override {
        if (Helper::manhattanDistance(getCoordinates(), player->getCoordinates()) == 0) {
            if (player->getExperimentCount() > 3) {
                return false; 
            }
            player->runExperiment();
            return true;
        }
        return false;
    }

    InteractableType getType() const override {
        return EXPERIMENT;
    }
};

#endif
