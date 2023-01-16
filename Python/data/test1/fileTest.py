import csv

with open('resources/2018年北京积分落户数据.csv', encoding='utf-8') as file:
    reader = csv.reader(file, delimiter=',', quotechar='"')
    for row in reader:
        print(row)
