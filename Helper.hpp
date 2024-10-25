#ifndef HELPER_HPP
#define HELPER_HPP

#include <utility> 
#include <cmath>   

class Helper {
public:

    static int manhattanDistance(std::pair<int, int> item1, std::pair<int, int> item2) {
        return std::abs(item2.first - item1.first) + std::abs(item2.second - item1.second);
    }
};

#endif
