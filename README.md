# LScript
LScriptLanguage
L脚本语言解释引擎
Window安装包和例子脚本文件
L脚本语言的开发目标是完全面向对象、支持中英文、跨平台、可扩展，语法简单易学

说明:中文脚本文件的字符编码为GB2312格式、英文脚本文件的字符编码可以为ansi或utf-8格式

从0.20版本开始，L脚本语言解释引擎增加了字节码动态生成的功能
通过传递命令行参数 /g 可以通知解释引擎生成.scpb字节码文件
例如 ScriptEngine.exe add.scp /g
会在add.scp同目录下生成add.scp.scpb文件
成功生成的字节码文件可以替代源码文件，通过解释器引擎加载执行
如 ScriptEngine.exe add.scp.scpb

与Ruby语言的对比https://github.com/zhaoliangcn/LScript/blob/master/LanguageCompare.md

与Python语言的对比https://github.com/zhaoliangcn/LScript/blob/master/LanguageCompareWithPython.md


L脚本语言和编译器开发QQ群: 192019254

安装包百度网盘链接: https://pan.baidu.com/s/1mrKbwNs3lKQSa3f9ynYreQ 提取码: jfff

