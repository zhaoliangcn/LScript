## HelloWorld

```go
package main

import "fmt"

func main() {
    fmt.Println("Hello, World!")
}
```

```c++
#scp
#scpeng

show:"Hello World!"
show("Hello World!")    
("Hello World!").show()
```

## 注释

go语言支持单行注释和多行注释

```go
// 单行注释
/*
 Author by 菜鸟教程
 我是多行注释
 */
```

L脚本语言支持单行注释和C++风格的注释

```c++
# L脚本语言的单行注释
x = y +z // L脚本语言支持C++风格的单行注释
```

## 数据类型

## 布尔型

go支持布尔型 布尔型的值只可以是常量true 和false

L脚本语言没有布尔类型，L脚本语言中以整数值1表示真 以整数值0表示假

## 数字类型

go语言支持整数，浮点数，复数

L脚本语言支持整数(int) 大整数(int64) 浮点数(double) ，这些都是与CPU架构无关的

## 变量

go语言通过关键字var声明变量

```go
package main
import "fmt"
func main() {
    var a string = "Runoob"
    fmt.Println(a)

    var b, c int = 1, 2
    fmt.Println(b, c)
}
```

L脚本语言通过define语句声明对象

```c
#scp
#scpeng
define:int,x,100
define:string,s,"hello"
x.show()
s.show()
    
```

## 运算符

## 条件语句

## if语句

```c++
#scp
#scpeng
define:function,main
    define:int,a,10
    if(a<20)
        ("a小于20").show()
    end
end
```



```go
package main

import "fmt"

func main() {
   /* 定义局部变量 */
   var a int = 10
 
   /* 使用 if 语句判断布尔表达式 */
   if a < 20 {
       /* 如果条件为 true 则执行以下语句 */
       fmt.Printf("a 小于 20\n" )
   }
   fmt.Printf("a 的值为 : %d\n", a)
}
```

## switch语句

## select语句

## 循环

go支持for语句  循环语句中支持 continue break goto

L脚本语言支持while loop，while循环中支持 continue,break



```go
package main

import "fmt"

func main() {
   /* 定义局部变量 */
   var a int = 10

   /* for 循环 */
   for a < 20 {
      if a == 15 {
         /* 跳过此次循环 */
         a = a + 1;
         continue;
      }
      fmt.Printf("a 的值为 : %d\n", a);
      a++;    
   }  
}
```

```c++
#scp
#scpeng
define:function,main
    define:int,a,10
    while(a<20)
        if(a == 15)
            a++
         	continue
        end
        a.show()
        a++ 
    end
end
```

## 函数



```go
/* 函数返回两个数的最大值 */
func max(num1, num2 int) int {
   /* 声明局部变量 */
   var result int

   if (num1 > num2) {
      result = num1
   } else {
      result = num2
   }
   return result
}
```

L脚本语言的函数参数不需要指定参数类型，函数的参数可以是任意对象，使用时需要自己保证参数类型正确，函数的返回值可以是任意对象，因为参数是任意对象，而函数也是对象，所以L脚本语言的函数的参数也可以是函数

```c++
#scp
#scpeng
define:function,max,num1,num2
    if(num1>num2)
        return(num1)
    else
        return(num2)
	end
end
```

## 指针

go语言支持指针

L脚本语言中没有指针的概念

## 结构体



## 递归函数

阶乘

```go
package main

import "fmt"

func Factorial(n uint64)(result uint64) {
    if (n > 0) {
        result = n * Factorial(n-1)
        return result
    }
    return 1
}

func main() {  
    var i int = 15
    fmt.Printf("%d 的阶乘是 %d\n", i, Factorial(uint64(i)))
}
```

```c++
#scp
#scpeng
define:function,Factorial,n
    define:int64,result
    if(n>0)
        result=n*Factorial(n-1)
        return(result)
    end
    return(1)
end
define:function,main
    define:int64,i,15
    (Factorial(i)).show()
end
        
```

需要注意一点,L脚本语言的return 语句必须用括号把返回值括起来