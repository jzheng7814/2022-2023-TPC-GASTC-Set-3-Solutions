line = input().split()
N = int(line[0])
K = int(line[1])

line = [int(x) for x in input().split()]

line.sort()

i = 0
j = N-1

while line[j]-line[i] > K:
    left = line[i+1]-line[i]
    right = line[j]-line[j-1]

    if left >= right:
        i += 1
    else:
        j -= 1

print(N-j+i-1)