**简介**:该笔记主要记录自学Python过程中一些更加深入的知识，学习和理解面向对象编程相关概念 和文件相关操作

​																																							author:  LZY

# 1.Python面向对象编程

**OOB**(Object Oriented Programming)

**对象**：对象是可以接收消息的实体，面向对象编程就是通过给对象发消息达到解决问题的目标

> 对象  =  数据  +  函数（方法）

**类**：将一大类对象共同的特征（动态特征和静态特征）抽取出来之后得到的一个抽象概念

面向对象的三大支柱：**封装**、**继承**和**多态**



## 类的使用

一般，使用 class 语句来创建一个新类，class之后为类的名称(通常首字母**大写**)并以冒号结尾,例如：

> class Test:
>
> class Test():
>
> class Test (object):

不加括号的，或者加括号未继承其他类的是**经典类（旧式类）** ，加括号继承其他类或者Object的是**新式类**

在多继承中，经典类**深度优先**,新式类是**广度优先**

**python3中都是新式类**



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

### 普通方法
(实例方法)

一般方法，即不加任何修饰的，直接用def定义的方法。如：

~~~python
class A():
    def __init__(self, name, age):
        self.name = name
        self.age = age
 
    def get_name(self):
        print('my name is', self.name)
 
    def get_age(self):
        print(f'i am {self.age} years old')、
        
        
    if __name__ == '__main__':
	    a = A('tom',19)#实例化，用类创建了一个具体对象
	    a.get_name()  # my name is tom
	    a.get_age() # i am 19 years old    
~~~



`class A()` 中，` __init__()`是一个特殊的方法，相当于对A进行初始化，`__init__` 中的**self**是对象A**本身**，name和age是它们的**形参**。
​	
​	**每次调用方法之前需要对类进行实例化，即创建对象**



### 静态方法

（staticmethod方法）

  经过staticmethod修饰过的类方法无需[实例化](https://m.py.cn/faq/python/12659.html)即可被调用，不需要**创建对象**即可使用，而且该类方法不再需要self作为第一参数。

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

  

  这样做的好处是，以后重构类的时候不需要修改init函数，只要额外添加需要处理的函数，然后使用@staticmethod修饰即可。

 **静态方法**，其实就是我们学过的**函数**，和函数唯一的区别是，静态方法定义在类这个空间（**类命名空间**）中，而函数则定义在程序所在的空间（**全局命名空间**）中。

静态方法没有类似 self、cls 这样的特殊参数，因此 Python 解释器不会对它包含的参数做任何类或对象的绑定。也正因为如此，类的静态方法中**无法**调用任何**类属性**和**类方法**。



### 类方法
（classmethod 修饰的方法）。

**类方法**经 classmethod 修饰后无需[实例化](https://m.py.cn/faq/python/12659.html)即可被调用，而且该类方法的第一参数不再是self，而是**cls**，表示类本身。

~~~python

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
~~~

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

简单的说，类和类之间的关系有三种：is-a、has-a和use-a关系。

- is-a关系也叫**继承**或泛化，比如学生和人的关系、手机和电子产品的关系都属于继承关系。
- has-a关系通常称之为**关联**，比如部门和员工的关系，汽车和引擎的关系都属于关联关系；关联关系如果是整体和部分的关联，那么我们称之为聚合关系；如果整体进一步负责了部分的生命周期（整体和部分是不可分割的，同时同在也同时消亡），那么这种就是最强的关联关系，我们称之为合成关系。
- use-a关系通常称之为**依赖**，比如司机有一个驾驶的行为（方法），其中（的参数）使用到了汽车，那么司机和汽车的关系就是依赖关系。



### 继承

面向对象编程 (OOP) 语言的一个主要功能就是“继承”。继承是指这样一种能力：它可以使用**现有类**的**所有功能**，并在无需重新编写原来的类的情况下对这些功能进行**扩展**。

继承是实现**代码复用**的一种手段

通过**继承**创建的新类称为“**子类**”或“**派生类**”，**被继承**的类称为“**基类**”、“**父类**”或“**超类**”，继承的过程，就是从一般到特殊的过程。在某些 OOP 语言中，一个子类可以继承多个基类。但是一般情况下，**一个子类只能有一个基类**，要实现多重继承，可以通过多级继承来实现。

**object**是python中的**基类**, 所有类均继承自此基类

```python
class Father(object):
    def __init__(self, name):
        self.name=name
        print ( "name: %s" %( self.name) )
    def getName(self):
        return 'Father ' + self.name
 
class Son(Father):
    def getName(self):
        return 'Son '+self.name
 
if __name__=='__main__':
    son=Son('runoob')
    print ( son.getName() )
```



继承概念的实现方式主要有2类：**实现继承**、**接口继承**。

1. **实现继承**是指使用**基类**的属性和方法而无需额外编码的能力。
2. **接口继承**是指仅使用属性和方法的名称、但是子类必须提供实现的能力(子类重构爹类方法)。

**参考资料：**

[python类的继承 ](https://www.cnblogs.com/bigberg/p/7182741.html)



# 2.文件



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

