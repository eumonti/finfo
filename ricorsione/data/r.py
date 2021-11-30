import random

arr = [round(random.uniform(1.0, 100.0), 2) for _ in range(1000)]
arr.sort()
for item in arr:
    print(item, end=" ")
print()
