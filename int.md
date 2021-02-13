## 整数对象类型

## object type: int 



### 对象声明

### object declarition

​	定义:整数,x[,对象初始值]

​	define:int,x[,initialvalue]

### 成员函数

### member function

显示()

show()

​	参数

​		无

​	功能

​		在控制台显示整数的值

​	返回值

​		整数对象自身

​	例程

​	

```c++
#scp
#scpeng
define:int,x,1024
x.show()
```



获取()

get()

​	参数

​		类型

​		type

​	功能

​		获得整数对象的类型名称

​	返回值

​		字符串临时对象，内容为整数对象的类型名称

​	例程

```c++
#scp
#scpeng
define:int,x,1024
x.get(type).show()
```



转换()

transform()

​	参数

​		字符串

​		string

​	功能

​		将整数对象的值转换为字符串

​	返回值

​		字符串临时对象，内容为整数对象的值的字符串表示

​	例程

```c++
#scp
#scpeng
define:int,x,1024
x.transform(string).show()
```



平方()

square()

​	参数

​		无

​	功能

​		计算整数的平方

​	返回值

​		整数临时对象，值为整数对象的平方

​	例程	

```c++
#scp
#scpeng
define:int,x,1024
x.square().show()
```



平方根()

sqrt()

​	参数

​		无

​	功能

​		计算整数的平方根

​	返回值

​		整数临时对象，值为整数对象的平方根

​	例程	

```c++
#scp
#scpeng
define:int,x,1024
x.sqrt().show()
```



立方()

cubic()

​	参数

​		无

​	功能

​		计算整数的立方

​	返回值

​		整数临时对象，值为整数对象的立方

​	例程

```c++
#scp
#scpeng
define:int,x,1024
x.cubic().show()
```



立方根()

cuberoot()

​	参数

​		无

​	功能

​		计算整数的立方根

​	返回值

​		整数临时对象，值为整数对象的立方根

​	例程

```c++
#scp
#scpeng
define:int,x,1024
x.cuberoot().show()
```



绝对值()

abs()

​	参数

​		无

​	功能

​		计算整数的绝对值

​	返回值

​		整数临时对象，值为整数对象的绝对值

​	例程	

```c++
#scp
#scpeng
define:int,x,-1024
x.abs().show()
```



反余弦()

acos()

​	参数

​		无

​	功能

​		计算整数的反余弦

​	返回值

​		浮点数临时对象，值为整数对象的反余弦

​	例程

```c++
#scp
#scpeng
define:int,x,1024
x.acos().show()
```



余弦()

cos()

​	参数

​		无

​	功能

​		计算整数的余弦

​	返回值

​		浮点数临时对象，值为整数对象的余弦

​	例程	

```c++
#scp
#scpeng
define:int,x,1024
x.cos().show()
```



反正弦()

asin()

​	参数

​		无

​	功能

​		计算整数的反正弦

​	返回值

​		浮点数临时对象，值为整数对象的反正弦

​	例程	

```c++
#scp
#scpeng
define:int,x,1024
x.asin().show()
```



正弦()

sin()

​	参数

​		无

​	功能

​		计算整数的正弦

​	返回值

​		浮点数临时对象，值为整数对象的正弦

​	例程	

```c++
#scp
#scpeng
define:int,x,1024
x.sin().show()
```



反正切()

atan()

​	参数

​		无

​	功能

​		计算整数的反正切

​	返回值

​		浮点数临时对象，值为整数对象的反正切

​	例程	

```
#scp
#scpeng
define:int,x,1024
x.atan().show()
```



正切()

tan()

​	参数

​		无

​	功能

​		计算整数的正切

​	返回值

​		浮点数临时对象，值为整数对象的正切

​	例程	

```c++
#scp
#scpeng
define:int,x,1024
x.tan().show()
```



次方()

pow()

​	参数y

​		整数对象或字符串格式的整数值

​	功能

​		计算整数的y次方

​	返回值

​		整数临时对象，值为整数对象的y次方

​	例程	

```
#scp
#scpeng
define:int,x,10
x.pow(3).show()
```

