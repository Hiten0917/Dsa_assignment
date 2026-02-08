#include <stdio.h>
#include <ctype.h>

int prec(char c) {
    if (c == '+' || c == '-') return 1;
    if (c == '*' || c == '/') return 2;
    return 0;
}

int calc(int a, int b, char op) {
    if (op == '+') return a + b;
    if (op == '-') return a - b;
    if (op == '*') return a * b;
    return a / b;
}

void solve() {
    char infix[100], post[100], s[100];
    int top = -1, j = 0, val[100], vTop = -1;

    printf("Enter infix: ");
    scanf("%s", infix);

    for (int i = 0; infix[i]; i++) {
        char c = infix[i];
        if (isdigit(c)) post[j++] = c;
        else if (c == '(') s[++top] = c;
        else if (c == ')') {
            while (top > -1 && s[top] != '(') post[j++] = s[top--];
            top--;
        } else {
            while (top > -1 && prec(s[top]) >= prec(c)) post[j++] = s[top--];
            s[++top] = c;
        }
    }
    while (top > -1) post[j++] = s[top--];
    post[j] = '\0';

    printf("Postfix: %s\n", post);

    for (int i = 0; post[i]; i++) {
        if (isdigit(post[i])) val[++vTop] = post[i] - '0';
        else {
            int b = val[vTop--], a = val[vTop--];
            val[++vTop] = calc(a, b, post[i]);
        }
    }
    printf("Result: %d\n", val[vTop]);
}

int main() {
    solve();
    return 0;
}