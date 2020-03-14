# 与Java的对比

## HelloWorld

```c++
#scp
#scpeng

show:"Hello World!"
show("Hello World!")    
("Hello World!").show()
```

```java
public class HelloWorld {
    public static void main(String[] args) {
        System.out.println("Hello World");
    }
}
```

## 注释

Java支持C++风格的单行注释和多行注释

```java
public class HelloWorld {
   /* 这是第一个Java程序
    *它将打印Hello World
    * 这是一个多行注释的示例
    */
    public static void main(String []args){
       // 这是单行注释的示例
       /* 这个也是单行注释的示例 */
       System.out.println("Hello World"); 
    }
}
```

L脚本语言支持单行注释和C++风格的单行注释

```c++
#scp
#scpeng

show:"Hello World!" 
show("Hello World!")     
("Hello World!").show() //调用字符串对象的show()函数
```



## 类

L脚本语言的类、对象与Java的类、对象概念是相同的

**类**：类是一个模板，它描述一类对象的行为和状态。

**对象**：对象是类的一个实例，有状态和行为。

L脚本语言中没有 多态 重载的概念

Java语言中一个类可以包含 局部变量 成员变量 类变量

L脚本语言中没有类变量的概念

L脚本语言的类没有构造方法

比较特殊的是，L脚本语言的类自身也是对象

## 基本数据类型

Java有八种数据类型，包括，byte short int long float double boolean char 

通过这些基本数据类型声明的变量不是对象，所以从这个层面上来说Java不是完全面向对象的语言

L脚本语言 包含 int int64 double 三种数值类型的对象

由于不包括byte short char 这样的数据类型，L脚本语言缺少了直接操纵字节、双字节、单个字符 的能力

## 修饰符

Java中包含很多修饰符

主要分为访问修饰符和非访问修饰符

L脚本语言没有修饰符的概念

但L脚本语言中通过 public: 指令将后续类成员变量或类成员函数 切换为可以公开访问的状态 通过private:指令切换为不可公开访问的状态

## 运算符

### 算术运算符

包括 

```
+加法 

-减法

 *乘法

 /除法

 %取模

 ++自增

 --自减
```

其中Java的++ 自增运算符区分前置自增和后置自增 L脚本语言没有前置自增，只有后置自增

-- 自减 运算符也是一样，L脚本语言没有前置自减，只有后置自减

### 关系运算符

包括 

```
==等于
!=不等于 
>大于
<小于
>=大于等于
<=小于等于
```

### 位运算符

包括

```
&按位与
|按位或
^按位异或 
~按位取反
<<按位左移
>>按位右移
```

 Java还包括一个

```
>>>按位右移并补零
```



### 逻辑运算符

包括 

```
&&逻辑与
||逻辑或
！逻辑取反
```



### 赋值运算符

```
= 赋值
+= 加法并赋值
-= 减法并赋值
*= 乘法并赋值
/= 除法并赋值
%= 取模并赋值
<<= 按位左移并赋值
>>= 按位右移并赋值
&= 按位与并赋值
^= 按位异或并赋值
|= 按位或并赋值

```



### 条件运算符（?:）

Java 支持三元运算符，L脚本语言不支持

### instanceof 运算符

Java通过instanceof 运算符获得对象的类型，L脚本语言通过对象的gettype()函数获得对象类型的字符串说明

