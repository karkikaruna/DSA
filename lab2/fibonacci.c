#include <stdio.h>

int fibo(int n) {
    if ((n == 1) || (n == 2)) {
        return 1;
    } else {
        return (fibo(n - 1) + fibo(n - 2));
    }
}

int main() {
    int n, result;
    printf("Enter value: \n");
    scanf("%d", &n);
    result = fibo(n);
    
    printf("The %dth fibonacci number is %d\n", n, result);
    return 0;
}
