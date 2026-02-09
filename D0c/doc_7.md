7: Dijkstra’s Shortest Path Algorithm
This program implements Dijkstra’s Algorithm to calculate the most efficient path from a single source vertex to all other reachable nodes in a weighted, directed graph. It utilizes a greedy approach to ensure that the shortest possible distance is locked in for each node during processing.

(a) Architecture and Logic
The algorithm manages the graph's state through three primary tracking structures:

Distance Array (dist[]): Stores the current minimum weight required to reach each node. Initially, the source is set to 0 and all other nodes are set to Infinity (INF).

Visited Array (visited[]): A boolean flag system that marks nodes once their absolute shortest path has been confirmed, preventing redundant calculations.

Parent Array (parent[]): A backtracking tool that stores the predecessor of each node, allowing the program to reconstruct the full path from the source to any destination.

(b) Functional Breakdown
The Greedy Process
Selection: The program scans the dist[] array to find the unvisited node with the smallest current distance.

Relaxation: For the selected node, the program looks at all its neighbors. If the distance to the current node plus the edge weight to a neighbor is less than the neighbor's current recorded distance, the neighbor's dist[] and parent[] values are updated.

Complexity Analysis
Time Complexity: In this implementation (using a linear search for the minimum distance), the complexity is O(V²). For larger datasets, this can be optimized to O((V+E) log V) using a Priority Queue or Min-Heap.

Space Complexity: O(V), required to maintain the tracking arrays for distances, parent pointers, and visited status.

(c) Implementation Workflow (main)
The main() function executes the following sequence:

Graph Construction: Takes user input for the number of vertices and edges.

Edge Mapping: Populates an adjacency list with the source, destination, and weight for each connection.

Path Calculation: Executes the Dijkstra logic starting from a user-defined source node.

Results Display: Iterates through all nodes to print the final distance and uses the parent[] array to print the step-by-step path (e.g., 0 -> 2 -> 1 -> 3).

(d) Execution Trace
Input Sample:

4 Nodes, 5 Edges

Edges: (0,1,w4), (0,2,w1), (1,3,w1), (2,1,w2), (2,3,w5)

Source: 0

Output Results:

Node 1: Distance: 3 | Path: 0 -> 2 -> 1

Node 2: Distance: 1 | Path: 0 -> 2

Node 3: Distance: 4 | Path: 0 -> 2 -> 1 -> 3

(e) Final Technical Review
Dijkstra’s algorithm is a cornerstone of network routing and GPS navigation. While it is highly efficient for non-negative weights, its primary limitation is an inability to handle negative edge weights, which would require the Bellman-Ford algorithm. This implementation successfully demonstrates the "Greedy" property, where local optimal choices lead to a global shortest-path solution.