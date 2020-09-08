import sys

word = sys.argv[1]
start = (int)(sys.argv[2])
end = (int)(sys.argv[3])
sign = 0
i = 0

while i < end :
    print(word[start],end='')
    if sign :
        start -= 1
        if start == 0 :
            sign = 0
    else :
        start += 1
        if start == len(word) - 1 :
            sign = 1
    i += 1
print()