#include <stdio.h>
#include <stdlib.h>

struct list {
    int data;
    struct list *next;
};

struct list *first = NULL, *last = NULL;

void insertAtBeg(int ele) {
    struct list *Newnode;
    Newnode = (struct list *)malloc(sizeof(struct list));
    Newnode->next = NULL;
    Newnode->data = ele;

    if (first == NULL) {
        first = last = Newnode;
    } else {
        Newnode->next = first;
        first = Newnode;
    }
}

void insertAtEnd(int ele) {
    struct list *Newnode;
    Newnode = (struct list *)malloc(sizeof(struct list));
    Newnode->next = NULL;
    Newnode->data = ele;

    if (first == NULL) {
        first = last = Newnode;
    } else {
        last->next = Newnode;
        last = Newnode;
    }
}

void insertAtPos(int ele, int pos) {
    struct list *Newnode, *temp;
    int i;

    if (pos == 1) {
        insertAtBeg(ele);
        return;
    }

    Newnode = (struct list *)malloc(sizeof(struct list));
    Newnode->data = ele;
    Newnode->next = NULL;

    if (first == NULL) {
        printf("List is empty. Inserting at position 1.\n");
        first = last = Newnode;
        return;
    }

    temp = first;
    for (i = 1; i < pos - 1 && temp != NULL; i++) {
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Invalid position.\n");
        free(Newnode);
        return;
    }

    Newnode->next = temp->next;
    temp->next = Newnode;
    if (Newnode->next == NULL) {
        last = Newnode;
    }
}

void deleteBeg() {
    struct list *temp;
    if (first == NULL) {
        printf("List is empty\n");
    } else {
        temp = first;
        first = first->next;
        if (first == NULL) {
            last = NULL;
        }
        free(temp);
    }
}

void deleteEnd() {
    struct list *temp;
    if (first == NULL) {
        printf("List is empty\n");
    } else if (first->next == NULL) {
        free(first);
        first = last = NULL;
    } else {
        temp = first;
        while (temp->next != last) {
            temp = temp->next;
        }
        free(last);
        last = temp;
        last->next = NULL;
    }
}

void deletePos(int pos) {
    struct list *temp, *tempp;
    int i;

    if (first == NULL) {
        printf("List is empty\n");
        return;
    }

    if (pos == 1) {
        deleteBeg();
        return;
    }

    temp = first;
    for (i = 1; i < pos - 1 && temp != NULL; i++) {
        temp = temp->next;
    }

    if (temp == NULL || temp->next == NULL) {
        printf("Invalid position\n");
        return;
    }

    tempp = temp->next;
    temp->next = tempp->next;

    if (tempp == last) {
        last = temp;
    }

    free(tempp);
}

void search(int s) {
    struct list *temp = first;
    int flag = 0;

    if (first == NULL) {
        printf("List is Empty\n");
        return;
    }

    while (temp != NULL) {
        if (temp->data == s) {
            flag = 1;
            printf("Element Found\n");
            return;
        }
        temp = temp->next;
    }

    if (flag == 0) {
        printf("Element Not Found!\n");
    }
}

void display() {
    struct list *temp;
    if (first == NULL)
        printf("EMPTY LIST!\n");
    else {
        temp = first;
        while (temp != NULL) {
            printf("%d -> ", temp->data);
            temp = temp->next;
        }
        printf("NULL\n");
    }
}

int main() {
    int ele, pos, choice;

    while (1) {
        printf("\n---------------Menu----------------\n");
        printf("Press 1 to insert at the beginning.\n");
        printf("Press 2 to insert at the end.\n");
        printf("Press 3 to insert at a specific position.\n");
        printf("Press 4 to delete from the beginning.\n");
        printf("Press 5 to delete from the end.\n");
        printf("Press 6 to delete from a specific position.\n");
        printf("Press 7 to search for an element.\n");
        printf("Press 8 to display the list.\n");
        printf("Press 9 to exit.\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter element to insert at beginning: ");
                scanf("%d", &ele);
                insertAtBeg(ele);
                break;
            case 2:
                printf("Enter element to insert at end: ");
                scanf("%d", &ele);
                insertAtEnd(ele);
                break;
            case 3:
                printf("Enter element and position to insert: ");
                scanf("%d%d", &ele, &pos);
                insertAtPos(ele, pos);
                break;
            case 4:
                deleteBeg();
                break;
            case 5:
                deleteEnd();
                break;
            case 6:
                printf("Enter position to delete: ");
                scanf("%d", &pos);
                deletePos(pos);
                break;
            case 7:
                printf("Enter element to search: ");
                scanf("%d", &ele);
                search(ele);
                break;
            case 8:
                display();
                break;
            case 9:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice, please try again!!\n");
        }
    }

    return 0;
}
