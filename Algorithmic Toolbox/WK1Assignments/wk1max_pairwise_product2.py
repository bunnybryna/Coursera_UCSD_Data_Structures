n = int(input())
a = [int(x) for x in input().split()]
assert(len(a) == n)

result = 0
max1 = 0
max2 = 0

for i in range(0, n):
    if a[i]>max1:
        max1 = a[i]
        if (i>=1) and (a[i-1]>max2):
            max2 = a[i-1]
    elif a[i]>max2:
        max2 = a[i]
print(max1, max2)        
print(result)
