result = []
finish = 7
T1 = 3
T2 = 7
for x in range(0, finish + 1):
    result.append((4*(x**2)+7*x+7)%8)
print('set(', end = '')
for x in range(0, finish + 1):
    if x == T1 or x == T2:
        print(str(result[x]) + ',', end='')
print(')')
print()
print('set(', end = '')
for x in range(0, finish + 1):
    if result[x] == T1 or result[x] == T2:
        print(str(x) + ',', end='')
print(')')
print()
for x in range(0, finish + 1):
    print('x = ' + str(x), end = '\t')
    print('f(x) = ' + str(result[x]))