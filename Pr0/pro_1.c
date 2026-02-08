#include <stdio.h>

int match(char open, char close) {
    return (open == '(' && close == ')') || 
           (open == '{' && close == '}') || 
           (open == '[' && close == ']');
}

int balanced(char *exp) {
    char stack[100];
    int top = -1;

    for (int i = 0; exp[i]; i++) {
        if (exp[i] == '(' || exp[i] == '{' || exp[i] == '[') {
            stack[++top] = exp[i];
        } else if (exp[i] == ')' || exp[i] == '}' || exp[i] == ']') {
            if (top == -1 || !match(stack[top--], exp[i])) return 0;
        }
    }
    return top == -1;
}

int main() {
    char *exps[] = {"a + (b - c) * (d", "m + [a - b * (c + d * {m)]", "a + (b - c)"};
    
    for (int i = 0; i < 3; i++) {
        printf("Expression %d is %s\n", i + 1, balanced(exps[i]) ? "Balanced" : "Not Balanced");
    }
    return 0;
}