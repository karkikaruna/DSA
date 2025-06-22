#include <stdio.h>
int stepCount = 0;  
void towerOfHanoi(int n, char source, char temp, char destination) {
    if (n == 1) {
        printf("Move disk 1 from %c to %c\n", source, destination);
        stepCount++; 
        return;
    }
    towerOfHanoi(n - 1, source, destination, temp);
    printf("Move disk %d from %c to %c\n", n, source, destination);
    stepCount++;
    towerOfHanoi(n - 1, temp, source, destination);
}

int main() {
    int n;
    printf("Enter the number of disks: ");
    scanf("%d", &n);
    printf("Steps to solve Tower of Hanoi with %d disks:\n", n);
    towerOfHanoi(n, 'A', 'B', 'C');
    printf("\nTotal number of steps: %d\n", stepCount);
    return 0;
}

