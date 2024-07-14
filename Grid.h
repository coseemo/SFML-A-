//
// Created by cosim on 13/07/2024.
//

#ifndef ASFML_GRID_H
#define ASFML_GRID_H
#include "Node.h"

class Grid {
public:

    std::vector<std::vector<Node>> nodes;

    Grid(int width, int height);
    void draw(sf::RenderWindow &window);
    static bool randombool();

    int width, height;

};
#endif //ASFML_GRID_H
