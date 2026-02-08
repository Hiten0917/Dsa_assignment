Documentation for Program 2: Infix to Postfix Conversion and Evaluation
This program handles the transformation of standard mathematical expressions (infix) into postfix notation and computes the final result. Both processes rely heavily on the Stack data structure to manage operator precedence and intermediate calculation values.

(a) Data Structure Definitions
The program uses two distinct stacks to separate logic from arithmetic:

1. Operator Stack (Conversion)
char stack[MAX]: A character array used to temporarily hold operators (+, -, *, /) and parentheses while the expression is being rearranged.

int top = -1: An integer index that tracks the top of the operator stack.

2. Value Stack (Evaluation)
int valueStack[MAX]: An integer array used to store operands and the results of intermediate calculations during the evaluation phase.

int valueTop = -1: An integer index that tracks the current position in the value stack.

(b) Function Descriptions and Logic
Core Stack Operations
push(char x): Adds a new element to the top of the stack and increments the top index.

pop(): Returns the element currently at the top and then decrements the top index.

Logic and Processing Functions
precedence(char p): Assigns a weight to operators to ensure correct mathematical order.

+ and - are assigned Precedence 1.

* and / are assigned Precedence 2. This ensures that multiplication and division are processed before addition and subtraction.

infixToPostfix(char infix[], char postfix[]): This function converts the user input into a machine-friendly format.

Operands: Added directly to the output string.

Parentheses: ( is pushed to the stack; when ) is found, the stack is popped until the matching ( is reached.

Operators: If an operator has higher or equal precedence than the one on the stack, the stack is popped. The new operator is then pushed.

Cleanup: Any remaining operators in the stack are moved to the end of the string.

evaluatePostfix(char postfix[]): Computes the numerical result of the converted expression.

Scans the postfix string from left to right.

Operands are pushed onto the valueStack.

Operators trigger a pop of the two most recent values. The operation is performed, and the result is pushed back onto the stack.

Final Result: The last remaining value in the stack is the total.

(c) Overview of the main() Function
The main() function acts as the controller for the entire process:

Input: Prompts the user to enter a standard infix expression.

Conversion: Passes the input to infixToPostfix and displays the resulting string.

Calculation: Passes that postfix string to evaluatePostfix.

Output: Prints the final integer result to the console.

(d) Sample Run Results
Example 1:

Input: 2+3*4

Postfix: 234*+

Result: 14

Example 2:

Input: (1+2)*(3+4)

Postfix: 12+34+*

Result: 21

(e) Conclusion
This program illustrates the practical utility of stacks in compiler design and calculator logic. By managing operator precedence and parentheses through a LIFO (Last In, First Out) system, the program ensures that complex mathematical expressions are evaluated accurately and efficiently.