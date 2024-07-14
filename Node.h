//
// Created by cosim on 13/07/2024.
//

#ifndef ASFML_NODE_H
#define ASFML_NODE_H
#include <SFML/graphics.hpp>

class Node{

public:

    float x,y;
    float gCost,hCost,fCost;
    bool walkable;
    sf::RectangleShape shape;

    Node(float x, float y, bool walkable);
    void draw(sf::RenderWindow &window);
    bool operator>(const Node& other) const;

};
#endif //ASFML_NODE_H
