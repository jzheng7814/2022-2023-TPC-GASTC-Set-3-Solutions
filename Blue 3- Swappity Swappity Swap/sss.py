A = input()
B = input()

if len(A) != len(B):
    print(-1)
    quit()

a = dict()
b = dict()

for c in A:
    a[c] = a.get(c, 0) + 1

for c in B:
    b[c] = b.get(c, 0) + 1

sum = 0
for key in set(list(a.keys()) + list(b.keys())):
    if (a.get(key, 0) + b.get(key, 0)) % 2 != 0:
        print(-1)
        quit()
    sum += abs(a.get(key, 0) - b.get(key, 0))

if sum % 4 != 0:
    print(-1)
else:
    print(int(sum/4))