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

1. The map was represented as a 2D grid of tiles, where each tile is treated as a vertex in the graph. The relationship between tiles is established based on the adjacency matrix. The graph is implicitly represented using the 2D grid (vector<vector<char>>).

2. Dijkstra's algorithm uses a priority queue (min-heap) and processes vertices based on their current minimum distance. The cost is O(logV) per operation, where 𝑉 is the number of vertices (tiles). Overall, the time complexity of Dijkstra’s algorithm in this context is O((V+E)logV).

3.
Execution Time: The algorithm scales reasonably well for practical map sizes, although the growth in time for very large maps is noticeable.
Memory Usage: As the number of tiles grows, memory usage becomes more of a concern, particularly for extremely large maps. This is a direct consequence of needing to store distances, previous nodes, and the priority queue.
