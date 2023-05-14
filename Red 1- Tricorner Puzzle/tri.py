from queue import Queue

step = [(0,1), (1,0), (0,-1), (-1,0)]

line = input().split()
N = int(line[0])
K = int(line[1])

walls = dict()

for i in range(K):
    line = input().split()
    x_wall_start = int(line[0])
    y_wall_start = int(line[1])
    x_wall_end = int(line[2])
    y_wall_end = int(line[3])

    if x_wall_start == x_wall_end:
        for j in range(y_wall_start, y_wall_end+1):
            walls[(x_wall_start, j)] = 0
    else:
        for j in range(x_wall_start, x_wall_end+1):
            walls[(j, y_wall_start)] = 0

visited = [walls.copy(), walls.copy(), walls.copy()]
q = [Queue(), Queue(), Queue()]

for i in range(3):
    line = input().split()
    start = (int(line[0]), int(line[1]))
    q[i].put((start, 0))
    visited[i][start] = 0

def valid(coord, i):
    if coord[0] < 0 or coord[0] >= N or coord[1] < 0 or coord[1] >= N \
        or coord in visited[i]:
        return False
    return True

res = -2
cur_step = 0
while res == -2:
    for i in range(3):
        while True:
            if q[i].empty():
                print(-1)
                quit()

            if q[i].queue[0][1] == cur_step:
                break

            cur = q[i].get()

            if cur[0] in visited[0] and cur[0] in visited[1] and cur[0] in visited[2]:
                res = max((visited[0][cur[0]], visited[1][cur[0]], visited[2][cur[0]]))
                print(res)
                quit()

            for j in range(4):
                next = (cur[0][0]+step[j][0], cur[0][1]+step[j][1])
                if valid(next, i):
                    q[i].put((next, cur[1]+1))
                    visited[i][next] = cur[1]+1
    cur_step += 1

print(res)
# for i in range(3):
#     print(i)
#     for key in visited[i]:
#         print("\t", key, visited[i][key])
#     print()