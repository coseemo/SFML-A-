//
// Created by cosim on 13/07/2024.
//
#include <random>
#include "Grid.h"

Grid::Grid(int width, int height) : width(width), height(height) {
    for (int y = 0; y < height; ++y) {
        std::vector<Node> row;
        for (int x = 0; x < width; ++x) {
            if (x == y-2 || x == y) {
                row.emplace_back(x, y, true);
            } else if(x == 5 || x == y-3) {
                row.emplace_back(x, y, true);
            }
            else
                row.emplace_back(x, y, randombool());
        }
        nodes.push_back(row);
    }
}

void Grid::draw(sf::RenderWindow &window) {
    for (auto &row : nodes) {
        for (auto &node : row) {
            node.draw(window);
        }
    }
}

bool Grid::randombool() {
    static std::random_device rd; // Seed for the random number engine
    static std::mt19937 gen(rd()); // Mersenne Twister random number engine
    static std::bernoulli_distribution dis(0.5); // Distribution that produces true or false with equal probability
    return dis(gen);
}

