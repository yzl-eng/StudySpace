**简介**:该笔记主要记录自学Python过程中的基础知识，内容属于入门水平  

​																												author:  LZY

# 1.Python基础

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



---

# 2.容器型数据类型

**(用一个变量可以保存多个数据)**

**序列**是Python中最基本的数据结构。序列中的每个元素都分配一个数字 --它的位置，或索引，第一个索引是0，第二个索引是1，依此类推。

Python有6个序列的内置类型，但最常见的是列表和元组。包含**列表、元组、字符串、Unicode字符串、buffer对象和 xrange 对象**，可相互转换

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
list4 = []  #创建空列表
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
for i in range(len(nums)):# len() 方法返回对象（字符、列表、元组等）长度或项目个数
    print(nums[i])
#方式三
list2 = list(range(1, 10))
for i, x in enumerate(list2): #i为下标，x为元素
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
#sort( key=None, reverse=False)默认升序
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

<img src="图片素材/image-20211209151523954.png" alt="image-20211209151523954" style="zoom:200%;" />



## 元组（tuple）

不可变容器       [参考资料](https://www.runoob.com/python3/python3-tuple.html)

Python 的元组与列表类似，不同之处在于元组的元素不能修改。**元组**使用小括号 **( )**，**列表**使用方括号 **[ ]**。

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

```python
str = '这是一个字符串'
str2 = "这也是一个字符串"
```

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

- **find** ：检测 str 是否包含在 mystr中，如果指定 **beg**（开始） 和 **end**（结束） 范围，则检查是否包含在指定范围内，如果是返回开始的**索引值**，否则返回**-1**

	```python
	mystr.find(str, beg=0, end=len(string))
	```

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

<img src="图片素材/image-20211223190418491.png" alt="image-20211223190418491" style="zoom:200%;" />

**set()函数：**`set([iterable])`其中`iterable`为可迭代对象，能用`for...in... `循环的数据，包括列表



### 集合的运算

- **成员运算：**

  ```python
  print(1 in set1)
  print(1 not in set1)
  ```

  **集合的成员运算在效率上是远远高于列表的成员运算**

  

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

字典的每个键值 **key=>value** 对用**冒号"  :  "** 分割，每个**键值对**之间用**逗号" , "** 分割，整个字典包括在 **花括号" {} "** 中 ,格式如下所示：

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

	

### 字典的相关运算

```python
#示例
#dict = {key1 : value1, key2 : value2 }
dict = {'a': 1, 'b': 2, 'b': '3'}
```

- **访问字典的值**

  ```python
  print "dict['a'] = ", dict['a']
  print "dict['b'] = ", dict['b']
  #结果为
  #dict['a'] = 1
  #dict['b'] = 2
  ```

  **keys()方法**

   ~~`keys( )` 函数以**列表**返回一个字典所有的键。`dict.key()`~~

  

  **values()方法**

  values() 方法返回一个[视图对象](https://blog.csdn.net/weixin_39705435/article/details/110488026)。

  [dict.keys()](https://www.runoob.com/python3/python3-att-dictionary-keys.html)、dict.values() 和 [dict.items()](https://www.runoob.com/python3/python3-att-dictionary-items.html) 返回的都是视图对象（ view objects），提供了字典实体的动态视图，这就意味着字典改变，视图也会跟着变化。

  **视图**只是字典上的…视图(窗口)，即使字典发生**更改**，它也会显示字典的内容。它们提供了不同于列表的特性：**键列表**在给定的时间点包含字典键的**copy**，而视图是**动态**的，获取速度更快，因为它不必复制任何数据(键或值)就可以创建。

  视图对象**不是**列表，不支持kong索引，可以使用 `list()` 来**转换**为列表。

  我们不能对视图对象进行任何的修改，因为字典的视图对象都是**只读**的。

- **修改字典**

	```python
	dict['a'] = 0  #对字典元素值更新
	dict['d'] = 4  #添加新的键值对
	```

- **删除字典元素**

	```python
	del dict['a']   #删除键是'a'的条目
	dict.clear()    #清空字典所有条目
	del dict        #删除字典
	```

	

###  字典相关操作

- **将JSON格式转换为Python中字典**

	> json 模块  --->  loads()函数

	```python
	import json
	data = """{
	  "code": 200,
	  "msg": "success",
	  "newslist": [
	    {
	      "id": "e0b9638ae82dae48ef286d14dfb6c4d7",
	      "ctime": "2021-03-18 16:35",
	      "title": "《Apex英雄》封禁700多个高段位开挂者隔热板Bug目前正在修复",
	      "description": "在对抗作弊和开挂的永无止境的战争中，重生娱乐采取了又一轮措施，其最新一轮封禁已经奏效。继去年11月419名顶级分段的《Apex英雄》玩...",
	      "source": "新浪电竞",
	      "picUrl": "//n.sinaimg.cn/games/639/w400h239/20210318/c25b-kmkptxe6554750.jpg",
	      "url": "//dj.sina.com.cn/article/kknscsi7936390.shtml"
	    },
	    {
	      "id": "a8aa36675df83fee7b43c4730515754d",
	      "ctime": "2021-03-18 16:35",
	      "title": "2021LCK春季赛季后赛晋级形势：T1惊险晋级",
	      "description": "2021年LCK春季常规赛的赛程已经进入尾声，对于正在冲击季后赛的队伍来说只剩最后两周的时间。今年LCK赛区完成了联盟化改革，首次将季...",
	      "source": "新浪电竞",
	      "picUrl": "//n.sinaimg.cn/games/639/w400h239/20210318/65f4-kmkptxe6613024.jpg",
	      "url": "//dj.sina.com.cn/article/kknscsi7939778.shtml"
	    },
	    {
	      "id": "49714f4a573af0de61b94923f29c5302",
	      "ctime": "2021-03-18 16:35",
	      "title": "ENCE、G2锁定出线Vitality需险中求生",
	      "description": "ESLProLeagueS13的小组赛正在如火如荼的进行，目前B组还有最后一轮比赛，比赛将于3月19日的凌晨2点钟开赛三场同开。",
	      "source": "新浪电竞",
	      "picUrl": "//n.sinaimg.cn/games/639/w400h239/20210312/0d54-kmeeiut0904585.jpg",
	      "url": "//dj.sina.com.cn/article/kknscsi7942016.shtml"
	    }
	  ]
	}"""
	news_dict = json.loads(data)
	news_list = news_dict['newslist']
	for news in news_list:
	    print(news)
	```

	

	> requests第三方库获取网络数据





---

# 3.函数

函数是组织好的，可重复使用的，用来实现单一，或相关联功能的代码段。

函数能提高应用的模块性，和代码的重复利用率。你已经知道Python提供了许多内建函数，比如print()。但你也可以自己创建函数，这被叫做用户自定义函数。

- Python中的函数是**一等函数**：

	1. 函数可作为函数的参数

	1. 函数可以作为函数的返回值

	1. 函数可以赋值给变量
- 如果把函数作为函数的参数或返回值，这种玩法通常称为**高阶函数**
- 设计函数时，一定要注意函数的**无副作用性**（调用函数不影响传入参数）
- 枚举是定义符号常量的最佳选择
- 符号常量总是优于字面常量

## 函数的定义

**定义规则：**

- 函数代码块以 **def** 关键词开头，后接函数标识符名称和圆括号**()**。
- 任何传入参数和自变量必须放在圆括号中间。圆括号之间可以用于定义参数。
- 函数的第一行语句可以选择性地使用文档字符串—用于存放函数说明。
- 函数内容以冒号起始，并且缩进。
- **return [表达式]** 结束函数，选择性地返回一个值给调用方。不带表达式的return相当于返回 None。

**示例：**

```python
 def function_name( parameters ):
  	 """函数_文档字符串"""
  	 function_suite
   	return [expression]
```



##  函数参数

Python传入参数的方法有：**位置参数**、**默认参数**、**可变参数**、**关键字参数**和**命名关键字参数**、以及各种参数调用的组合

- **位置参数**：调用函数时根据函数定义的参数位置来传递参数。
- **默认参数**：在函数声明时，指定形参的默认值，调用时可不传入改参数（使用默认值）
- **可变参数**：定义函数时，有时候我们不确定调用的时候会传递多少个参数(不传参也可以)。此时，可用包裹(packing)位置参数，或者包裹关键字参数，来进行参数传递，会显得非常方便。
- **关键字参数**：调用时指定参数的名称，且与函数声明时的参数名称一致。使用关键字参数允许函数调用时参数的顺序与声明时不一致，仅根据参数的指定进行赋值



## 函数调用

1. **模块的函数调用**
	- **import**  模块名
		模块名.函数名
	- **from**  模块名  **import**  函数名 （**as 别名**）
		python调用另一个.py文件中的类和函数
		同一文件夹下的调用



## lambda函数

Python Lambda函数是没有任何名称的函数。它们也称为匿名或无名功能。“ lambda”一词不是名称，而是关键字。此关键字指定后面的函数是匿名的。

**语法：**

lambda参数：表达式

**演示：**

```python
p = lambda x,y:x+y
print(p(4,6))
```





# 4.面向对象编程

**对象**：对象是可以接收消息的实体，面向对象编程就是通过给对象发消息达到解决问题的目标

> 对象  =  数据  +  函数（方法）

**类**：将一大类对象共同的特征（动态特征和静态特征）抽取出来之后得到的一个抽象概念



## 类的使用

一般，使用 class 语句来创建一个新类，class之后为类的名称(通常首字母大写)并以冒号结尾,例如：

1. **类的定义**

	```python
	class Student:
	    # 数据抽象（属性）
	    def __init__(self, name, age):
	        self.name = name
	        self.age = age
	
	    # 行为抽象（方法）
	    def eat(self):
	        print(f'{self.name}正在吃饭。')
	
	    def study(self,couse_name):
	        print(f'{self.name}正在学习{couse_name}')
	    
	    def play(self,game_name):
	        print(f'{self.name}正在玩{game_name}')
	
	    def drink_liquer(self):
	        if self.age<18:
	            print(f'{self.name}未满十八岁只能坐小孩那桌')
	        else:
	            print(f'{self.name}正在喝酒')
	        
	```

​	类中可以定义所使用的方法，类的**方法**与普通的**函数**只有一个特别的**区别**——它们必须有一个额外的第一个参数名称, 按照惯例它的名称是 **self**；

2. **创建对象**

	```python
	#创建对象（构造器语法）
	stu1 = Student('王二', 18)
	stu2 = Student('张三', 15)
	```

3. **调用对象方法**

	```python
	# 调用对象方法
	stu1.study('英语')
	stu1.eat()
	
	stu2.drink_liquer()
	```

<img src="图片素材/image-20220112113221012.png" alt="image-20220112113429558" style="zoom:200%;height:40px;width:500px;" />






## Python类的三种方法

我们在类里面写的函数，通常称之为方法，它们基本都是发给对象的消息。但有的时候，我们的消息并不想发给对象，而是希望发给这个类（类本身也是一个对象）。

这个时候，我们可以使用静态方法或类方法

1. **普通方法**(实例方法)

	  一般方法，即不加任何修饰的，直接用def定义的方法。如：

	  ```python
	class A():
	    def __init__(self, name, age):
	        self.name = name
	        self.age = age
	 
	    def get_name(self):
	        print('my name is', self.name)
	 
	    def get_age(self):
	        print(f'i am {self.age} years old')
	        
	        
	if __name__ == '__main__':
	    a = A('tom',19)#实例化
	    a.get_name()  # my name is tom
	    a.get_age() # i am 19 years old
	  ```

	  class A() 中，` __init__()`是一个特殊的方法，相当于对A进行初始化，`__init__` 中的self是对象A本身，name和age是它们的形参。

	每次调用方法之前需要对类进行实例化




2. **静态方法**（staticmethod方法）

  经过staticmethod修饰过的类方法无需[实例化](https://m.py.cn/faq/python/12659.html)即可被调用，而且该类方法不再需要self作为第一参数。

  ```python
  class B():
      @staticmethod
      def get_name(name):
          print('my name is %s' % name)
   
      @staticmethod
      def get_age(age):
          print(f'i am %s years old' % age)
          
   
  if __name__ == '__main__':
      B.get_name('tom')  # my name is tom
      B.get_age(19) # i am 19 years old
  ```

  

  这样做的好处是，以后重构类的时候不需要修改init函数，只要额外添加需要处理的函数，然后使用@staticmethod修饰即可。=

  

3. **类方法**（classmethod 修饰的方法）。类方法经 classmethod 修饰后无需[实例化](https://m.py.cn/faq/python/12659.html)即可被调用，而且该类方法的第一参数不再是self，而是**cls**，表示类本身。

	```python
	class C():
	    @classmethod
	    def get_name(cls, name):
	        print(cls)  # <class '__main__.C'>
	        print('my name is %s' % name)
	 
	    @classmethod
	    def get_age(cls, age):
	        print(f'i am %s years old' % age)
	        
	  
	if __name__ == '__main__':
	    C.get_name('tom')  # my name is tom
	    C.get_age(19) # i am 19 years old
	```



**@staticmethod** 与 **@classmethod**在Python中称为 **装饰器**， 
用来修饰函数，相当于添加一个额外的功能，比如不再像普通函数那样进行实例化。 
通过使用装饰器可以让代码更加**整洁，易读**。用了修饰器之后，也可以进行实例化之后再调用，但是就显得多此一举了。

**参考资料：**

[Python 实例方法、类方法、静态方法的区别与作用](https://www.cnblogs.com/wcwnina/p/8644892.html)




## Python魔术方法

在Python中，所有以“__”双下划线包起来的方法，都统称为“Magic Method”，中文称『魔术方法』,例如类的初始化方法 __`__init__` ,Python中所有的魔术方法均在官方文档中有相应描述，但是对于官方的描述比较混乱而且组织比较松散。很难找到有一个例子。

- 魔术方法就是一个类中的方法，和普通方法唯一的不同是普通方法需要调用，而魔术方法是在特定时刻自动触发。

- 这些魔术方法的名字特定，不能更改，但是入口参数的名字可以自己命名。

**基本魔术方法：**

1. `__init__(self,...)`构造器，当一个实例被创建的时候调用的初始化方法

	```python
	class A():
	    def __init__(self, name, age):
	        self.name = name
	        self.age = age
	```

2. `__del__(self)`构造器，当一个实例被销毁的时候调用的方法

**参考资料：**

[Python中的魔术方法详解](https://www.cnblogs.com/pyxiaomangshe/p/7927540.html)

[ 如何最简单、通俗地理解Python的魔术方法](https://www.zhihu.com/question/432522820)



## 两个类之间的关系

继承 

关联 强关联-->聚合和合成

依赖



多态



## 继承

面向对象编程 (OOP) 语言的一个主要功能就是“继承”。继承是指这样一种能力：它可以使用现有类的所有功能，并在无需重新编写原来的类的情况下对这些功能进行扩展。

继承是实现**代码复用**的一种手段

通过继承创建的新类称为“**子类**”或“**派生类**”，被继承的类称为“**基类**”、“**父类**”或“**超类**”，继承的过程，就是从一般到特殊的过程。在某些 OOP 语言中，一个子类可以继承多个基类。但是一般情况下，**一个子类只能有一个基类**，要实现多重继承，可以通过多级继承来实现。

继承概念的实现方式主要有2类：**实现继承**、**接口继承**。

1. 实现继承是指使用基类的属性和方法而无需额外编码的能力。
2. 接口继承是指仅使用属性和方法的名称、但是子类必须提供实现的能力(子类重构爹类方法)。

**参考资料：**

[python类的继承 ](https://www.cnblogs.com/bigberg/p/7182741.html)







# 5.文件



文件MD5码

```python
from hashlib import md5

hasher = md5()
file = open('文件路径', 'rb')
try:
    data = file.read(512)
    while data:
	#update(arg)传入arg对象来更新hash的对象，
#重复调用update(arg)方法，是会将传入的arg参数进行拼接
        hasher.update(data)
        data = file.read(512)
finally:
    file.close()
#转化成16进制输出
print(hasher.hexdigest())

```

