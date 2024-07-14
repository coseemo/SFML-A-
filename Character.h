//
// Created by cosim on 13/07/2024.
//

#ifndef ASFML_CHARACTER_H
#define ASFML_CHARACTER_H
#include "Node.h"

class Character {

public:

    Character(Node* startNode);
    void moveTo(Node* targetNode);
    void draw(sf::RenderWindow &window) const;

    Node* currentNode;
    sf::CircleShape shape;
};

#endif //ASFML_CHARACTER_H
