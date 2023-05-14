N, K = map(int, input().split())
A = list(map(int, input().split()))

A.sort()
window_start = 0
min_removals = N

for window_end in range(N):
    window_start = 0
    while A[window_end] - A[window_start] > K:
        window_start += 1
    num_removals = N - (window_end - window_start + 1)
    min_removals = min(min_removals, num_removals)

print(min_removals)
