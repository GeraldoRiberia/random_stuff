dct = {49 : {'name' : 'Asbir Kallada', 'DS' : 90,'SE':80,'OOPJ': 80 }, 13 : {'name':'Adish K T', 'DS':90, 'SE': 87, 'OOPJ':92}, 12:{'name' : 'Adisankar L', 'DS' : 90, 'SE':77, 'OOPJ':84}, 57 : {'name': 'Benson B Varghese','DS' : 86,'SE':89,'OOPJ':84}}
max = {'DS':{'mark':0,'name':'NULL'}, 'SE':{'mark':0, 'name':'NULL'},'OOPJ':{'mark':0,'name':'NULL'}}
for i in dct:
    if(dct[i]['DS'] > max['DS']['mark']):
        max['DS']['mark'] = dct[i]['DS']
        max['DS']['name'] = dct[i]['name']
    if(dct[i]['SE'] > max['SE']['mark']):
        max['SE'] = dct[i]['SE']
        max['SE']['name'] = dct[i]['name']
    if(dct[i]['OOPJ'] > max['OOPJ']['mark']):
        max['OOPJ'] = dct[i]['OOPJ']
        max['OOPJ']['name'] = dct[i]['name']
print(max)