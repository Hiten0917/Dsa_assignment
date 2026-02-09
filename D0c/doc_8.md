8: Comparative Analysis of Sorting Algorithms
This program evaluates the performance of three distinct sorting techniques—Bubble Sort, Selection Sort, and Merge Sort. By tracking the number of comparisons and data movements (swaps) each algorithm performs on a randomized dataset, it provides a direct look at algorithmic efficiency.

(a) Core Data Structures and Metrics
The program utilizes standard arrays and global counters to monitor performance in real-time:

orig[10] and temp[10]: Integer arrays used to store the initial random dataset and its working copies. Using copies ensures that every algorithm is tested against the exact same unsorted input.

c (Comparisons): An integer counter that increments every time two elements are evaluated against each other (e.g., checking if one value is greater than another).

s (Swaps/Moves): A counter that tracks the physical relocation of data, such as a pointer swap in Bubble Sort or an element assignment in Merge Sort.

(b) Functional Logic
1. Bubble Sort (bubble)
Mechanism: Iterative Exchange Bubble Sort repeatedly steps through the list, compares adjacent elements, and swaps them if they are in the wrong order. This process causes the largest unsorted element to "bubble" up to its correct position at the end of the array with each full pass.

2. Selection Sort (selection)
Mechanism: Minimum Element Selection This algorithm divides the array into a sorted and an unsorted section. It scans the unsorted part to find the absolute minimum value and swaps it with the first element of that section. This typically results in significantly fewer swaps compared to Bubble Sort.

3. Merge Sort (merge_sort & merge)
Mechanism: Divide and Conquer A recursive approach that splits the array into halves until each subarray contains a single element. The merge function then combines these subarrays in sorted order. Unlike the other two, this algorithm operates with O(nlogn) complexity and tracks "moves" as it populates auxiliary arrays.

4. Utility Functions
swap(): Manages the logic for exchanging two values in memory and increments the global swap counter.

reset_stats(): Clears the comparison and swap counters between different tests.

print_and_reset(): Formats and displays the performance data for each algorithm.

(c) Program Execution (main)
The main function manages the lifecycle of the experiment:

Data Generation: Uses rand() and srand(time(NULL)) to produce a unique set of 10 integers for testing.

Isolated Testing: For each sorting method, the program copies the original array, executes the sort, and logs the metrics.

Reporting: Outputs a formatted report showing the total comparisons and swaps performed by each method.

(d) Sample Output Trace
Input Generation: Generating random array of size 10...

Bubble Sort Performance

Comparisons: 45

Swaps/Moves: 22

Selection Sort Performance

Comparisons: 45

Swaps/Moves: 8

Merge Sort Performance

Comparisons: 34

Swaps/Moves: 42

(Note: Exact numbers depend on the randomness of the initial array.)

(e) Technical Conclusion
The program demonstrates the trade-offs between different sorting strategies. While Bubble Sort and Selection Sort share an O(n 
2
 ) complexity, Selection Sort is more efficient in terms of memory writes. Merge Sort, while requiring more "moves" to manage data, remains the most efficient choice for reducing comparisons as the dataset grows.