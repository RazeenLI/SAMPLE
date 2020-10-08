import json

with open('Sam.json', 'r') as FILE:
    DATA = json.load(FILE)
    print(DATA)

FILE = open('Sam.json', 'r')
if FILE:
    DATA = json.load(FILE)
    print(DATA)