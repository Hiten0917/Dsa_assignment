6: Min and Max Heap Construction
This program demonstrates how to transform a standard unsorted array into a Binary Heap. By applying "heapify" logic, the program organizes data into two specific hierarchical structures: a Min Heap (where the root is the smallest element) and a Max Heap (where the root is the largest).

(a) Architecture and Definitions
A Binary Heap is stored in a one-dimensional array, but conceptually treated as a complete binary tree. The relationship between any parent node at index i and its children is defined by specific mathematical offsets:

Left Child: 2i+1

Right Child: 2i+2

Parent Node: (i−1)/2

Core Components
smallest / largest: Temporary indices used during the heapify process to track which node (parent or child) holds the value that satisfies the heap property.

left / right: Variables used to compute the specific array indices of the current node's children.

Recursion: Both heapify functions use recursive calls to ensure that a swap at a higher level doesn't break the heap properties further down the tree.

(b) Functional Logic
void swap(int *x, int *y)
A utility function that exchanges the values of two memory addresses using a temporary variable. This is triggered whenever a child node violates the heap property relative to its parent.

void minHeapify(int arr[], int n, int i)
Ensures the Min Heap property: Parent≤Children. If a child node is found to be smaller than the current root i, the indices are swapped, and the function recurses down that branch to re-validate the sub-tree.

void maxHeapify(int arr[], int n, int i)
Ensures the Max Heap property: Parent≥Children. If a child node is larger than the root i, they are swapped. The function then continues to heapify the affected subtree until the largest value of that section has successfully bubbled up to the parent position.

void buildHeap(int arr[], int n)
To build a heap from an unsorted array, the program doesn't start at the beginning. Instead, it starts at the last non-leaf node (n/2−1) and works backward to the root. This "bottom-up" approach ensures that sub-trees are already valid heaps before they are processed as children of higher-level nodes.

(c) Program Execution (main)
The main function serves as the controller for the heap construction process:

Input: Initializes an unsorted array: {45, 12, 89, 33, 7, 56, 23}.

Min Heap Construction: Calls buildMinHeap to reorganize the array so the minimum value (7) sits at index 0.

Max Heap Construction: Calls buildMaxHeap to reorganize the array so the maximum value (89) sits at index 0.

Verification: Uses a display function to print the array after each transformation.

(d) Execution Trace
Unsorted Input: 45 12 89 33 7 56 23

Calculated Min Heap: 7 12 23 33 45 56 89 (Note: 7 is at the root; every parent is ≤ its children)

Calculated Max Heap: 89 33 56 12 7 45 23 (Note: 89 is at the root; every parent is ≥ its children)

(e) Conclusion
The program effectively illustrates the efficiency of heap construction. By utilizing a bottom-up heapify approach, an unsorted array is converted into a priority-ready structure in O(n) time. This logic forms the foundation for high-performance systems like priority queues and the Heapsort algorithm.