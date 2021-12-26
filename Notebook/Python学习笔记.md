# Python基础



## Python 打印输出三种模式

1.利用占位符格式化输出

```python
a=1,b=2;
print("%f+%f=%f" %(a, b, a+b))
```

2.利用f-String格式化（第二种格式化输出）（3.6版本，具有向上兼容）建议使用使打印更加好看

```python
print(f"{a}+{b}={a+b}")
```

3.利用format格式化输出format格式化（第三种格式化输出）（3.4版本，具有向上兼容）

```python
print("{}+{}={}".format(a, b, a+b))  # 不设置指定位置，按默认顺序

print("{1}+{0}={2}".format(b, a, a+b))  # 设置指定位置

print("名：{name}, 年龄：{age}".format(name="xxx", age="18"))
```



##  Python分支结构

**1. 双分支结构**

   ```python
   a = int(input("请输入一个数："))
   if a < 0:
       print(-a)
   else:
       print(a)
   #求绝对值
   ```

**2. 三分支结构**

  ```python
   if 表达式:
       语句块1
   elif 表达式:
       语句块2
   elif 表达式2:
       语句块3
   else:
       语句块4
   后续语句
  ```

   

## Python循环结构

**1.  for-in 循环**

举例：计算100以内奇数和

```python
sum = 0
#range的类型：range(起始位，结束位，步长)
for i in range(1, 101, 2):
    sum = sum+i
print(sum)
```

**2. while  循环**

举例：求1-100所有偶数

```python
count = 1
while count < 101:
　　result = count % 2
　　if result == 0:
　　　　print count
　　else:
　　　　pass
　　count = count + 1
```

与for-in循环的区别：

构造不知道具体循环次数的循环结构，推荐使用‘while’循环



## Python随机函数应用

- **random()函数**

  ``` python 
  import random
  
  random.random();
  ```

random() 方法返回随机生成的一个实数，它在[0,1)范围内。

random()是不能直接访问的，需要导入 random 模块，然后通过 random 静态对象调用该方法。

-  **randrange()函数**

	```python
	import random
	
	random.randrange ([start,] stop [,step])
	```

	start -- 指定范围内的开始值，包含在范围内

	stop -- 指定范围内的结束值，不包含在范围内。

	step -- 指定递增基数.

-  **choice()函数**

	**choices()**

	```python
	import random
	
	random.choice(x)
	```

	choice() 方法返回一个列表，元组或字符串的随机项。



参考资料：

[python举例说明随机函数的应用](https://blog.csdn.net/weixin_39959298/article/details/109622979)



# 容器型数据类型

**(用一个变量可以保存多个数据)**

**序列**是Python中最基本的数据结构。序列中的每个元素都分配一个数字 - 它的位置，或索引，第一个索引是0，第二个索引是1，依此类推。

Python有6个序列的内置类型，但最常见的是列表和元组。

序列都可以进行的操作包括**索引，切片，加，乘，检查**成员。



## 列表(list)

**列表**是最常用的Python数据类型，它可以作为一个方括号内的逗号分隔值出现。

列表的数据项不需要具有相同的类型

### 列表的创建

**创建一个列表**(字面量语法)，只要把逗号分隔的不同的数据项使用方括号**' [ ] '**括起来即可。如下所示

```python
list1 = ['physics', 'chemistry', 1997, 2000]
list2 = [1, 2, 3, 4, 5 ]
list3 = ["a", "b", "c", "d"]
```

**列表生成式(推导式)语法**		[参考资料](https://blog.csdn.net/xixlxl/article/details/79677405)

```python
#随机生成10个元素的列表
import random
nums = [random.randrange(1, 100) for _ in range(10)]
print(nums)
```

**列表函数**  

```python
list2 = list(range(1, 10))
print(list2)
```



### 列表元素循环

```python
#循环输出
nums = [1, 2, 3, 4, 5, 6]
#方式一
for num in nums:
    print(num)
#分隔    
print('-'*20)
#方式二
for i in range(len(nums)):
    print(nums[i])
#方式三
list2 = list(range(1, 10))
for i, x in enumerate(list2):
    print(i, x)
```



### 与列表相关的运算

```python
#合并列表元素
list1 = [1, 2, 3, 4]
list2 = [5, 6, 7]
temp = list1+list2
print(temp)

#删除列表元素
list1.pop()
list1.pop(1)
list1.remove('1')
del list1[2]

#清空列表元素
list2.clear()

#添加列表元素
list1.append('777')
list1.insert(1,'666')

#反转
list1.reverse()

#排序(可以修改reverse参数控制排升序或降序)
list1.sort()
#key = int
```

**列表切片操作**

​	**[start : end: step]**

   start:起始索引，从0开始

   end：结束索引,但是end-1为实际的索引值

   step：步长，步长为正时，从左向右取值。步长为负时，反向取值



### 嵌套列表

```python
text = [[0, 0, 1], [0, 0, 0], [0, 0, 0], [0, 0, 0]]
print(text)
text2 = [[0, 0, 1] for _ in range(4)]
print(text2)
```

运行结果

![image-20211209151523954](D:\WorkSpace\Notebook\图片素材\image-20211209151523954.png)



## 元组（tuple）

不可变容器       [参考资料](https://www.runoob.com/python3/python3-tuple.html)

Python 的元组与列表类似，不同之处在于元组的元素不能修改。元组使用小括号 **( )**，列表使用方括号 **[ ]**。

### 元组创建

```python
#元组定义
tup1 = ('Google', 'Apple', 'HUAWEI', 2021)
```

元组中只包含一个元素时，需要在元素后面添加逗号 **,** ，否则括号会被当作运算符使用：

```python
tup1 = (50,)
```



## 字符串(string)

字符串是 Python 中最常用的数据类型。我们可以使用引号(  **'**  或  **"**  )来创建字符串。

### 字符串性质判断

1、**S.isalnum()**或者str.isalnum(S)：判断字符串S是否全部由字母和数字组成，返回True/False  

2、**S.isalpha()**或者str.isalpha(S)：判断字符串S是否只由字母组成，返回True/False

3、**S.isdigit()**或者str.isdigit(S)：判断字符串S是否只由数字组成，返回True/False，负数的判断为false，因为“-”不是数字

4、**S.isupper()**或者str.isupper(S)：判断字符串S是否全部为大写字母，返回True/False

5、**S.islower()**或者str.islower(S)：判断字符串S是否全部为小写字母，返回True/False

6、**S.isspace()**或者str.isspace(S)：判断字符串S是否只由空格组成，返回True/False



- [ ] **任务：下面内容太复杂要修改**

```python
# Run this code to see a table of isX() behaviors
def p(test):
    print("True     " if test else "False    ", end="")
def printRow(s):
    print(" " + s + "  ", end="")
    p(s.isalnum())
    p(s.isalpha())
    p(s.isdigit())
    p(s.islower())
    p(s.isspace())
    p(s.isupper())
    print()
def printTable():
    print("  s   isalnum  isalpha  isdigit  islower  isspace  isupper")
    for s in "ABCD,ABcd,abcd,ab12,1234,    ,AB?!".split(","):
        printRow(s)
printTable()
```

**运行结果：**

```wiki
 s   isalnum  isalpha  isdigit  islower  isspace  isupper
 ABCD  True     True     False    False    False    True     
 ABcd  True     True     False    False    False    False    
 abcd  True     True     False    True     False    False    
 ab12  True     False    False    True     False    False    
 1234  True     False    True     False    False    False    
       False    False    False    False    True     False    
 AB?!  False    False    False    False    False    True
```

[资料来源](https://blog.csdn.net/xiaozhimonica/article/details/85272189)



### 字符串常见操作

- **find** ：检测 str 是否包含在 mystr中，如果是返回开始的索引值，否则返回-1
- **index**：跟find()方法一样，只不过如果str不在 mystr中会报一个异常.
- **count：**返回 str在start和end之间 在 mystr里面出现的次数
- **replace**：把 mystr 中的 str1 替换成 str2,如果 count 指定，则替换不超过 count 次.
- **split**：以 str 为分隔符切片 mystr，如果 maxsplit有指定值，则仅分隔 maxsplit 个子字符串



相关资料：[python 字符串常见的操作](https://blog.csdn.net/qq_40518671/article/details/89316446)



## 集合（Set）

集合（set）是一个**无序**的**不重复**元素序列

集合底层使用哈希存储

[参考资料](https://www.runoob.com/python3/python3-set.html)

### 集合的创建

可以使用大括号 **{ }** 或者 **set()** 函数创建集合，**注意：**创建一个空集合必须用 **set()** 而不是 **{ }**，因为 **{ }** 是用来创建一个空字典。

```python
set1 = {1, 2, 3, 1, 4, 1, 5}
set2 = set()
print(set1)
print(type(set2))
```

输出结果：

<img src="D:\WorkSpace\Notebook\图片素材\image-20211223190418491.png" alt="image-20211223190418491" style="zoom:150%;" />



### 集合的运算

- **成员运算：**

	```python
	print(1 in set1)
	print(1 not in set1)
	```

	集合的成员运算在效率上是远远高于列表的成员运算

- **交集：**

```python
print(list_1.intersection(list_2))
print(list_1 & list_2)
```

- **并集：**

```python
print(list_1.union(list_2))
print(list_1 | list_2)
```

- **差集：**

```python
print(list_1.difference(list_2))
print(list_1 - list_2)
```

- **对称差**：

```python
print(list_1.symmetric_difference(list_2))
print(list_1 ^ list_2)
```



### 集合基本操作

- **删除元素：**

```python
list_1.remove(3)#若元素不包含在集合中，会报错
list_1.discard(5)#若元素不包含在集合中，不会报错
list_1.pop()#随机删除
```

- **添加元素：**

```python
list_1.add(100) #添加一项
list_1.update([20,30,40])
```

参考资料：[python:集合及其运算](https://www.cnblogs.com/cansun/p/8040513.html?ivk_sa=1024320u)



## 字典(Dictionary)

字典是另一种可变容器模型，且可存储任意类型对象。

字典的每个键值 **key=>value** 对用冒号 **:** 分割，每个键值对之间用逗号 **,** 分割，整个字典包括在花括号 **{}** 中 ,格式如下所示：

> d = {key1 : value1, key2 : value2 }



### 字典的创建

1. **字面量语法**

	```python
	student1 = {
	    'id': 100,
	    'name': '张三',
	    'sex': True,
	    'birthday': '1991-02'
	}
	print(student1)
	```

2. **构造器函数**

	```python
	student2 = dict(id=101, name='李四', sex=True, birthday='1992-08')
	
	print(student2)
	```

3. **生成式语法**

	```python
	dict1 = {i: i ** 2 for i in range(1, 10)}
	print(dict1)
	```

	

### 字典的运算

