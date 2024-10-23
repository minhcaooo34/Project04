// dijsktras.cpp

// Main Execution

#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
#include <limits.h>
#include <algorithm>

using namespace std;

struct Node {
    int row, col, cost;
    bool operator>(const Node &other) const {
        return cost > other.cost;
    }
};

void readInput(unordered_map<char, int> &tileCosts, vector<vector<char>> &mapLayout, pair<int, int> &startPos, pair<int, int> &endPos) {
    int TILES_N;
    cin >> TILES_N;

    // Read tile symbols and their corresponding costs
    for (int i = 0; i < TILES_N; ++i) {
        char tileName;
        int tileCost;
        cin >> tileName >> tileCost;
        tileCosts[tileName] = tileCost;
    }

    // Read the map dimensions
    int MAP_ROWS, MAP_COLUMNS;
    cin >> MAP_ROWS >> MAP_COLUMNS;

    // Read the map layout
    mapLayout.resize(MAP_ROWS, vector<char>(MAP_COLUMNS));
    for (int i = 0; i < MAP_ROWS; ++i) {
        for (int j = 0; j < MAP_COLUMNS; ++j) {
            cin >> mapLayout[i][j];
        }
    }

    // Read the runner's starting and ending positions
    cin >> startPos.first >> startPos.second;
    cin >> endPos.first >> endPos.second;
}

// Dijkstra's algorithm placed in a separate function
vector<pair<int, int>> dijkstra(const unordered_map<char, int> &tileCosts, const vector<vector<char>> &mapLayout, pair<int, int> startPos, pair<int, int> endPos) {
    int MAP_ROWS = mapLayout.size();
    int MAP_COLUMNS = mapLayout[0].size();

    // Priority queue to process nodes with the smallest cost first
    priority_queue<Node, vector<Node>, greater<Node>> pq;

    // Distance table to store the cost of reaching each cell
    vector<vector<int>> dist(MAP_ROWS, vector<int>(MAP_COLUMNS, INT_MAX));

    // Table to store the previous cell for path reconstruction
    vector<vector<pair<int, int>>> prev(MAP_ROWS, vector<pair<int, int>>(MAP_COLUMNS, {-1, -1}));

    // Starting node (initial cost is 0 since we don't count entering the start)
    pq.push({startPos.first, startPos.second, 0});
    dist[startPos.first][startPos.second] = 0;

    // Direction vectors for moving up, down, left, right
    vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

    while (!pq.empty()) {
        Node current = pq.top();
        pq.pop();

        int currRow = current.row;
        int currCol = current.col;

        // If we reached the destination, stop
        if (currRow == endPos.first && currCol == endPos.second) {
            break;
        }

        // Explore neighbors (up, down, left, right)
        for (const auto &dir : directions) {
            int newRow = currRow + dir.first;
            int newCol = currCol + dir.second;

            // Check if the new position is within bounds
            if (newRow >= 0 && newRow < MAP_ROWS && newCol >= 0 && newCol < MAP_COLUMNS) {
                int newCost = dist[currRow][currCol] + tileCosts.at(mapLayout[newRow][newCol]);

                // If a shorter path is found
                if (newCost < dist[newRow][newCol]) {
                    dist[newRow][newCol] = newCost;
                    pq.push({newRow, newCol, newCost});
                    prev[newRow][newCol] = {currRow, currCol};
                }
            }
        }
    }

    // Reconstruct the path from endPos to startPos
    vector<pair<int, int>> path;
    pair<int, int> cur = endPos;

    // Handle case if no path exists
    if (dist[endPos.first][endPos.second] == INT_MAX) {
        return path; // Return empty path indicating no solution
    }

    while (cur != startPos) {
        path.push_back(cur);
        cur = prev[cur.first][cur.second];
    }
    path.push_back(startPos);

    // Reverse to get path from start to end
    reverse(path.begin(), path.end());

    // Return the path
    return path;
}

int main() {
    unordered_map<char, int> tileCosts;          // To store the cost of each tile type
    vector<vector<char>> mapLayout;              // 2D map layout
    pair<int, int> startPos, endPos;             // Runner's start and end positions

    // Reading input
    readInput(tileCosts, mapLayout, startPos, endPos);

    // Running Dijkstra's algorithm
    vector<pair<int, int>> path = dijkstra(tileCosts, mapLayout, startPos, endPos);

    // Handle case when no path exists
    if (path.empty()) {
        cout << "No path found" << endl;
        return 0;
    }

    // Output the cost (including the ending tile's cost but excluding the starting tile's cost)
    int totalCost = 0;
    for (size_t i = 0; i < path.size() - 1; ++i) {  // Exclude the starting tile
        totalCost += tileCosts[mapLayout[path[i].first][path[i].second]]; // Cost of entering each tile
    }
    cout << totalCost << endl;

    // Output the path
    for (const auto &pos : path) {
        cout << pos.first << " " << pos.second << endl;
    }

    return 0;
}