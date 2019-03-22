#include <WinSock2.h>
#include <Windows.h>
#include <string>
#include <vector>
typedef std::vector<std::wstring> VTSTRINGS;
typedef std::vector<std::wstring>::iterator  ITSTRINGS;
typedef void(__stdcall *UICallBack)(void * UIClass, const wchar_t * Message);
typedef BOOL(__stdcall *GlobalCommandFunctionPtr)(VTSTRINGS * vtparameters, void * engine);
#ifndef _EM_SCRIPTRUNTYPE
#define _EM_SCRIPTRUNTYPE
typedef enum _tag_SCRIPTRUNTYPE
{
	RUN_NORMAL,
	RUN_DEBUG,
	RUN_SINGLESTEP,
}SCRIPTRUNTYPE;

#endif //_EM_SCRIPTRUNTYPE

// __declspec(dllexport)
extern "C" int __stdcall	ScriptEngineDoString(wchar_t * ScriptString);
extern "C" int __stdcall	ScriptEngineDoScriptFile(wchar_t * ScriptFileName);
extern "C" int __stdcall	ScriptEngineDebugScriptFile(wchar_t * ScriptFileName);
extern "C" int __stdcall	ScriptEngineDebugMemoryScript(wchar_t * ScriptFileName);

extern "C" HANDLE __stdcall CreateScriptEngine();
extern "C" BOOL __stdcall	LoadScript(HANDLE hScript,const wchar_t * ScriptFilePathName);
extern "C" BOOL __stdcall	ScriptObjectToWString(HANDLE hScript,wchar_t * ObjectName,wchar_t *ObjectBuffer,size_t BufferSize);
extern "C" BOOL __stdcall	ScriptObjectToInt(HANDLE hScript, wchar_t * ObjectName, int * Value);
extern "C" BOOL __stdcall	ScriptObjectToDouble(HANDLE hScript, wchar_t * ObjectName, double * Value);
extern "C" BOOL __stdcall	ScriptObjectToInt64(HANDLE hScript, wchar_t * ObjectName, __int64 * Value);
extern "C" BOOL __stdcall	ScriptCallFunction(HANDLE hScript,wchar_t * FunctionAndParameter);
extern "C" void __stdcall	CloseScriptEngine(HANDLE &hScript);
extern "C" BOOL __stdcall	ScriptRegisterUICallBack(HANDLE hScript,void * uiclass,UICallBack callback);
extern "C" BOOL __stdcall	ScriptRegisterUIStepCallBack(HANDLE hScript,void * uiclass,UICallBack callback);
extern "C" int __stdcall	ScriptGetCurrentCommandLine(HANDLE hScript);
extern "C" void __stdcall	ScriptEnumObjects(HANDLE hScript,VTSTRINGS **objects);
extern "C" void __stdcall	ScriptReleaseObjects(VTSTRINGS**objects);
extern "C" int __stdcall	ScriptDoScript(HANDLE hScript,const wchar_t * scriptfilename,SCRIPTRUNTYPE mode=RUN_NORMAL);
extern "C" int __stdcall	ScriptDebugMemoryScript(HANDLE hScript,wchar_t * MemoryScript);
extern "C" int __stdcall	ScriptAddBreakPoints(HANDLE hScript,int line);
extern "C" int __stdcall	ScriptEraseBreakPoint(HANDLE hScript,int line);
extern "C" void __stdcall	ScriptDumpObject(HANDLE hScript,const wchar_t *  objectname);
extern "C" int __stdcall	ScriptDumpScript(HANDLE hScript,const wchar_t *  newscriptfilename);
extern "C" void __stdcall	ScriptSetDebugEvent(HANDLE hScript);
extern "C" bool __stdcall	ScriptReadScript(const wchar_t *  scriptfilename,VTSTRINGS** body);
extern "C" void __stdcall	ScriptReleaseScript(VTSTRINGS** body);
extern "C" BOOL __stdcall	ScriptRegisterGlobalCommand(HANDLE hScript,const wchar_t * chscommandstring, const wchar_t * engcommandstring, DWORD commandid, GlobalCommandFunctionPtr);


typedef int (__stdcall		*FUNC_ScriptEngineDoString)(wchar_t * ScriptString);
typedef int (__stdcall		*FUNC_ScriptEngineDoScriptFile)(wchar_t * ScriptFileName);
typedef int (__stdcall		*FUNC_ScriptEngineDebugScriptFile)(wchar_t * ScriptFileName);
typedef int (__stdcall		*FUNC_ScriptEngineDebugMemoryScript)(wchar_t * ScriptFileName);

typedef HANDLE (__stdcall	*FUNC_CreateScriptEngine)();
typedef BOOL (__stdcall		*FUNC_LoadScript)(HANDLE hScript,const wchar_t * ScriptFilePathName);
typedef BOOL (__stdcall		*FUNC_ScriptObjectToWString)(HANDLE hScript,wchar_t * ObjectName,wchar_t *ObjectBuffer,size_t BufferSize);
typedef BOOL (__stdcall		*FUNC_ScriptObjectToInt)(HANDLE hScript, wchar_t * ObjectName, int * Value);
typedef BOOL (__stdcall		*FUNC_ScriptObjectToDouble)(HANDLE hScript, wchar_t * ObjectName, double * Value);
typedef BOOL(__stdcall		*FUNC_ScriptObjectToInt64)(HANDLE hScript, wchar_t * ObjectName, __int64 * Value);
typedef BOOL (__stdcall		*FUNC_ScriptCallFunction)(HANDLE hScript,wchar_t * FunctionAndParameter);
typedef void (__stdcall		*FUNC_CloseScriptEngine)(HANDLE &hScript);
typedef BOOL (__stdcall		*FUNC_ScriptRegisterUICallBack)(HANDLE hScript,void * uiclass,UICallBack callback);
typedef BOOL (__stdcall		*FUNC_ScriptRegisterUIStepCallBack)(HANDLE hScript,void * uiclass,UICallBack callback);
typedef int (__stdcall		*FUNC_ScriptGetCurrentCommandLine)(HANDLE hScript);
typedef void (__stdcall		*FUNC_ScriptEnumObjects)(HANDLE hScript,VTSTRINGS **objects);
typedef void (__stdcall		*FUNC_ScriptReleaseObjects)(VTSTRINGS**objects);
typedef int (__stdcall		*FUNC_ScriptDoScript)(HANDLE hScript,const wchar_t * scriptfilename,SCRIPTRUNTYPE mode);
typedef int (__stdcall		*FUNC_ScriptDebugMemoryScript)(HANDLE hScript,wchar_t * MemoryScript);

typedef int (__stdcall		*FUNC_ScriptAddBreakPoints)(HANDLE hScript,int line);
typedef int (__stdcall		*FUNC_ScriptEraseBreakPoint)(HANDLE hScript,int line);
typedef void (__stdcall		*FUNC_ScriptDumpObject)(HANDLE hScript,const wchar_t *  objectname);
typedef int (__stdcall		*FUNC_ScriptDumpScript)(HANDLE hScript,const wchar_t *  newscriptfilename);
typedef void (__stdcall		*FUNC_ScriptSetDebugEvent)(HANDLE hScript);
typedef bool (__stdcall		*FUNC_ScriptReadScript)(const wchar_t *  scriptfilename,VTSTRINGS** body);
typedef void (__stdcall		*FUNC_ScriptReleaseScript)(VTSTRINGS** body);
typedef BOOL (__stdcall		*FUNC_ScriptRegisterGlobalCommand)(HANDLE hScript, const wchar_t * chscommandstring, const wchar_t * engcommandstring, DWORD commandid, GlobalCommandFunctionPtr);