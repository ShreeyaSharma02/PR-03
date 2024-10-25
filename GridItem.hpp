#ifndef GRIDITEM_HPP
#define GRIDITEM_HPP

#include <utility> 

class GridItem {
private:
    int x, y;       
    int width, height;  
    static int activeGridItemCount;  

public:

    GridItem(int x, int y, int width, int height) 
        : x(x), y(y), width(width), height(height) {
        ++activeGridItemCount; 
    }

    GridItem() : x(0), y(0), width(0), height(0) {
        ++activeGridItemCount; 
    }

    virtual ~GridItem() {
        --activeGridItemCount; 
    }

    void setCoordinates(int newX, int newY) {
        x = newX;
        y = newY;
    }

    std::pair<int, int> getCoordinates() const {
        return std::make_pair(x, y);
    }

    int getGridWidth() const {
        return width;
    }

    int getGridHeight() const {
        return height;
    }

    static int getActiveGridItemCount() {
        return activeGridItemCount;
    }
};

int GridItem::activeGridItemCount = 0;

#endif 
