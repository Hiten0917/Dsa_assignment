5: Graph Representation and Traversal (Adjacency Matrix)
This implementation explores graph theory by representing an undirected graph through an Adjacency Matrix. It provides a comparative look at two fundamental traversal logic patterns: Depth First Search (DFS) and Breadth First Search (BFS), utilizing stacks and queues respectively to navigate a 7-vertex network.

(a) Data Structure Definition
The program manages the graph and its traversal state using the following structures:

adjMatrix[MAX][MAX]: A 2D integer array where a 1 at [i][j] signifies a connection (edge) between vertex i and vertex j.

visited[MAX]: A tracking array used to flag vertices once they’ve been processed, preventing infinite loops or redundant processing.

stack[MAX]: The primary container for DFS logic, managing the "dive deep" order of vertex processing.

queue[MAX]: The primary container for BFS logic, managing the "level-by-level" discovery of neighbors.

(b) Functional Logic
initGraph(int vertices)
Prepares the environment by setting the vertex count and clearing the matrix. Every cell is set to 0 (no edges), and the visited array is wiped clean to ensure a fresh state.

addEdge(int a, int b)
Defines the connections. Since this is an undirected graph, the function applies symmetry: it sets both adjMatrix[a][b] and adjMatrix[b][a] to 1.

DFS(int startV)
Concept: Exploration by going as deep as possible along a branch before backtracking.

Execution: Pushes the starting node onto the stack. It then enters a loop: popping the top node, marking it visited if it isn't already, and pushing all its unvisited neighbors back onto the stack. This continues until the stack is drained.

BFS(int startV)
Concept: Exploration by visiting all immediate neighbors before moving to the next level.

Execution: Marks the start node as visited and places it in the queue. It then dequeues nodes one by one; for every node removed, all its unvisited neighbors are added to the end of the queue. This ensures a circular, outward expansion from the source.

(c) Execution Flow (main)
The main function acts as a test bench for the graph's connectivity:

Setup: Creates a graph with 7 vertices.

Mapping: Defines the topology using addEdge() calls (e.g., connecting vertex 0 to 1 and 2, branching down to 6).

DFS Run: Executes a depth-first pass starting at 0, then clears the visited flags.

BFS Run: Executes a breadth-first pass from the same starting point.

Output: Displays the specific order of discovery for each method to highlight the difference in search behavior.

(d) Run Logs
Graph Configuration: Edges: (0,1), (0,2), (1,3), (1,4), (2,5), (2,6)

Results:

DFS Path (Vertex 0): 0 1 3 4 2 5 6

BFS Path (Vertex 0): 0 1 2 3 4 5 6

(e) Conclusion
The project highlights the structural differences between stack-based and queue-based navigation. While the Adjacency Matrix provides a direct way to check for edges, the choice between DFS and BFS determines the efficiency and order of data discovery—crucial concepts for pathfinding and network analysis in broader software applications.