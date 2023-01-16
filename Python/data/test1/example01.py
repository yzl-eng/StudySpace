import xlrd

wb = xlrd.open_workbook('resources/阿里巴巴2020年股票数据.xls')
# 获取所有工作表名字
print(wb.sheet_names())
# 获取指定工作表---》worksheet
sheet = wb.sheet_by_name('股票数据')
# print(sheet)
# print(sheet.nrows, sheet.ncols)
# # 获取单元格中的数据
# print(sheet.row(0)[0].value)
# print(sheet.row_slice(0, start_colx=0, end_colx=8))
# # 获取指定列
# # print(sheet.col(4))
# print(sheet.col(4, start_rowx=1, end_rowx=11))
# # 获取单元格数据
# cell = sheet.cell(2, 2)
# print(type(cell))
# print(cell.value)

 
# 遍历整个表单
for row in range(1, sheet.nrows):
    for col in range(sheet.ncols):
        value = sheet.cell(row, col).value
        if col == 0:
            year, mouth, day, *_ = xlrd.xldate_as_tuple(value, 0)
            print(f'{year}年{mouth:0>2d}月{day:0>2d}日', end='\t')
        elif col==5:
            print(f'{int(value):>10d}',end='\t')
        else:
            print(f'{value:.2f}', end='\t')
    print()
