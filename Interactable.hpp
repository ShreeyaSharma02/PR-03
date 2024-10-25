#ifndef INTERACTABLE_HPP
#define INTERACTABLE_HPP

#include "GridItem.hpp"

enum InteractableType { GOAL, EXPERIMENT };

class Scientist; 

class Interactable : public GridItem {
private:
    static int activeInteractableCount;

public:

    Interactable(int x, int y, int width, int height)
        : GridItem(x, y, width, height) {
        ++activeInteractableCount;
    }


    Interactable() : GridItem(0, 0, 0, 0) {
        ++activeInteractableCount;
    }

    virtual ~Interactable() {
        --activeInteractableCount;
    }

    static int getActiveInteractableCount() {
        return activeInteractableCount;
    }

    virtual bool interact(Scientist* player) = 0;
    virtual InteractableType getType() const = 0;
};

int Interactable::activeInteractableCount = 0;

#endif 
