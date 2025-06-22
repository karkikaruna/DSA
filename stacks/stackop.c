#include <stdio.h>
#include <stdlib.h>

#define MAX 20
#define True 1
#define False 0

struct stack {
    int tos;
    int data[MAX];
};

int isEmpty(struct stack *s) {
    return (s->tos == -1) ? True : False;
}

int isFull(struct stack *s) {
    return (s->tos == MAX - 1) ? True : False;
}

void push(struct stack *s, int element) {
    if (isFull(s)) {
        printf("Stack overflow\n");
    } else {
        s->tos++;
        s->data[s->tos] = element;
    }
}

int pop(struct stack *s) {
    if (isEmpty(s)) {
        printf("Stack underflow.\n");
        return -1; 
    } else {
        int element = s->data[s->tos];
        s->tos--;
        return element;
    }
}

void display(struct stack *s) {
    if (isEmpty(s)) {
        printf("Stack is empty.\n");
    } else {
        printf("Stack elements are:\n");
        for (int i = 0; i <= s->tos; i++) {
            printf("%d ", s->data[i]);
        }
        printf("\n");
    }
}

int main() {
    struct stack s;
    s.tos = -1;

    int element, choice, result;

    while (1) {
        printf("\n------------------Menu---------------\n");
        printf("Enter 1 to push element into the stack.\n");
        printf("Enter 2 to pop element from the stack.\n");
        printf("Enter 3 to check if stack is full.\n");
        printf("Enter 4 to check if stack is empty.\n");
        printf("Enter 5 to display stack elements.\n");
        printf("Enter 6 to exit.\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter element to push: ");
                scanf("%d", &element);
                push(&s, element);
                break;
            case 2:
                result = pop(&s);
                if (result != -1)
                    printf("%d is popped from the stack.\n", result);
                break;
            case 3:
                if (isFull(&s))
                    printf("Stack is full.\n");
                else
                    printf("Stack is not full.\n");
                break;
            case 4:
                if (isEmpty(&s))
                    printf("Stack is empty.\n");
                else
                    printf("Stack is not empty.\n");
                break;
            case 5:
                display(&s);
                break;
            case 6:
                printf("Exiting.....\n");
                exit(0);
            default:
                printf("Invalid choice.....\n");
        }
    }

    return 0;
}
