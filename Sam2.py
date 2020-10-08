import json

DATA = {
    'name':
    [
        '1',
        '2',
        '3',
        '4',
    ],
    'year':
    [
        '12',
        '11',
        '13',
        '14',
    ]
}

with open('Sam.json', 'w') as FILE:
    json.dump(DATA, FILE)