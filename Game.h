//
// Created by cosim on 13/07/2024.
//

#ifndef ASFML_GAME_H
#define ASFML_GAME_H
#include <SFML/Graphics.hpp>
#include "Grid.h"
#include "Character.h"
#include "AStar.h"
#include <memory>
#include <array>

class Game {
public:

    Game();
    void run();

    sf::RenderWindow window;
    Grid grid;
    Character character;
    Astar astar;

    void processEvents();
    void update(std::vector<Node *>::iterator &it, std::vector<Node*>::iterator);
    void render();
};

#endif //ASFML_GAME_H
