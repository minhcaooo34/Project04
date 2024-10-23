Project 04: Path Finding

Project Partners: David Cheves & Minh Cao 

NetIDs: dcheves & mcao12


Partner turning it in: David Cheves (My summary is in this file)

GitHub: https://github.com/minhcaooo34/Project04.git



How to compile dijkstras.cpp: Run "make" on the command line

How to execute dijkstras: Run ./src/dijkstras < data/[input].txt

What will happen: The program will output the total weight to traverse and every step taken



How to compile generator.cpp: Run "make" on the command line

How to execute generator: Run ./data/generator

What will happen: A text file of size N (Determined in generator.cpp) will be in the Project4 directory as map[N].txt



Summary: I started by working on reading input in from cin. I had to determine what data structures to use and I had to figure out the best way to read in data so that it could be used in the Dijkstras Algorithm. Then, Minh started on the implementation of Dijkstras Algorithm. He figured out the solution almost completely and was 
printing out the correct path to take, but didn't have the correct cost. I also completed the markdown table and creating the map generator. I went into the program and found where his mistake was and then the program was working correctly. I enjoyed working with Minh. We worked well together and we were able to communicate effectively 
to finish this project on time.



|               |  Markdown Table   |                       |
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
