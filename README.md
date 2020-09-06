# LScript
LScript Language

LScript  is a simple object oriented language.

This repository contains LScript IDE' source code and sample script .

```c++
#scp
#scpeng
("helloworld").show()
```

L脚本语言解释引擎
Window安装包和例子脚本文件
L脚本语言的开发目标是完全面向对象、支持中英文、跨平台、可扩展，语法简单易学

![helloworld](https://github.com/zhaoliangcn/LScript/blob/master/helloworld.PNG)

请将脚本文件保存为utf-8编码格式

从0.20版本开始，L脚本语言解释引擎增加了字节码动态生成的功能
通过传递命令行参数 /g 可以通知解释引擎生成.scpb字节码文件
例如 ScriptEngine.exe add.scp /g
会在add.scp同目录下生成add.scp.scpb文件
成功生成的字节码文件可以替代源码文件，通过解释器引擎加载执行
如 ScriptEngine.exe add.scp.scpb

与Ruby语言的对比https://github.com/zhaoliangcn/LScript/blob/master/LanguageCompare.md

与Python语言的对比https://github.com/zhaoliangcn/LScript/blob/master/LanguageCompareWithPython.md

与go语言的对比https://github.com/zhaoliangcn/LScript/blob/master/LanguageCompareWithGo.md

与C语言的对比https://github.com/zhaoliangcn/LScript/blob/master/LanguageCompareWithC.md

与Java语言的对比https://github.com/zhaoliangcn/LScript/blob/master/LanguageCompareWithJava.md

如何在C或C++程序中集成L脚本语言https://github.com/zhaoliangcn/LScript/blob/master/HowToEmbedInCplusplus.md

L脚本语言和编译器开发QQ群: 192019254

本仓库仅包含LScriptIDE的源码，暂未开放解释引擎，最新安装包请通过网盘下载

安装包百度网盘链接: https://pan.baidu.com/s/1mrKbwNs3lKQSa3f9ynYreQ 提取码: jfff

