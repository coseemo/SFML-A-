#include "Astar.h"
#include <algorithm>
#include <limits>
#include <queue>
#include <unordered_set>
#include <vector>

struct NodeComparator {
    bool operator()(const Node* lhs, const Node* rhs) const {
        return lhs->fCost > rhs->fCost;
    }
};

std::vector<Node*> Astar::findPath(Grid& grid, Node& start, Node& end) {
    std::priority_queue<Node*, std::vector<Node*>, NodeComparator> openSet;
    std::unordered_set<Node*> openSetTracker;
    std::unordered_set<Node*> closedSet;
    std::vector<Node*> cameFrom(grid.width * grid.height, nullptr);
    std::vector<float> gScore(grid.width * grid.height, std::numeric_limits<float>::infinity());

    auto index = [&](Node& node) {
        return static_cast<int>(node.y) * grid.width + static_cast<int>(node.x);
    };

    gScore[index(start)] = 0;
    start.fCost = heuristic(start, end);
    openSet.push(&start);
    openSetTracker.insert(&start);

    while (!openSet.empty()) {
        Node* current = openSet.top();
        openSet.pop();
        openSetTracker.erase(current);

        if (current == &end) {
            std::vector<Node*> path;
            while (current != nullptr) {
                path.push_back(current);
                current = cameFrom[index(*current)];
            }
            std::reverse(path.begin(), path.end());
            return path;
        }

        closedSet.insert(current);

        for (Node* neighbor : getNeighbors(*current, grid)) {
            if (closedSet.find(neighbor) != closedSet.end() || !neighbor->walkable) {
                continue;
            }

            float tentativeGScore = gScore[index(*current)] + heuristic(*current, *neighbor);

            if (tentativeGScore < gScore[index(*neighbor)]) {
                cameFrom[index(*neighbor)] = current;
                gScore[index(*neighbor)] = tentativeGScore;
                neighbor->fCost = gScore[index(*neighbor)] + heuristic(*neighbor, end);

                if (openSetTracker.find(neighbor) == openSetTracker.end()) {
                    openSet.push(neighbor);
                    openSetTracker.insert(neighbor);
                }
            }
        }
    }

    return {};
}

std::vector<Node*> Astar::getNeighbors(Node& node, Grid& grid) {
    std::vector<Node*> neighbors;
    int x = static_cast<int>(node.x);
    int y = static_cast<int>(node.y);

    const std::vector<std::pair<int, int>> directions = {
            {1, 0}, {-1, 0}, {0, 1}, {0, -1}
    };

    for (const auto& direction : directions) {
        int nx = x + direction.first;
        int ny = y + direction.second;

        if (nx >= 0 && ny >= 0 && nx < grid.width && ny < grid.height) {
            neighbors.push_back(&grid.nodes[ny][nx]);
        }
    }

    return neighbors;
}

int Astar::heuristic(Node& a, Node& b) {
    return std::abs(static_cast<int>(a.x - b.x)) + std::abs(static_cast<int>(a.y - b.y));
}

bool Astar::contains(const std::unordered_set<Node*>& set, Node* node) {
    return set.find(node) != set.end();
}
