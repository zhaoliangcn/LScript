字符串对象类型：

object type:string



对象声明

object declarition

​	定义:字符串,str[,对象初始值]

​	define:string,str[,initialvalue]

成员函数

member function

显示()

show()

​	参数

​		无

​	功能

​		在控制台显示字符串的内容

​	返回值

​		字符串对象自身

​	例程

​		

```c++
#scp
#scpeng
define:string,str,"hello L language"
str.show()
```



​	获取()

​	get()

​		参数

​			类型

​			type

​		功能

​			获得对象的类型名称

​		返回值

​			字符串临时对象，内容为字符串对象的类型名称

​		例程

​			

```c++
#scp
#scpeng
define:string,str,"abcdefg"
str.get(type).show()
```



​	转换()

​	transform()

​		参数

​			大写，小写，反转，十六进制，整数，浮点数

​		功能

​			按照参数要求转换为指定格式或对象

​		返回值	

​			转换后的对象

​		例程

```c++
#scp
#scpeng
define:string,str,"abcdefg"
str.transform(upper)
str.show()

str.transform(lower)
str.show()

str.transform(reverse)
str.show()

define:string,nstr,"1024"
define:int,x,0
x.show()
x = str.transform(int)
s.show()

define:string,dstr,"3.1415926"
define:double,y,0
y.show()
y = dstr.transform(double)
y.show()

```

​		

​	取大小()

​		getsize()

​			参数

​				无

​			功能

​				取得字符串的大小

​			返回值

​				整数临时对象，值为字符串对象的大小

​			例程

​				

```c++
#scp
#scpeng
define:string,s,"abcdefg"
s.getsize().show()
```

​		

​	长度()

​		length()

​			参数

​				无

​			功能

​				取得字符串的长度

​			返回值

​				整数临时对象，值为字符串对象的长度

​			例程

```c++
#scp
#scpeng
define:string,s,"abcdefg"
s.length().show()
```



​	清除()

​	clear()

​		参数()

​			无

​		功能

​			清空字符串的内容	

​		返回值

​			字符串对象自身

​		例程

​	

```c++
#scp
#scpeng
define:string,s,"abcdefg"
s.clear().show()
```



​	取子串()

​	getsubstring()

​		参数

​			起始位置

​			起始位置，截取长度

​		功能

​			截取字符串的子串

​		返回值

​			临时字符串对象，内容为截取后的子串

​		例程

​	

```c++
#scp
#scpeng
define:string,str,"helloworld"
define:string,sub1
define:string,sub2

sub1=str.getsubstring(5).show();
sub2=str.getsubstring(0,5).show();
```



​	格式化()

​	format()

​		参数

​			字符串模式，填充值列表

​				字符串模式中%s为占位符，可由填充值列表中的任意类型对象填充并替换

​		功能

​			对字符串进行格式化

​		返回值

​			临时字符串对象，内容为格式化后的字符串

​		例程

​		

```c++
#scp
#scpeng
define:string,s
s.format("year%smonth%sday%s",2021,2,13)
s.show()
```



​	替换()

​	replace()

​		参数

​			源子串，目标子串

​		功能

​			将字符串中源子串的内容替换为目标子串的内容

​		返回值

​			临时字符串对象，内容为替换操作后的字符串

​		例程

​			

```c++
#scp
#scpeng
define:string,s,"today is sunday"
s.show()
s.replace("sunday","monday")
s.show()

```



​	查找()

​	find()

​		参数

​			子串

​		功能

​			从字符串的左边开始查找子串，返回子串的位置

​		返回值

​			临时整数对象，内容字符串子串的索引

​		例程

​			

```c++
#scp
#scpeng
define:string,s,"helloworld"
s.find("world").show()
```



​	右查找()

​	rfind()

​		参数

​			子串

​		功能

​			从字符串的右边开始查找子串，返回子串的位置

​		返回值

​			临时整数对象，内容字符串子串的索引

​		例程

​			

```c++
#scp
#scpeng
define:string,s,"helloworld"
s.rfind("world").show()
```



​	包含()

​	contains()

​		参数

​			子串

​		功能

​			从字符串中查找子串，找到返回整数1，否则返回整数0

​		返回值

​			临时整数对象

​		例程

```c++
#scp
#scpeng
define:string,s,"helloworld"
s.contains("world").show()
```

​		

​	插入()

​	insert()

​		参数

​			子串插入位置			

​			子串内容

​		功能

​			将子串插入到字符串的指定位置

​		返回值

​			字符串对象自身

​		例程

​			

```c++
#scp
#scpeng
define:string,s,"hello L Language"
s.insert(5,"world")
s.show()
```



分割()

split()

​	参数

​			分割子串内容

​		功能

​			以子串作为分隔符将字符串分割为多个字符串，保存在表格对象中

​		返回值

​			表格临时对象

​		例程

```c++
#scp
#scpeng
define:string,s,"abcDefgDhigD"
define:table,t
t=s.split("D")
t.show()
```



比较()

compare()

​		参数

​			目标字符串

​		功能

​			比较两个字符串的内容，相等返回整数1,不等返回整数0

​		返回值

​			临时整数对象

​		例程

```c++
#scp
#scpeng
define:string,s1,"abcd"
define:string,s2,"ABCD"
s1.compare(s2).show()

```



连接()

connect()

​		参数

​			字符串

​		功能

​			连接两个字符串的内容

​		返回值

​			字符串对象自身

​		例程

```c++
#scp
#scpeng
define:string,s,"hello"
define:string,s2,"world"
s.connect(s2)
s.show()

```

