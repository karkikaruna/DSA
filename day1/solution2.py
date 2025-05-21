import time

def fib(n):
    if n <= 1:
        return n
    a, b = 0, 1
    for _ in range(2, n + 1):
        a, b = b, a + b
    return b

n = int(input("Enter the value of n: "))

start2 = time.time()
result2 = fib(n)
end2 = time.time()
print(f"The nth fibonacci number is: {result2} | Time: {end2 - start2:.6f} seconds")