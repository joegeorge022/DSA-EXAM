#include <stdio.h>
#include <ctype.h>

#define MAX 100

char stack[MAX];
int top = -1;

int stackInt[MAX];
int topInt = -1;

void push(char c) {
    stack[++top] = c;
}

char pop() {
    return stack[top--];
}

char peek() {
    if (top == -1) return '\0';
    return stack[top];
}

void pushInt(int x) {
    stackInt[++topInt] = x;
}

int popInt() {
    return stackInt[topInt--];
}

int precedence(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    return 0;
}

int isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/');
}

void infixToPostfix(char infix[], char postfix[]) {
    int i = 0, k = 0;
    char c;

    while ((c = infix[i]) != '\0') {
        if (isdigit(c)) {
            postfix[k++] = c;
        }
        else if (c == '(') {
            push(c);
        }
        else if (c == ')') {
            while (top != -1 && peek() != '(') {
                postfix[k++] = pop();
            }
            pop();
        }
        else if (isOperator(c)) {
            while (top != -1 && precedence(peek()) >= precedence(c)) {
                postfix[k++] = pop();
            }
            push(c);
        }
        i++;
    }

    while (top != -1) {
        postfix[k++] = pop();
    }

    postfix[k] = '\0';
}

int evaluatePostfix(char postfix[]) {
    int i = 0;
    char c;

    while ((c = postfix[i]) != '\0') {
        if (isdigit(c)) {
            pushInt(c - '0');
        }
        else if (isOperator(c)) {
            int b = popInt();
            int a = popInt();
            int res;

            switch (c) {
                case '+': res = a + b; break;
                case '-': res = a - b; break;
                case '*': res = a * b; break;
                case '/': res = a / b; break;
            }

            pushInt(res);
        }
        i++;
    }

    return popInt();
}

int main() {
    char infix[MAX], postfix[MAX];
    int result;

    printf("Enter infix expression (no spaces, single digit operands): ");
    scanf("%s", infix);

    infixToPostfix(infix, postfix);

    printf("Infix  : %s\n", infix);
    printf("Postfix: %s\n", postfix);

    result = evaluatePostfix(postfix);

    printf("Result : %d\n", result);
    
}