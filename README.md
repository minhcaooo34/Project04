Project 04: Path Finding

| N             | Elapsed Time (s)  | Memory Usage (bytes)  |
|---------------|-------------------|-----------------------|
| 10            | 0.0014            | 85,538                |
| 20            | 0.002             | 91,568                |
| 50            | 0.003             | 123,978               |
| 100           | 0.006             | 230,848               |
| 200           | 0.021             | 639,588               |
| 500           | 0.124             | 3,440,144             |
| 1000          | 0.502             | 13,298,180            |

1. We used a 2D grid of tiles, where each tile acts as a node in the graph. The connections between these nodes are based on their adjacency in the grid. The 2D grid is an implicit graph where neighboring tiles form edges between nodes. The map itself is stored as a vector of vectors (vector<vector<char>>), representing the layout of the grid.

2. For Dijkstra's algorithm, we utilized a priority queue (specifically a min-heap) to handle nodes based on their shortest known distance at any given point. Each operation on the priority queue has a time cost of O(logV), where V represents the number of tiles (vertices). The overall time complexity for the algorithm in this case is O((V + E)logV), with E being the number of edges, which are determined by the neighboring relationships between tiles.

3. In terms of execution time, the algorithm performs well for most practical grid sizes, though you will notice an increase in computation time for very large maps. Regarding memory usage, as the map size increases, memory demands rise accordingly, mainly because the algorithm has to maintain data such as distances, the priority queue, and previous nodes for each tile. For especially large grids, this becomes more of a factor in limiting performance.
