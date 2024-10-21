// dijsktras.cpp

// Main Execution

#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>

using namespace std;

struct Tile {
    char symbol;
    int cost;
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

int main() {
    unordered_map<char, int> tileCosts;          // To store the cost of each tile type
    vector<vector<char>> mapLayout;              // 2D map layout
    pair<int, int> startPos, endPos;             // Runner's start and end positions

    readInput(tileCosts, mapLayout, startPos, endPos);

    //djikstra's algorithm
    //FUNCTION HERE

    return 0;
}

