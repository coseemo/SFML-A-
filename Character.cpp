//
// Created by cosim on 13/07/2024.
//
#include "Character.h"

Character::Character(Node* startNode) : currentNode(startNode) {
    shape.setRadius(15);
    shape.setFillColor(sf::Color::Blue);
    moveTo(startNode);
}

void Character::moveTo(Node* targetNode) {
    currentNode = targetNode;
    if(targetNode->walkable)
        shape.setPosition(targetNode->x * 30 + 15, targetNode->y * 30 + 15);
}

void Character::draw(sf::RenderWindow &window) const {
    window.draw(shape);
}