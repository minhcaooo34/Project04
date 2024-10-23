QUESTIONS:

1. The map was represented as a 2D grid of tiles, where each tile is treated as a vertex in the
graph. The relationship between tiles is established based on the adjacency
matrix. The graph is implicitly represented using the 2D grid (vector<vector<char>>).
2. Dijkstra's algorithm uses a priority queue (min-heap) and processes vertices based on their
current minimum distance. The cost is O(logV) per operation, where V is the
number of vertices (tiles). Overall, the time complexity of Dijkstra’s algorithm in this context is
O((V+E)logV).
3. Execution Time: The algorithm scales reasonably well for practical map sizes, although the
growth in time for very large maps is noticeable.
Memory Usage: As the number of tiles grows, memory usage becomes more of a concern,
particularly for extremely large maps. This is a direct consequence of needing to store
distances, previous nodes, and the priority queue.

SUMMARY:
I basically worked on the Dijkstra's algorithm. David worked on reading in the information with cin and determined what structures to use 
within this program. I was having some issues getting it set up so I had my cousin (previous CS302 student) how 
to start it and the best way to approach it. After setting it up it took me about 1 1/2 to 2 hours to fully complete the program. However, 
even then it wasn't fully working correctly and I had David take a look to see where I went wrong. Overall we figured out the issue and 
the program is fully working now. Communication was very good overall and enjoyed working with David. It really helped getting a second
pair of eyes seeing my mistakes after sitting at a computer for a long time.
