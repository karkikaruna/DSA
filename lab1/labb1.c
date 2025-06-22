#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <math.h>

#define MAX 100

char stack[MAX];
int top = -1;

int valStack[MAX];
int valTop = -1;

// Stack operations
void push(char c) {
    if (top == MAX - 1) {
        printf("Operator stack overflow\n");
        exit(1);
    }
    stack[++top] = c;
}

char pop() {
    if (top == -1) {
        printf("Operator stack underflow\n");
        exit(1);
    }
    return stack[top--];
}

char peek() {
    return (top == -1) ? '\0' : stack[top];
}

void pushVal(int val) {
    if (valTop == MAX - 1) {
        printf("Value stack overflow\n");
        exit(1);
    }
    valStack[++valTop] = val;
}

int popVal() {
    if (valTop == -1) {
        printf("Value stack underflow\n");
        exit(1);
    }
    return valStack[valTop--];
}

// Precedence and associativity
int precedence(char op) {
    switch (op) {
        case '^': return 3;
        case '*':
        case '/': return 2;
        case '+':
        case '-': return 1;
        default: return 0;
    }
}

int isRightAssociative(char op) {
    return op == '^';
}

// Infix to Postfix conversion
void infixToPostfix(char *infix, char *postfix) {
    int i = 0, j = 0;
    char token;

    while (infix[i] != '\0') {
        if (isdigit(infix[i])) {
            // Append the full number to postfix
            while (isdigit(infix[i])) {
                postfix[j++] = infix[i++];
            }
            postfix[j++] = ' ';
            continue;
        } else if (infix[i] == '(') {
            push(infix[i]);
        } else if (infix[i] == ')') {
            while (peek() != '(') {
                postfix[j++] = pop();
                postfix[j++] = ' ';
            }
            pop(); // pop '('
        } else if (strchr("+-*/^", infix[i])) {
            while (top != -1 &&
                   ((precedence(peek()) > precedence(infix[i])) ||
                    (precedence(peek()) == precedence(infix[i]) && !isRightAssociative(infix[i]))) &&
                   peek() != '(') {
                postfix[j++] = pop();
                postfix[j++] = ' ';
            }
            push(infix[i]);
        }
        i++;
    }

    while (top != -1) {
        postfix[j++] = pop();
        postfix[j++] = ' ';
    }

    postfix[j - 1] = '\0';  // remove trailing space and null terminate
}

// Postfix evaluation
int evaluatePostfix(char *postfix) {
    int i = 0;
    while (postfix[i] != '\0') {
        if (isdigit(postfix[i])) {
            int num = 0;
            while (isdigit(postfix[i])) {
                num = num * 10 + (postfix[i++] - '0');
            }
            pushVal(num);
        } else if (postfix[i] != ' ') {
            int val2 = popVal();
            int val1 = popVal();
            switch (postfix[i]) {
                case '+': pushVal(val1 + val2); break;
                case '-': pushVal(val1 - val2); break;
                case '*': pushVal(val1 * val2); break;
                case '/': pushVal(val1 / val2); break;
                case '^': pushVal((int)pow(val1, val2)); break;
                default:
                    printf("Unknown operator: %c\n", postfix[i]);
                    exit(1);
            }
        }
        i++;
    }
    return popVal();
}

int main() {
    char infix[MAX];
    char postfix[MAX];

    printf("Enter an infix expression : ");
    if (scanf("%99s", infix) != 1) {
        printf("Invalid input\n");
        return 1;
    }

    infixToPostfix(infix, postfix);

    printf("Postfix Expression: %s\n", postfix);
    int result = evaluatePostfix(postfix);
    printf("Result: %d\n", result);

    return 0;
}

