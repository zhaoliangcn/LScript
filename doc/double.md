## 浮点数对象类型

## object type: double



### 对象声明

### object declarition

​	定义:浮点数,x[,对象初始值]

​	define:double,x[,initialvalue]

### 成员函数

### member function

显示()

show()

​	参数

​		无

​	功能

​		在控制台显示浮点数的值

​	返回值

​		浮点数对象自身

​	例程

​	

```c++
#scp
#scpeng
define:double,x,3.1415926
x.show()
```



获取()

get()

​	参数

​		类型

​		type

​	功能

​		获得浮点数对象的类型名称

​	返回值

​		字符串临时对象，内容为浮点数对象的类型名称

​	例程

```c++
#scp
#scpeng
define:double,x,3.1415926
x.get(type).show()
```



转换()

transform()

​	参数

​		字符串

​		string

​	功能

​		将浮点数对象的值转换为字符串

​	返回值

​		字符串临时对象，内容为浮点数对象的值的字符串表示

​	例程

```c++
#scp
#scpeng
define:double,x,3.1415926
x.transform(string).show()
```



平方()

square()

​	参数

​		无

​	功能

​		计算浮点数的平方

​	返回值

​		浮点数临时对象，值为浮点数对象的平方

​	例程	

```c++
#scp
#scpeng
define:double,x,1024
x.square().show()
```



平方根()

sqrt()

​	参数

​		无

​	功能

​		计算浮点数的平方根

​	返回值

​		浮点数临时对象，值为浮点数对象的平方根

​	例程	

```c++
#scp
#scpeng
define:double,x,1024
x.sqrt().show()
```



立方()

cubic()

​	参数

​		无

​	功能

​		计算浮点数的立方

​	返回值

​		浮点数临时对象，值为浮点数对象的立方

​	例程

```c++
#scp
#scpeng
define:double,x,1024
x.cubic().show()
```



立方根()

cuberoot()

​	参数

​		无

​	功能

​		计算浮点数的立方根

​	返回值

​		浮点数临时对象，值为浮点数对象的立方根

​	例程

```c++
#scp
#scpeng
define:double,x,1024
x.cuberoot().show()
```



绝对值()

abs()

​	参数

​		无

​	功能

​		计算浮点数的绝对值

​	返回值

​		浮点数临时对象，值为浮点数对象的绝对值

​	例程	

```c++
#scp
#scpeng
define:double,x,-1024
x.abs().show()
```



反余弦()

acos()

​	参数

​		无

​	功能

​		计算浮点数的反余弦

​	返回值

​		浮点数临时对象，值为浮点数对象的反余弦

​	例程

```c++
#scp
#scpeng
define:double,x,1024
x.acos().show()
```



余弦()

cos()

​	参数

​		无

​	功能

​		计算浮点数的余弦

​	返回值

​		浮点数临时对象，值为浮点数对象的余弦

​	例程	

```c++
#scp
#scpeng
define:double,x,1024
x.cos().show()
```



反正弦()

asin()

​	参数

​		无

​	功能

​		计算浮点数的反正弦

​	返回值

​		浮点数临时对象，值为浮点数对象的反正弦

​	例程	

```c++
#scp
#scpeng
define:double,x,1024
x.asin().show()
```



正弦()

sin()

​	参数

​		无

​	功能

​		计算浮点数的正弦

​	返回值

​		浮点数临时对象，值为浮点数对象的正弦

​	例程	

```c++
#scp
#scpeng
define:double,x,1024
x.sin().show()
```



反正切()

atan()

​	参数

​		无

​	功能

​		计算浮点数的反正切

​	返回值

​		浮点数临时对象，值为浮点数对象的反正切

​	例程	

```c++
#scp
#scpeng
define:double,x,1024
x.atan().show()
```



正切()

tan()

​	参数

​		无

​	功能

​		计算浮点数的正切

​	返回值

​		浮点数临时对象，值为浮点数对象的正切

​	例程	

```c++
#scp
#scpeng
define:double,x,1024
x.tan().show()
```



次方()

pow()

​	参数y

​		整数对象或字符串格式的整数值

​	功能

​		计算浮点数的y次方

​	返回值

​		浮点数临时对象，值为浮点数对象的y次方

​	例程	

```c++
#scp
#scpeng
define:double,x,10
x.pow(3).show()
```



向上取整()

ceil()

​	参数

​		无

​	功能

​		返回大于或者等于浮点数对象的最小整数

​	返回值

​		浮点数临时对象，值为浮点数对象的向上取整

​	例程	

```c++
#scp
#scpeng
define:double,x,10.2
x.ceil(3).show()
```



向下取整()

floor()

​	参数

​		无

​	功能

​		返回小于或者等于浮点数对象的最大整数

​	返回值

​		浮点数临时对象，值为浮点数对象的向下取整

​	例程	

```c++
#scp
#scpeng
define:double,x,10.2
x.floor(3).show()
```



舍入()

round()

​	参数

​		无

​	功能

​		返回浮点数对象的四舍五入值

​	返回值

​		浮点数临时对象，值为浮点数对象的四舍五入值

​	例程	

```c++
#scp
#scpeng
define:double,x,10.2
x.round(3).show()
```

