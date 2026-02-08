Documentation for Program 4: Doubly Linked List (DLL) Mechanics
This implementation focuses on bidirectional data management using a Doubly Linked List. By utilizing two pointers per node, the program enables efficient insertion and removal without the overhead of full-list traversals required by singly linked lists.

(a) Architecture
The list is built on a custom Node structure that stores both data and directional links.

int data: The integer payload.

struct Node* prev: Pointer to the preceding element (enables backward movement).

struct Node* next: Pointer to the following element (enables forward movement).

(b) Logic & Functional Breakdown
CreateNode
This is the constructor. It handles the malloc call to reserve heap space, assigns the input integer to the node, and nullifies both prev and next pointers. This ensures every new node starts as a clean, isolated block.

InsertAfter
This function handles the pointer handshakes required to inject a node into the middle of the list.

Isolation: A new node is generated via CreateNode.

Forward Link: The new node’s next is set to point to the current GivenNode->next.

Backward Link: The new node’s prev is set to the GivenNode.

Re-linking: If the GivenNode wasn't at the tail, the old successor's prev is updated to point to our new node, completing the bridge.

DeleteNode
Removes a targeted node while stitching the surrounding list back together.

Head Logic: If the target is the first node, the head pointer is moved forward.

Bridge Logic: The program checks for a predecessor and successor. If found, their respective next and prev pointers are updated to "jump" over the deleted node.

Memory Release: Once the node is unlinked, free() is called to return that memory to the system.

PrintList
A simple linear traversal. It starts at the provided head and steps through the next pointers, printing the integer values until it hits a NULL terminator at the tail.

(c) Implementation Workflow (main)
The main function executes a standard lifecycle test for the DLL:

Creation: Builds a foundation with three nodes: 11, 22, and 33.

Integration: Manually links the prev and next pointers to establish the initial bidirectional chain.

Modification: Tests the InsertAfter logic by placing 44 behind 22, then tests DeleteNode by removing the 22 node entirely.

Verification: Calls PrintList after each state change to confirm the pointers are holding the structure together.

(d) Output Logs
Initial Chain: 11 22 33

Post-Insertion (44 after 22): 11 22 44 33

Post-Deletion (22 removed): 11 44 33

(e) Final Review
This code demonstrates the flexibility of Doubly Linked Lists for dynamic data storage. By managing four pointer assignments per insertion/deletion, we maintain a structure that allows for O(1) removal (if the node is known) and easy bidirectional navigation—features that make DLLs the backbone of many complex systems like navigation histories and undo-redo buffers.