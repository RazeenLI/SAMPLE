import json

with open('Sam.json', 'r') as FILE:
    DATA = json.load(FILE)
    print(DATA)