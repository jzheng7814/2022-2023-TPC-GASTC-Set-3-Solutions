from math import sqrt

A, B, C = [int(i) for i in input().split()]

print(round((-B - round(sqrt(B ** 2 - 4 * A * C))) / 2), round((-B + round(sqrt(B ** 2 - 4 * A * C))) / 2))