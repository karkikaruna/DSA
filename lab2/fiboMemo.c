#include <stdio.h>
#define MAX 20
long table[MAX];  

void initialize() {
    for (int i = 0; i < MAX; i++) {
        table[i] = -1;
    }
}

long fibo(int n) {
    if (n <= 0)
        return 0;  
    if (n == 1 || n == 2) 
        return 1;

    if (table[n] != -1) {
        return table[n];  
    }

    table[n] = fibo(n - 1) + fibo(n - 2); 
    return table[n];
}

int main() {
    initialize();

    int n;
    printf("Enter a Fibonacci term to compute (1 to %d): ", MAX - 1);
    scanf("%d", &n);

    if (n < 1 || n >= MAX) {
        printf("Invalid input! Please enter a number between 1 and %d.\n", MAX - 1);
        return 1;
    }

    long result = fibo(n);
    printf("Fibonacci(%d) = %ld\n", n, result);

    return 0;
}

