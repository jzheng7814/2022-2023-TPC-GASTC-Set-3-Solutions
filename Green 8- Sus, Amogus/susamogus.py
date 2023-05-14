N = int(input())

for i in range(1, N + 1):
    printed = False

    if i % 3 == 0:
        print('Sus', end='')
        printed = True
    
    if i % 5 == 0:
        print('Amogus', end='')
        printed = True
    
    if printed:
        print()