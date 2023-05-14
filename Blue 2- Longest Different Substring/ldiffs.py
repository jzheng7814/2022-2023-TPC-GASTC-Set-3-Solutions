S = input()

s = 0
l = 1
ms = -1
ml = -1

for i, j in enumerate(S):
    if i == 0:
        continue

    if S[i] != S[i - 1]:
        l += 1
    else:
        if l > ml:
            ms = s 
            ml = l
        
        s = i
        l = 1

if l > ml:
    ms = s 
    ml = l

print(S[ms:ms + ml])