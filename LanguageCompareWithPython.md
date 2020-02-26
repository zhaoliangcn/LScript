# 与python 对比

基于python2.7



## HelloWorld

```python
#!/usr/bin/python
 
print("Hello, World!")
```

```c++
#scp
#scpeng
show:"Hello,World!"
```



## 注释

python 中单行注释采用#开头

多行注释使用三个单引号(''')或三个双引号(""")

```python
#!/usr/bin/python
# -*- coding: UTF-8 -*-
# 文件名：test.py


'''
这是多行注释，使用单引号。
这是多行注释，使用单引号。
这是多行注释，使用单引号。
'''

"""
这是多行注释，使用双引号。
这是多行注释，使用双引号。
这是多行注释，使用双引号。
"""
```



```c++
# L脚本语言的单行注释
x = y +z // L脚本语言支持C++风格的单行注释
```



## 字符串



Python 可以使用引号( **'** )、双引号( **"** )、三引号( **'''** 或 **"""** ) 来表示字符串

```python
word = 'word'
sentence = "这是一个句子。"
paragraph = """这是一个段落。
包含了多个语句"""
```

L脚本语言中，字符串只有一种表示方式 就是双引号

```c++
#scp
#scpeng
define:string,s,"这是一个字符串"
```

python的字符串支持切片，是用数组运算符 **[头下标:尾下标]** 来截取相应的字符串

```python
#!/usr/bin/python
# -*- coding: UTF-8 -*-
 
str = 'Hello World!'
 
print str           # 输出完整字符串
print str[0]        # 输出字符串中的第一个字符
print str[2:5]      # 输出字符串中第三个至第六个之间的字符串
print str[2:]       # 输出从第三个字符开始的字符串
print str * 2       # 输出字符串两次
print str + "TEST"  # 输出连接的字符串
```

L脚本语言中，通过字符串对象的getsubstring函数实现提取子串

通过+运算符可以实现字符串的链接

```c++
#scp
#scpeng
define:string,s,"Hello World!"
(s.getsubstring(0,5)).show()
define:string,l,"LScript"
(s+l).show()
```



## 等待用户输入

```python
#!/usr/bin/python
# -*- coding: UTF-8 -*-

raw_input("按下 enter 键退出，其他任意键显示...\n")
```

```c++
#scp
#scpeng
define:string,s
wait:userinput,s

```

## 数值

python支持四种不同数字类型

- int（有符号整型）
- long（长整型[也可以代表八进制和十六进制]）
- float（浮点型）
- complex（复数）

L脚本语言支持以下数字类型

​	int（有符号整型）

​	int64 （有符号64位整型）

​	double (双精度浮点型)

## 列表

python的列表 支持字符，数字，字符串，还可以包含列表（即嵌套）,python的列表支持切片

```python
#!/usr/bin/python
# -*- coding: UTF-8 -*-
 
list = [ 'runoob', 786 , 2.23, 'john', 70.2 ]
tinylist = [123, 'john']
 
print list               # 输出完整列表
print list[0]            # 输出列表的第一个元素
print list[1:3]          # 输出第二个至第三个元素 
print list[2:]           # 输出从第三个开始至列表末尾的所有元素
print tinylist * 2       # 输出列表两次
print list + tinylist    # 打印组合的列表
```

L脚本语言也支持list对象，list对象的内容可以是任意对象，当然也可以是list，L脚本语言中没有切片的概念

列表的成员需要动态添加，成员访问可以通过下标方式，也可以通过成员名方式

```c++
#scp
#scpeng
define:list,mylist
define:string,s,"hello"
define:int,i,1000
mylist.append(s)
mylist.append(i)

mylist.show()
mylist[1].show()
mylist[s].show()
```



## 元组

python中的元组可以认为是只读的列表



## 表

L脚本语言支持table类型，实际上table类型和list类型很接近,只不过list类型的内部存储是有序的，而table类型的内部存储是无序的 和list一样 table的成员需要动态添加，成员访问可以通过下标方式，也可以通过成员名方式

```c++
#scp
#scpeng
define:table,mytable
define:string,s,"hello"
define:int,i,1000
mytable.insert(s)
mytable.insert(i)

mytable.show()
mytable[1].show()
```

这个和python语言的字典类型很相似

## 运算符

运算符很接近



## 条件语句

```python
#!/usr/bin/python
# -*- coding: UTF-8 -*-
 
# 例1：if 基本用法
 
flag = False
name = 'luren'
if name == 'python':         # 判断变量是否为 python 
    flag = True              # 条件成立时设置标志为真
    print 'welcome boss'     # 并输出欢迎信息
else:
    print name               # 条件不成立时输出变量名称
```

```c++
#scp
#scpeng
define:int,flag,0
define:string,name,"lscript"
if (name == "lscript")        
    flag = 1             
    show:"welcome lscript"    
else:
    show:name 
end
```

L脚本语言中没有定义布尔类型，L脚本语言中认为整数1代表真值，整数0代表假

## 循环

语法上比较接近

只不过python强制使用tab制表符实现代码块

L脚本语言中代码块通过end 语句结束

```python
#!/usr/bin/python
 
count = 0
while (count < 9):
   print 'The count is:', count
   count = count + 1
 
print "Good bye!"
```

```c++
#scp
#scpeng
define:int,count,0
while(count<9)
	show:"The Count is",count
	count ++
end

show:"Good bye!"
```

python 支持for循环

L脚本语言不支持for循环

break 和 continue语句的含义相同

python的while for 语句还支持else



## 函数

python的函数体代码块必须通过tab制表符缩进来表示，这种强制性的语法，使得python的代码有比较清晰的结构

python的函数支持默认参数

L脚本语言的函数不支持默认参数

变量作用域的概念比较接近，

局部变量的名称可以和全局变量相同，但是在函数内部，局部变量访问优先

```python
#!/usr/bin/python
# -*- coding: UTF-8 -*-
 
# 定义函数
def printme( str ):
   "打印任何传入的字符串"
   print str
   return
 
# 调用函数
printme("我要调用用户自定义函数!")
printme("再次调用同一函数")
```

```c++
#scp
#scpeng
define:function,printme,str
    str.show()
end
    
printme("我要调用用户自定义函数!")
printme("再次调用同一函数")
```

## 模块

模块的概念仍然比较接近

python的模块就是一般的python脚本文件

L脚本语言的模块要求第一行注释必须是#scplib

## 文件

python 中通过open函数获得文件对象

L脚本语言中通过define语句定义文件对象，通过文件对象的成员函数实现对文件的操作

```python
#!/usr/bin/python
# -*- coding: UTF-8 -*-
 
# 打开一个文件
fo = open("foo.txt", "r+")
str = fo.read(10)
print "读取的字符串是 : ", str
# 关闭打开的文件
fo.close()
```

```c
#scp
#scpeng
define:file,fo
fo.open("E:\\tmp\\3.c")
define:string,str
fo.read(str)
str.show()
fo.close()
```



## 目录

python中没有目录对象，通过os模块中目录相关的函数实现对目录的操作

L脚本语言中通过define语句定义目录对象，通过目录对象的成员函数实现对目录的操作



## 正则表达式

```python
#!/usr/bin/python
# -*- coding: UTF-8 -*- 
 
import re
print(re.match('www', 'www.runoob.com').span())  # 在起始位置匹配
print(re.match('com', 'www.runoob.com'))         # 不在起始位置匹配
```

```c++
#scp
#scpeng
define:regexp,re,"www"
define:regexp,re1,"com"
(re.match("'www.runoob.com")).show()
(re1.match("'www.runoob.com")).show()

```

## Socket

socket编程也比较接近

```python
#!/usr/bin/python
# -*- coding: UTF-8 -*-
# 文件名：client.py
 
import socket               # 导入 socket 模块
 
s = socket.socket()         # 创建 socket 对象
host = socket.gethostname() # 获取本地主机名
port = 12345                # 设置端口号
 
s.connect((host, port))
print s.recv(1024)
s.close()
```

```c
#scp
#scpeng
load:extobj,socket
define:string,string1,"SOCK SOCK BALA BALA"
define:address,addr1,"192.168.0.102",27015

define:socket,sock1
#sock1.show()
sock1.create()
sock1.connect(addr1)
sock1.send(string1)
sock1.receive(string1)
string1.show()
sock1.close()

```

