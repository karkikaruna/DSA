import time

def fib(n):
    if n <= 1:
        return n
    return fib(n - 1) + fib(n - 2)

n = int(input("Enter the value of n: "))

start1 = time.time()
result1 = fib(n)
end1 = time.time()
print(f"The nth fibonacci number is : {result1} | Time: {end1 - start1:.6f} seconds")





