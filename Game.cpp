//
// Created by cosim on 13/07/2024.
//
#include "Game.h"

Game::Game() : window(sf::VideoMode(800, 600), "Find A* way"), grid(20, 20), character(&grid.nodes[0][0]) {}

void Game::run() {
    std::vector<Node*> path = astar.findPath(grid, *character.currentNode, grid.nodes[19][19]);
    auto it = path.begin();
    auto end = path.end();

    sf::Clock clock;
    sf::Time timeSinceLastUpdate = sf::Time::Zero;
    sf::Time TimePerFrame = sf::seconds(5.f / 60.f);

    while (window.isOpen()) {
        processEvents();
        timeSinceLastUpdate += clock.restart();
        while (timeSinceLastUpdate > TimePerFrame) {
            timeSinceLastUpdate -= TimePerFrame;
            processEvents();
            update(it, end);
        }
        render();
    }
}


void Game::processEvents() {
    sf::Event event;
    while (window.pollEvent(event)) {
        if (event.type == sf::Event::Closed)
            window.close();
    }
}

void Game::update(std::vector<Node*>::iterator &it, std::vector<Node*>::iterator end) {
    if (it != end) {
        character.moveTo(*it);
        ++it;
    }
}


void Game::render() {
    window.clear();
    grid.draw(window);
    character.draw(window);
    window.display();
}
