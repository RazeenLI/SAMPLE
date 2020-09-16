a = input("please enter a number: ")

while (not a.isdigit()) :
    print("errer")
    a = input("please enter a number again: ")
else:
    a = (int)(a)
    print(a * a)