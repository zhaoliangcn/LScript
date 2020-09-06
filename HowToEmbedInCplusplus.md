# 如何在C或C++程序中集成L脚本语言



很多时候我们需要多种编程语言配合使用，比如我们正在开发的用C++语言编写的项目，其中用到的某个库是C++语言没有实现的，或者是实现起来比较困难的，而python实现了这个库，那我们可能会选择用我们的程序调用python库来实现这个功能，而不是花费更多时间重新实现。或者相反的当我们用python Java开发的项目，其中某个比较底层的功能语言无法实现、或是某个功能要求高性能并且减少内存使用，这个时候我们可以选择用在Java程序中调用JNI，在python中调用C/C++的动态库。

L脚本语言的解释引擎本身是使用C++语言开发的，并且已经封装为动态库导出了所有C语言接口的函数，所以在C/C++程序中调用L脚本语言不是什么难事。

所有导出函数可以参考 ScriptEngineDll.h 文件

这里我们对导出函数逐一进行说明

```cpp

/*
这个函数会内部创建一个L脚本语言解释引擎的实例，并将传入的字符串当做一行脚本执行，
执行结束后内部销毁解释引擎的实例

例如：
ScriptEngineDoString(L"(helloworld).show()");
*/

int 	ScriptEngineDoString(wchar_t * ScriptString);

```

```cpp

/*
这个函数会内部创建一个L脚本语言解释引擎的实例，并将传入的文件读入内存，逐行解释执行
执行结束后内部销毁解释引擎的实例

例如：
ScriptEngineDoScriptFile(L"C:\\script\\test.scp");

ScriptEngineDebugScriptFile(L"C:\\script\\test.scp");
*/

int 	ScriptEngineDoScriptFile(wchar_t * ScriptFileName);

int 	ScriptEngineDebugScriptFile(wchar_t * ScriptFileName);

```

```cpp

int 	ScriptEngineDebugMemoryScript(wchar_t * ScriptFileName);

/*
这个函数会内部创建一个L脚本语言解释引擎的实例，
并将传入的内存字符串当做一个完整的脚本文件逐行解释执行
执行结束后内部销毁解释引擎的实例

例如：
ScriptEngineDebugMemoryScript(L"");

*/


```

以上函数适用于简单的一次执行某一行脚本或某个脚本文件的情况。



下面的函数通过创建L脚本语言解释引擎的实例，并返回实例的句柄，通过实例句柄控制

其执行逻辑。

```cpp
/*
这个函数用于创建一个L脚本语言解释引擎的实例，并返回一个实例句柄
*/
HANDLE  CreateScriptEngine();
```





```cpp

/*
这个函数用于加载脚本源代码
*/

BOOL     LoadScript(HANDLE hScript, const wchar_t * ScriptFilePathName);
```





```cpp
/*
这个函数在脚本引擎的全局名字空间中查找名字为ObjectName的对象，并将其转换为字符串
保存在缓冲区ObjectBuffer中，调用者需要为ObjectBuffer分配足够的空间
*/
BOOL     ScriptObjectToWString(HANDLE hScript, wchar_t * ObjectName, wchar_t *ObjectBuffer, size_t BufferSize);
```





```cpp
/*
这个函数在脚本引擎的全局名字空间中查找名字为ObjectName的对象，并将其整数值保存在
Value指向的地址空间中
*/
BOOL     ScriptObjectToInt(HANDLE hScript, wchar_t * ObjectName, int * Value);
```





```cpp
/*
这个函数在脚本引擎的全局名字空间中查找名字为ObjectName的对象，并将其浮点数值保存在
Value指向的地址空间中
*/
BOOL     ScriptObjectToDouble(HANDLE hScript, wchar_t * ObjectName, double * Value);
```





```cpp
/*
这个函数在脚本引擎的全局名字空间中查找名字为ObjectName的对象，并将其__int64 整数数值保存在
Value指向的地址空间中
*/
BOOL     ScriptObjectToInt64(HANDLE hScript, wchar_t * ObjectName, __int64 * Value);
```





```cpp
/*
这个函数执行一次函数调用
*/
BOOL     ScriptCallFunction(HANDLE hScript, wchar_t * FunctionAndParameter);
```





```cpp
/*
这个函数关闭并销毁解释引擎的实例
*/
void     CloseScriptEngine(HANDLE &hScript);
```





```cpp
/*
这个函数主要用于调试器或者脚本编辑器中，通过注册界面回调
将脚本引擎的输出重定向到自己的界面程序中
*/
BOOL     ScriptRegisterUICallBack(HANDLE hScript, void * uiclass, UICallBack callback);
```





```cpp
/*
这个函数主要用于调试器或者脚本编辑器中，通过脚本单步执行时的界面回调
将脚本引擎的输出重定向到自己的界面程序中
*/
BOOL     ScriptRegisterUIStepCallBack(HANDLE hScript, void * uiclass, UICallBack callback);
```





```cpp
/*
这个函数主要用于调试器或者脚本编辑器中，获取当前脚本执行到哪一行
*/
int     ScriptGetCurrentCommandLine(HANDLE hScript);
```





```cpp
/*
这个函数用于枚举解释引擎中当前名字空间中的所有对象名称
*/
void     ScriptEnumObjects(HANDLE hScript, VTSTRINGS **objects);
```





```cpp

/*
这个函数释放ScriptEnumObjects函数中分配的对象名所占用的内存空间
*/
void     ScriptReleaseObjects(VTSTRINGS**objects);
```





```cpp
/*
这个函数加载指定的脚本文件，并逐行解释执行
*/
int     ScriptDoScript(HANDLE hScript, const wchar_t * scriptfilename, SCRIPTRUNTYPE mode = RUN_NORMAL);
```





```cpp
/*
这个函数主要用于调试器或者脚本编辑器中，将一块内存中的文本当做一个完整的脚本文件逐行解释执行
*/
int     ScriptDebugMemoryScript(HANDLE hScript, wchar_t * MemoryScript);
```





```cpp
int     ScriptAddBreakPoints(HANDLE hScript, int line); //已废弃
int     ScriptEraseBreakPoint(HANDLE hScript, int line);//已废弃
```





```cpp

/*
这个函数打印输出指定对象的值
*/

void     ScriptDumpObject(HANDLE hScript, const wchar_t *  objectname);
```





```cpp

/*
这个函数将解释引擎加载到内存中的脚本另存为文件
*/
int     ScriptDumpScript(HANDLE hScript, const wchar_t *  newscriptfilename);
```





```cpp
void     ScriptSetDebugEvent(HANDLE hScript);//已废弃
```





```cpp
/*
这个函数将脚本文件读入内存并将每一行作为std::wstring存入std::vector中
*/
bool     ScriptReadScript(const wchar_t *  scriptfilename, VTSTRINGS** body);
```





```cpp
/*
这个函数释放ScriptReadScript中分配内存
*/
void     ScriptReleaseScript(VTSTRINGS** body);
```





```cpp
/*
这个函数用于动态注册一个全局函数 注册后的函数可以直接以 函数名(参数列表) 的方式调用 
可以实现动态增加语言的功能特性

chscommandstring 是全局函数的中文名
engcommandstring 是全局函数的英文名
commandid 是全局函数的唯一标识
GlobalCommandFunctionPtr 是指向全局函数的指针
*/
BOOL     ScriptRegisterGlobalCommand(HANDLE hScript, const wchar_t * chscommandstring, const wchar_t * engcommandstring, DWORD commandid, GlobalCommandFunctionPtr);
```





```cpp
/*
这个函数将执行的字节码文件读取到内存并执行
*/
int     ScriptDoByteCode(HANDLE hScript, const wchar_t * bytecodefilename, SCRIPTRUNTYPE mode = RUN_NORMAL);
```





```cpp
/*
这个函数将一块内存当做字节码文件读取并顺序执行
*/
int     ScriptDoMemByteCode(HANDLE hScript, const unsigned char  * membytecode, int length, SCRIPTRUNTYPE mode = RUN_NORMAL);
```





```cpp
/*
这个函数设置脚本引擎是否在解释执行脚本的同时生成字节码文件 Jit=1 表示生成字节码
*/
int     ScriptSetJit(HANDLE hScript, int Jit);   
```



```cpp
/*
这个函数将一行字符串当做一行脚本执行
*/
int     ScriptDoString(HANDLE hScript, const wchar_t * ScriptString);
```



```cpp
/*
这个函数用于绑定调试器的实例
*/
int     ScriptSetDebugger(HANDLE hScript, void * debugger);
```



```cpp
/*
这个函数用于在执行内存中的脚本时为脚本指定一个文件名
*/
int     ScriptSetScriptFileName(HANDLE hScript, const wchar_t * ScriptFileName);
```



```cpp
/*
这个函数用于获取某个对象的对象类型
*/
int     ScriptGetObjectType(HANDLE hScript, const wchar_t * ObjectName, wchar_t *ObjectTypeBuffer, int BufferLength);
```



```cpp
/*
这个函数用于获取某个对象的成员函数列表
*/
int     ScriptGetObjectFuncList(HANDLE hScript, const wchar_t * ObjectName, wchar_t *ObjectFuncBuffer, int BufferLength);
```



通过这些导出函数，我们可以实现在C /C++程序中集成L脚本语言，或者实现自己的编辑器、调试器，或者将某个需要经常修改的业务功能编写为L脚本语言的脚本，在C/C++程序中动态调用

具体的可以参考 embedtest  QScriptEditor  ScriptIDE 源码中相关的实现
