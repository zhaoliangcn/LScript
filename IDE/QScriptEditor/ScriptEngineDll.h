#ifdef _WIN32
#include <WinSock2.h>
#include <Windows.h>
#else
#include <stdint.h>
typedef void *HANDLE;
typedef int BOOL;
typedef __int64_t __int64;
typedef unsigned int DWORD;
#endif
#include <string>
#include <vector>
using namespace std;
typedef std::vector<std::wstring> VTSTRINGS;
typedef std::vector<std::wstring>::iterator  ITSTRINGS;
typedef void(*UICallBack)(void * UIClass, const wchar_t * Message);
typedef BOOL(*GlobalCommandFunctionPtr)(VTSTRINGS * vtparameters, void * engine);
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
extern "C" int 	ScriptEngineDoString(wchar_t * ScriptString);
extern "C" int 	ScriptEngineDoScriptFile(wchar_t * ScriptFileName);
extern "C" int 	ScriptEngineDebugScriptFile(wchar_t * ScriptFileName);
extern "C" int 	ScriptEngineDebugMemoryScript(wchar_t * ScriptFileName);

extern "C" HANDLE  CreateScriptEngine();
extern "C" BOOL 	LoadScript(HANDLE hScript,const wchar_t * ScriptFilePathName);
extern "C" BOOL 	ScriptObjectToWString(HANDLE hScript,wchar_t * ObjectName,wchar_t *ObjectBuffer,size_t BufferSize);
extern "C" BOOL 	ScriptObjectToInt(HANDLE hScript, wchar_t * ObjectName, int * Value);
extern "C" BOOL 	ScriptObjectToDouble(HANDLE hScript, wchar_t * ObjectName, double * Value);
extern "C" BOOL 	ScriptObjectToInt64(HANDLE hScript, wchar_t * ObjectName, __int64 * Value);
extern "C" BOOL 	ScriptCallFunction(HANDLE hScript,wchar_t * FunctionAndParameter);
extern "C" void 	CloseScriptEngine(HANDLE &hScript);
extern "C" BOOL 	ScriptRegisterUICallBack(HANDLE hScript,void * uiclass,UICallBack callback);
extern "C" BOOL 	ScriptRegisterUIStepCallBack(HANDLE hScript,void * uiclass,UICallBack callback);
extern "C" int 	ScriptGetCurrentCommandLine(HANDLE hScript);
extern "C" void 	ScriptEnumObjects(HANDLE hScript,VTSTRINGS **objects);
extern "C" void 	ScriptReleaseObjects(VTSTRINGS**objects);
extern "C" int 	ScriptDoScript(HANDLE hScript,const wchar_t * scriptfilename,SCRIPTRUNTYPE mode=RUN_NORMAL);
extern "C" int 	ScriptDebugMemoryScript(HANDLE hScript,wchar_t * MemoryScript);
extern "C" int 	ScriptAddBreakPoints(HANDLE hScript,int line); //ÒÑ·ÏÆú
extern "C" int 	ScriptEraseBreakPoint(HANDLE hScript,int line);//ÒÑ·ÏÆú
extern "C" void 	ScriptDumpObject(HANDLE hScript,const wchar_t *  objectname);
extern "C" int 	ScriptDumpScript(HANDLE hScript,const wchar_t *  newscriptfilename);
extern "C" void 	ScriptSetDebugEvent(HANDLE hScript);//ÒÑ·ÏÆú
extern "C" bool 	ScriptReadScript(const wchar_t *  scriptfilename,VTSTRINGS** body);
extern "C" void 	ScriptReleaseScript(VTSTRINGS** body);
extern "C" BOOL 	ScriptRegisterGlobalCommand(HANDLE hScript,const wchar_t * chscommandstring, const wchar_t * engcommandstring, DWORD commandid, GlobalCommandFunctionPtr);
extern "C" int 	ScriptDoByteCode(HANDLE hScript, const wchar_t * bytecodefilename, SCRIPTRUNTYPE mode = RUN_NORMAL);
extern "C" int 	ScriptDoMemByteCode(HANDLE hScript, const unsigned char  * membytecode, int length,SCRIPTRUNTYPE mode = RUN_NORMAL);
extern "C" int 	ScriptSetJit(HANDLE hScript, int Jit);
extern "C" int 	ScriptDumpByteCode(HANDLE hScript, const wchar_t * ByteCodeFile);
extern "C" int 	ScriptDoString(HANDLE hScript, const wchar_t * ScriptString);
extern "C" int 	ScriptSetDebugger(HANDLE hScript, void * debugger);
extern "C" int 	ScriptSetScriptFileName(HANDLE hScript, const wchar_t * ScriptFileName);
extern "C" int 	ScriptGetObjectType(HANDLE hScript, const wchar_t * ObjectName,wchar_t *ObjectTypeBuffer,int BufferLength);
extern "C" int 	ScriptGetObjectFuncList(HANDLE hScript, const wchar_t * ObjectName, wchar_t *ObjectFuncBuffer, int BufferLength);

typedef int (		*FUNC_ScriptEngineDoString)(wchar_t * ScriptString);
typedef int (		*FUNC_ScriptEngineDoScriptFile)(wchar_t * ScriptFileName);
typedef int (		*FUNC_ScriptEngineDebugScriptFile)(wchar_t * ScriptFileName);
typedef int (		*FUNC_ScriptEngineDebugMemoryScript)(wchar_t * ScriptFileName);

typedef HANDLE (	*FUNC_CreateScriptEngine)();
typedef BOOL (		*FUNC_LoadScript)(HANDLE hScript,const wchar_t * ScriptFilePathName);
typedef BOOL (		*FUNC_ScriptObjectToWString)(HANDLE hScript,wchar_t * ObjectName,wchar_t *ObjectBuffer,size_t BufferSize);
typedef BOOL (		*FUNC_ScriptObjectToInt)(HANDLE hScript, wchar_t * ObjectName, int * Value);
typedef BOOL (		*FUNC_ScriptObjectToDouble)(HANDLE hScript, wchar_t * ObjectName, double * Value);
typedef BOOL(		*FUNC_ScriptObjectToInt64)(HANDLE hScript, wchar_t * ObjectName, __int64 * Value);
typedef BOOL (		*FUNC_ScriptCallFunction)(HANDLE hScript,wchar_t * FunctionAndParameter);
typedef void (		*FUNC_CloseScriptEngine)(HANDLE &hScript);
typedef BOOL (		*FUNC_ScriptRegisterUICallBack)(HANDLE hScript,void * uiclass,UICallBack callback);
typedef BOOL (		*FUNC_ScriptRegisterUIStepCallBack)(HANDLE hScript,void * uiclass,UICallBack callback);
typedef int (		*FUNC_ScriptGetCurrentCommandLine)(HANDLE hScript);
typedef void (		*FUNC_ScriptEnumObjects)(HANDLE hScript,VTSTRINGS **objects);
typedef void (		*FUNC_ScriptReleaseObjects)(VTSTRINGS**objects);
typedef int (		*FUNC_ScriptDoScript)(HANDLE hScript,const wchar_t * scriptfilename,SCRIPTRUNTYPE mode);
typedef int (		*FUNC_ScriptDebugMemoryScript)(HANDLE hScript,wchar_t * MemoryScript);

typedef int (		*FUNC_ScriptAddBreakPoints)(HANDLE hScript,int line);
typedef int (		*FUNC_ScriptEraseBreakPoint)(HANDLE hScript,int line);
typedef void (		*FUNC_ScriptDumpObject)(HANDLE hScript,const wchar_t *  objectname);
typedef int (		*FUNC_ScriptDumpScript)(HANDLE hScript,const wchar_t *  newscriptfilename);
typedef void (		*FUNC_ScriptSetDebugEvent)(HANDLE hScript);
typedef bool (		*FUNC_ScriptReadScript)(const wchar_t *  scriptfilename,VTSTRINGS** body);
typedef void (		*FUNC_ScriptReleaseScript)(VTSTRINGS** body);
typedef BOOL (		*FUNC_ScriptRegisterGlobalCommand)(HANDLE hScript, const wchar_t * chscommandstring, const wchar_t * engcommandstring, DWORD commandid, GlobalCommandFunctionPtr);
typedef int (		*FUNC_ScriptDoByteCode)(HANDLE hScript, const wchar_t * bytecodefilename, SCRIPTRUNTYPE mode );
typedef int (		*FUNC_ScriptDoMemByteCode)(HANDLE hScript, const unsigned char  * membytecode, int length, SCRIPTRUNTYPE mode );
typedef int	(		*FUNC_ScriptSetJit)(HANDLE hScript, int Jit);
typedef int (		*FUNC_ScriptDumpByteCode)(HANDLE hScript, wchar_t * ByteCodeFile);
typedef int (		*FUNC_ScriptDoString)(HANDLE hScript, const wchar_t * ScriptString);
typedef int	(		*FUNC_ScriptSetDebugger)(HANDLE hScript, void * debugger);
typedef int (		*FUNC_ScriptSetScriptFileName)(HANDLE hScript, const wchar_t * ScriptFileName);
typedef int (		*FUNC_ScriptGetObjectType)(HANDLE hScript, const wchar_t * ObjectName, wchar_t *ObjectTypeBuffer, int BufferLength);
typedef int (		*FUNC_ScriptGetObjectFuncList)(HANDLE hScript, const wchar_t * ObjectName, wchar_t *ObjectFuncBuffer, int BufferLength);
