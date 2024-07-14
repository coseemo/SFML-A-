//
// Created by cosim on 13/07/2024.
//

#ifndef ASFML_ASTAR_H
#define ASFML_ASTAR_H
#include <vector>
#include <unordered_set>
#include "Grid.h"

class Astar {

public:

    static std::vector<Node*> findPath(Grid& grid, Node& start, Node& end);

private:

    static std::vector<Node*> getNeighbors(Node& node, Grid& grid);
    static int heuristic(Node& a, Node& b);

    static bool contains(std::vector<Node *> &vec, Node *node);

    static bool contains(const std::unordered_set<Node *> &set, Node *node);
};
#endif //ASFML_ASTAR_H
