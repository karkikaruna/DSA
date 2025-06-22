#include <stdio.h>

void bubblesort(int A[], int n) {
    int i, j, temp;
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (A[j] > A[j + 1]) {
                temp = A[j];
                A[j] = A[j + 1];
                A[j + 1] = temp;
            }
        }
    }
}

int main() {
    int A[20], n, i;

    printf("Enter how many elements you want to sort:\n");
    scanf("%d", &n);

    if (n > 20) {
        printf("You can enter up to 20 elements only.\n");
        return 1;
    }

    printf("Enter elements to sort:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &A[i]);
    }

    printf("Entered elements are: ");
    for (i = 0; i < n; i++) {
        printf("%d ", A[i]);
    }
    printf("\n");

    bubblesort(A, n);

    printf("Sorted elements are:\n");
    for (i = 0; i < n; i++) {
        printf("%d ", A[i]);
    }
    printf("\n");

    return 0;
}
