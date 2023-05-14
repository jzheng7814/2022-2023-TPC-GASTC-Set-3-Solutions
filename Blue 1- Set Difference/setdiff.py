N = int(input())
A = set([int(i) for i in input().split()])
B = set([int(i) for i in input().split()])

print(len(A.difference(B)))
