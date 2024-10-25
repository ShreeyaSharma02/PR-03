#include <iostream>
#include "GridItem.hpp"
#include "Helper.hpp"

int main() {
    GridItem item1(0, 0, 2, 3);

    GridItem item2(3, 2, 4, 5);

    std::pair<int, int> coords1 = item1.getCoordinates();
    std::pair<int, int> coords2 = item2.getCoordinates();
    
    std::cout << "Item 1 Coordinates: (" << coords1.first << ", " << coords1.second << ")\n";
    std::cout << "Item 2 Coordinates: (" << coords2.first << ", " << coords2.second << ")\n";

    int distance = Helper::manhattanDistance(coords1, coords2);
    std::cout << "Manhattan Distance between Item 1 and Item 2: " << distance << "\n";

    std::cout << "Active GridItem Count: " << GridItem::getActiveGridItemCount() << "\n";

    return 0;
}
