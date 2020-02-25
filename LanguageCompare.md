# 与Ruby的对比

## Hello World

```c++
#scp
#scpeng

show:"Hello World!"
show("Hello World!")    
("Hello World!").show()
```



```ruby
#!/usr/bin/ruby
 
puts "Hello World!";
```



## 整数、浮点数

Ruby语言中，整数的定义有多种形式，浮点数也有多种定义形式，并且支持科学计数法

L脚本语言只有一种，这在需要进行金融计算的时候是个问题，不过大多数时候我们都是用最常用的一种整数表示方法



## 字符串

Ruby语言的字符串定义也比较灵活

```ruby
#!/usr/bin/ruby
name="Ruby" 
```

L脚本语言中定义字符串仅支持以双引号括起来的字符串，支持转义字符

```c++
#scp
#scpeng
define:string,name,"LLanguge"
```



## 数组

L脚本语言对数组类型有有限的支持

## 哈希类型

在L脚本语言中为Map类型

## 范围类型

L脚本语言不支持

## 类和对象

Ruby语言和L脚本语言的类类型很相像

```c++
#scp
#scpeng
define:class,Sample
public:
    define:function,hello
        ("Hello LScript!").show()
    end
end
define:Sample,object
object.hello()
```

```c++
#scp
#scpchs
定义:类,例子类
公开:
	定义:函数,你好
        ("你好 L脚本语言").显示()
    结束
结束
        
定义:例子类,对象实例
对象实例.你好()
    
```



```ruby
#!/usr/bin/ruby
 
class Sample
   def hello
      puts "Hello Ruby!"
   end
end
 
# 使用上面的类来创建对象
object = Sample. new
object.hello
```

Ruby语言新建对象通过new 关键字

L脚本语言新建对象仍然是define

从语法结构上来说，Ruby语言确实更加简洁，相比起来L脚本语言显得有点啰嗦，这也是一开始设计时的倾斜，这样写的代码是有点啰嗦，但是中文版本的代码阅读起来非常接近自然语言。这也是我一开始设计的目标之一，就是让代码的语法更接近我们平时说话的语言。





## 变量

Ruby语言有全局变量 实例变量 类变量的区分，且可以通过前缀的方式在任意地方定义全局变量

L脚本语言中只有在全局名字空间定义的变量才是全局变量，函数内部定义的变量仅在函数作用域中有效，类内部定义的变量都是实例变量，仅在类实例的作用域空间中有效



## 运算符

各种语言的运算符都比较接近



## 注释

Ruby语言支持单行注释和多行注释

```ruby
# 这是一个单行注释。

=begin
这是一个多行注释。
可扩展至任意数量的行。
但 =begin 和 =end 只能出现在第一行和最后一行。 
=end
```



```c++
# L脚本语言的单行注释
x = y +z // L脚本语言支持C++风格的单行注释
```





## 条件判断

Ruby语言中 有 if 语句还有 unless语句

```ruby
#!/usr/bin/ruby
# -*- coding: UTF-8 -*-
 
x=1
if x > 2
   puts "x 大于 2"
elsif x <= 2 and x!=0
   puts "x 是 1"
else
   puts "无法得知 x 的值"
end
```

L脚本语言中只有if语句

L脚本语言的语句没有elseif ，即不支持多重条件判断

```c++
#scp
#scpeng
define:int,x,1
if(x>2)
    show:"X大于2"
else
   	show:"X小于或等于2"
end
        
```

L脚本语言目前不支持Case语句





## 循环

Ruby语言支持 while until for    break next redo retry

L脚本语言支持while loop        continue break 

```ruby
#!/usr/bin/ruby
# -*- coding: UTF-8 -*-
 
$i = 0
$num = 5
 
while $i < $num  do
   puts("在循环语句中 i = #$i" )
   $i +=1
end
```



```c++
#scp
#scpeng
define:int,i,0
define:int,num,5
define:string,messages,"在循环中i等于"
while(i<num)
messages="在循环中i等于"
    messages+=i.transform(string)
    messages.show()
    i++
end
    
```



## 函数定义

```ruby
#!/usr/bin/ruby
# -*- coding: UTF-8 -*-
 
def test(a1="Ruby", a2="Perl")
   puts "编程语言为 #{a1}"
   puts "编程语言为 #{a2}"
end
test "C", "C++"
test
```



```c++
#scp
#scpeng
define:function,testfunc,a1,a2
    a1.show()
    a2.show()
end
testfunc("Ruby","LScript")
    
#这里注意一点早期L脚本语言的条件语句是使用test关键字，后来改为if，test仍然保留
#所以不能使用test作为函数名
```



L脚本语言的函数不支持默认参数

## 模块

Ruby语言通过module 来定义模块 通过 require 或 *include*  导入模块

L脚本语言中模块与普遍脚本相同，只不过第一行注释语句必须是#scplib

L脚本语言的模块也可以是压缩的zip文件

L脚本语言的模块没有自己的名字空间，通过import语句导入模块到脚本的全局空间

如果想要实现模块的名字空间隔离，可以把整个模块定义成一个类



## 时间日期



## 文件

Ruby通过File 类操作文件

例如

```ruby
File::exist?( path)
#如果 path 存在，则返回 true。
```

L脚本语言中文件是一种对象类型

```c++
#scp
#scpeng
define:file,fileobj,"C:\\temp\\1.txt"

if(fileobj.exist())
	("fileexist").show()
else
    ("file not exist").show()
end
```



## 目录

Ruby通过Dir 类实现目录的访问

例如

```ruby
Dir::delete( path)
#删除 path 指定的目录。目录必须是空的。
```

L脚本语言中 目录仍然是对象

```c++
#scp
#scpeng
define:directory,dir1,"C:\\temp\\testdir"
dir1.delete()
#目录不必为空，L脚本语言会递归删除整个目录
```



## 正则表达式

```ruby
#!/usr/bin/ruby
 
line1 = "Cats are smarter than dogs";
line2 = "Dogs also like meat";
 
if ( line1 =~ /Cats(.*)/ )
  puts "Line1 contains Cats"
end
if ( line2 =~ /Cats(.*)/ )
  puts "Line2 contains  Dogs"
end
```



```c++
#scp
#scpeng
define:regexp,re1,"Cats(.*)"
define:string,line1,"Cats are smarter than dogs"
define:string,line2,"Dogs also like meat"
if(re1.match(line1))
    show:"Line1 contains Cats"
end
if(re1.match(line2))
    show:"Line2 contains Cats"
end
```



## 网络编程



```ruby
require 'socket'      # Sockets 是标准库
 
hostname = 'localhost'
port = 2000
 
s = TCPSocket.open(hostname, port)
 
while line = s.gets   # 从 socket 中读取每行数据
  puts line.chop      # 打印到终端
end
s.close               # 关闭 socket
```



L脚本语言的socket模型比较接近C语言

```c++
#scp
#scpeng
define:string,string1,"SOCK SOCK BALA BALA"
define:address,addr1,"192.168.0.102",27015

define:socket,sock1
sock1.show()
sock1.create()
sock1.connect(addr1)
sock1.send(string1)
sock1.receive(string1)
string1.show()
sock1.close()
    
```





总体来说Ruby语言的类型定义比L脚本语言灵活简洁，但这也是以牺牲效率来实现的。











