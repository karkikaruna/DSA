import time
import math

#using binets formula
def fib(n):
    sqrt5 = math.sqrt(5)
    phi = (1 + sqrt5) / 2
    return round((phi ** n) / sqrt5)

n = int(input("Enter the value of n: "))

start3 = time.time()
result3 = fib(n)
end3 = time.time()
print(f" The nth fibonacci number is: {result3} | Time: {end3 - start3:.6f} seconds")