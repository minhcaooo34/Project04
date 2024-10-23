// dijsktras.cpp

// Partners: David Cheves & Minh Cao
// netIDs:    dcheves & mcao12
// Program Description: This program practices with the implementation of Dijkstras Algorithm. 
//                      It reads input from cin to determine the size of the board, the weights
//                      of each edge, and where to start and end. From that input, Dijkstras 
//                      algorithm is run. This finds the shortest path to the destination node
//                      and then outputs the total cost to travel to that node and each step
//                      of the path that the algorithm took. This program worked with Dijkstras
//                      algorithm and how to implement it on a weighted graph.

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
    int numTiles;
    cin >> numTiles;

    // Read tile symbols and their costs
    for (int i = 0; i < numTiles; ++i) {
        char tileName;
        int tileCost;
        cin >> tileName >> tileCost;
        tileCosts[tileName] = tileCost;
    }

    // Read the map dimensions
    int rows, cols;
    cin >> rows >> cols;

    // Read the map layout
    mapLayout.resize(rows, vector<char>(cols));
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            cin >> mapLayout[i][j];
        }
    }

    // Read the starting and ending positions
    cin >> startPos.first >> startPos.second;
    cin >> endPos.first >> endPos.second;
}

// Dijkstra's algorithm
vector<pair<int, int>> dijkstra(const unordered_map<char, int> &tileCosts, const vector<vector<char>> &mapLayout, pair<int, int> startPos, pair<int, int> endPos) {
    int rows = mapLayout.size();
    int cols = mapLayout[0].size();

    // Priority queue to process nodes with the smallest cost first
    priority_queue<Node, vector<Node>, greater<Node>> pq;

    // Distance table to store the cost of reaching each cell
    vector<vector<int>> dist(rows, vector<int>(cols, INT_MAX));

    // Table to store the previous cell for path
    vector<vector<pair<int, int>>> prev(rows, vector<pair<int, int>>(cols, {-1, -1}));

    // Starting node (don't include start node cost)
    pq.push({startPos.first, startPos.second, 0});
    dist[startPos.first][startPos.second] = 0;

    // Direction vectors
    vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

    while (!pq.empty()) {
        Node current = pq.top();
        pq.pop();

        int currRow = current.row;
        int currCol = current.col;

        // Stop
        if (currRow == endPos.first && currCol == endPos.second) {
            break;
        }

        // Check up, down, left, right
        for (const auto &dir : directions) {
            int newRow = currRow + dir.first;
            int newCol = currCol + dir.second;

            // Check if the new position is in the map bounds
            if (newRow >= 0 && newRow < rows && newCol >= 0 && newCol < cols) {
                int newCost = dist[currRow][currCol] + tileCosts.at(mapLayout[newRow][newCol]);

                // If a shorter path is found update
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

    // If no path exisits
    if (dist[endPos.first][endPos.second] == INT_MAX) {
        return path; 
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
    unordered_map<char, int> tileCosts;
    vector<vector<char>> mapLayout;
    pair<int, int> startPos, endPos;     

    readInput(tileCosts, mapLayout, startPos, endPos);
    vector<pair<int, int>> path = dijkstra(tileCosts, mapLayout, startPos, endPos);

    // If no path exists
    if (path.empty()) {
        cout << "No path found" << endl;
        return 0;
    }

    // Output the cost
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