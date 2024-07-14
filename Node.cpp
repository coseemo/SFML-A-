//
// Created by cosim on 13/07/2024.
//

#include "Node.h"

Node::Node(float x, float y, bool walkable) : x(x), y(y), walkable(walkable){
    shape.setSize(sf::Vector2f(30, 30));
    shape.setPosition(x * 30, y * 30);
    shape.setFillColor(walkable ? sf::Color::Green : sf::Color::Red);
}

void Node::draw(sf::RenderWindow &window) {
    window.draw(shape);
}

bool Node::operator>(const Node &other) const {
    return fCost > other.fCost;
}
