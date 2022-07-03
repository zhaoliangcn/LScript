ScpObject.h

​	class ScpObject 是L语言的对象系统的基础，L语言中所有的对象皆继承于此类，通过实现ScpObject 所定义的纯虚函数接口实现对象的功能特性。

​	由于C++语言本身不支持反射，所以通过  ScpObject 中的 IsInnerFunction CallInnerFunction BindObjectInnerFuction GetInnerFunctionList 来实现"反射"。这些机制方便了解释引擎对用户自定义扩展对象进行语法解析。增强了语言的灵活性和扩展性。

​	

​	