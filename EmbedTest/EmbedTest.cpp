// EmbedTest.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "../include/ScriptEngineDll.h"
int BasicFileTest(HMODULE hDLL, std::wstring wsScriptFile)
{
	int ret = -1;
	if (hDLL)
	{

		FUNC_ScriptEngineDoScriptFile ScriptEngineDoScriptFile = (FUNC_ScriptEngineDoScriptFile)GetProcAddress(hDLL, "ScriptEngineDoScriptFile");
		if (ScriptEngineDoScriptFile)
		{
			ret = ScriptEngineDoScriptFile((wchar_t *)wsScriptFile.c_str());
		}
	}
	return ret;
}
int BasicStringTest(HMODULE hDLL, std::wstring wsScriptString)
{
	int ret = -1;
	if (hDLL)
	{
		FUNC_ScriptEngineDoString ScriptEngineDoString =(FUNC_ScriptEngineDoString)GetProcAddress(hDLL,"ScriptEngineDoString");
		if(ScriptEngineDoString)
		{
			ret = ScriptEngineDoString((wchar_t *)wsScriptString.c_str());
		}
	}
	return ret;
}
int ConfigFileTest(HMODULE hDLL, std::wstring wsScriptFile)
{
	int ret = -1;
	FUNC_CreateScriptEngine  CreateScriptEngine=(FUNC_CreateScriptEngine)GetProcAddress(hDLL,"CreateScriptEngine");
	FUNC_LoadScript LoadScript =(FUNC_LoadScript)GetProcAddress(hDLL,"LoadScript");
	FUNC_ScriptObjectToWString ScriptObjectToWString = (FUNC_ScriptObjectToWString)GetProcAddress(hDLL,"ScriptObjectToWString");
	FUNC_ScriptCallFunction ScriptCallFunction =(FUNC_ScriptCallFunction)GetProcAddress(hDLL,"ScriptCallFunction");
	FUNC_CloseScriptEngine CloseScriptEngine = (FUNC_CloseScriptEngine)GetProcAddress(hDLL,"CloseScriptEngine");
	HANDLE hscript = CreateScriptEngine();
	if(hscript)
	{
		if(LoadScript(hscript, wsScriptFile.c_str()))
		{		
			ret = ScriptCallFunction(hscript,L"初始化");
			wchar_t objectbuffer1[1024]={0};
			wchar_t objectbuffer2[1024]={0};
			wchar_t objectbuffer3[1024]={0};
			ScriptObjectToWString(hscript,L"根节点[子节点[属性1]]",objectbuffer1,1024);
			ScriptObjectToWString(hscript,L"根节点[子节点[属性2]]",objectbuffer2,1024);
			ScriptObjectToWString(hscript,L"根节点[长度]",objectbuffer3,1024);
			printf("根节点[子节点[属性1]]=%S\n",objectbuffer1);
			printf("根节点[子节点[属性2]]=%S\n",objectbuffer2);
			printf("根节点[长度]=%S\n",objectbuffer3);


			ScriptObjectToWString(hscript,L"根节点[1]",objectbuffer3,1024);
			printf("根节点[1]=%S\n",objectbuffer3);
		}
		CloseScriptEngine(hscript);

	}
	return ret;
}
int ObjectInitFileTest(HMODULE hDLL, std::wstring wsScriptFile)
{
	int ret = -1;
	FUNC_CreateScriptEngine  CreateScriptEngine = (FUNC_CreateScriptEngine)GetProcAddress(hDLL, "CreateScriptEngine");
	FUNC_LoadScript LoadScript = (FUNC_LoadScript)GetProcAddress(hDLL, "LoadScript");
	FUNC_ScriptObjectToWString ScriptObjectToWString = (FUNC_ScriptObjectToWString)GetProcAddress(hDLL, "ScriptObjectToWString");
	FUNC_ScriptObjectToInt ScriptObjectToInt=(FUNC_ScriptObjectToInt)GetProcAddress(hDLL, "ScriptObjectToInt");
	FUNC_ScriptObjectToDouble ScriptObjectToDouble = (FUNC_ScriptObjectToDouble)GetProcAddress(hDLL, "ScriptObjectToDouble");
	FUNC_ScriptObjectToInt64 ScriptObjectToInt64 = (FUNC_ScriptObjectToInt64)GetProcAddress(hDLL, "ScriptObjectToInt64");
	FUNC_ScriptCallFunction ScriptCallFunction = (FUNC_ScriptCallFunction)GetProcAddress(hDLL, "ScriptCallFunction");
	FUNC_CloseScriptEngine CloseScriptEngine = (FUNC_CloseScriptEngine)GetProcAddress(hDLL, "CloseScriptEngine");
	HANDLE hscript = CreateScriptEngine();
	if (hscript)
	{
		if (LoadScript(hscript, wsScriptFile.c_str()))
		{
			//ret = ScriptCallFunction(hscript, L"init");
			int value = 0;
			ScriptObjectToInt(hscript, L"test1", &value);
			printf("test1=%d\n", value);

			double value2 = 0;
			ScriptObjectToDouble(hscript, L"test2", &value2);
			printf("test2=%.10lf\n", value2);

			__int64 value3 = 0;
			ScriptObjectToInt64(hscript, L"test3", &value3);
			printf("test3=%I64d\n", value3);
			
		}
		CloseScriptEngine(hscript);

	}
	return ret;
}
int _tmain(int argc, _TCHAR* argv[])
{
	std::wstring wsDllFile =  L"ScriptEngineDll.dll";
	HMODULE hDLL = LoadLibraryW(wsDllFile.c_str());
	if (hDLL)
	{
		ObjectInitFileTest(hDLL, L"init.scp");
	}	
	return 0;
}

