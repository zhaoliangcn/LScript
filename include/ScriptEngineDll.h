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

#ifdef __cplusplus
extern "C" {
#endif
	int 	ScriptEngineDoString(wchar_t * ScriptString);
	int 	ScriptEngineDoScriptFile(wchar_t * ScriptFileName);
	int 	ScriptEngineDebugScriptFile(wchar_t * ScriptFileName);
	int 	ScriptEngineDebugMemoryScript(wchar_t * ScriptFileName);

	HANDLE  CreateScriptEngine();
	BOOL 	LoadScript(HANDLE hScript, const wchar_t * ScriptFilePathName);
	BOOL 	ScriptObjectToWString(HANDLE hScript, wchar_t * ObjectName, wchar_t *ObjectBuffer, size_t BufferSize);
	BOOL 	ScriptObjectToInt(HANDLE hScript, wchar_t * ObjectName, int * Value);
	BOOL 	ScriptObjectToDouble(HANDLE hScript, wchar_t * ObjectName, double * Value);
	BOOL 	ScriptObjectToInt64(HANDLE hScript, wchar_t * ObjectName, __int64 * Value);
	BOOL 	ScriptCallFunction(HANDLE hScript, wchar_t * FunctionAndParameter);
	void 	CloseScriptEngine(HANDLE &hScript);
	BOOL 	ScriptRegisterUICallBack(HANDLE hScript, void * uiclass, UICallBack callback);
	BOOL 	ScriptRegisterUIStepCallBack(HANDLE hScript, void * uiclass, UICallBack callback);
	int 	ScriptGetCurrentCommandLine(HANDLE hScript);
	void 	ScriptEnumObjects(HANDLE hScript, VTSTRINGS **objects);
	void 	ScriptReleaseObjects(VTSTRINGS**objects);
	int 	ScriptDoScript(HANDLE hScript, const wchar_t * scriptfilename, SCRIPTRUNTYPE mode = RUN_NORMAL);
	int 	ScriptDebugMemoryScript(HANDLE hScript, wchar_t * MemoryScript);
	int 	ScriptAddBreakPoints(HANDLE hScript, int line); //ÒÑ·ÏÆú
	int 	ScriptEraseBreakPoint(HANDLE hScript, int line);//ÒÑ·ÏÆú
	void 	ScriptDumpObject(HANDLE hScript, const wchar_t *  objectname);
	int 	ScriptDumpScript(HANDLE hScript, const wchar_t *  newscriptfilename);
	void 	ScriptSetDebugEvent(HANDLE hScript);//ÒÑ·ÏÆú
	bool 	ScriptReadScript(const wchar_t *  scriptfilename, VTSTRINGS** body);
	void 	ScriptReleaseScript(VTSTRINGS** body);
	BOOL 	ScriptRegisterGlobalCommand(HANDLE hScript, const wchar_t * chscommandstring, const wchar_t * engcommandstring, DWORD commandid, GlobalCommandFunctionPtr);
	int 	ScriptDoByteCode(HANDLE hScript, const wchar_t * bytecodefilename, SCRIPTRUNTYPE mode = RUN_NORMAL);
	int 	ScriptDoMemByteCode(HANDLE hScript, const unsigned char  * membytecode, int length, SCRIPTRUNTYPE mode = RUN_NORMAL);
	int 	ScriptSetJit(HANDLE hScript, int Jit);
	int 	ScriptDumpByteCode(HANDLE hScript, const wchar_t * ByteCodeFile);
	int 	ScriptDoString(HANDLE hScript, const wchar_t * ScriptString);
	int 	ScriptSetDebugger(HANDLE hScript, void * debugger);
	int 	ScriptSetScriptFileName(HANDLE hScript, const wchar_t * ScriptFileName);
	int 	ScriptGetObjectType(HANDLE hScript, const wchar_t * ObjectName, wchar_t *ObjectTypeBuffer, int BufferLength);
	int 	ScriptGetObjectFuncList(HANDLE hScript, const wchar_t * ObjectName, wchar_t *ObjectFuncBuffer, int BufferLength);

	typedef int(		*FUNC_ScriptEngineDoString)(wchar_t * ScriptString);
	typedef int(		*FUNC_ScriptEngineDoScriptFile)(wchar_t * ScriptFileName);
	typedef int(		*FUNC_ScriptEngineDebugScriptFile)(wchar_t * ScriptFileName);
	typedef int(		*FUNC_ScriptEngineDebugMemoryScript)(wchar_t * ScriptFileName);

	typedef HANDLE(	*FUNC_CreateScriptEngine)();
	typedef BOOL(		*FUNC_LoadScript)(HANDLE hScript, const wchar_t * ScriptFilePathName);
	typedef BOOL(		*FUNC_ScriptObjectToWString)(HANDLE hScript, wchar_t * ObjectName, wchar_t *ObjectBuffer, size_t BufferSize);
	typedef BOOL(		*FUNC_ScriptObjectToInt)(HANDLE hScript, wchar_t * ObjectName, int * Value);
	typedef BOOL(		*FUNC_ScriptObjectToDouble)(HANDLE hScript, wchar_t * ObjectName, double * Value);
	typedef BOOL(		*FUNC_ScriptObjectToInt64)(HANDLE hScript, wchar_t * ObjectName, __int64 * Value);
	typedef BOOL(		*FUNC_ScriptCallFunction)(HANDLE hScript, wchar_t * FunctionAndParameter);
	typedef void(		*FUNC_CloseScriptEngine)(HANDLE &hScript);
	typedef BOOL(		*FUNC_ScriptRegisterUICallBack)(HANDLE hScript, void * uiclass, UICallBack callback);
	typedef BOOL(		*FUNC_ScriptRegisterUIStepCallBack)(HANDLE hScript, void * uiclass, UICallBack callback);
	typedef int(		*FUNC_ScriptGetCurrentCommandLine)(HANDLE hScript);
	typedef void(		*FUNC_ScriptEnumObjects)(HANDLE hScript, VTSTRINGS **objects);
	typedef void(		*FUNC_ScriptReleaseObjects)(VTSTRINGS**objects);
	typedef int(		*FUNC_ScriptDoScript)(HANDLE hScript, const wchar_t * scriptfilename, SCRIPTRUNTYPE mode);
	typedef int(		*FUNC_ScriptDebugMemoryScript)(HANDLE hScript, wchar_t * MemoryScript);

	typedef int(		*FUNC_ScriptAddBreakPoints)(HANDLE hScript, int line);
	typedef int(		*FUNC_ScriptEraseBreakPoint)(HANDLE hScript, int line);
	typedef void(		*FUNC_ScriptDumpObject)(HANDLE hScript, const wchar_t *  objectname);
	typedef int(		*FUNC_ScriptDumpScript)(HANDLE hScript, const wchar_t *  newscriptfilename);
	typedef void(		*FUNC_ScriptSetDebugEvent)(HANDLE hScript);
	typedef bool(		*FUNC_ScriptReadScript)(const wchar_t *  scriptfilename, VTSTRINGS** body);
	typedef void(		*FUNC_ScriptReleaseScript)(VTSTRINGS** body);
	typedef BOOL(		*FUNC_ScriptRegisterGlobalCommand)(HANDLE hScript, const wchar_t * chscommandstring, const wchar_t * engcommandstring, DWORD commandid, GlobalCommandFunctionPtr);
	typedef int(		*FUNC_ScriptDoByteCode)(HANDLE hScript, const wchar_t * bytecodefilename, SCRIPTRUNTYPE mode);
	typedef int(		*FUNC_ScriptDoMemByteCode)(HANDLE hScript, const unsigned char  * membytecode, int length, SCRIPTRUNTYPE mode);
	typedef int(		*FUNC_ScriptSetJit)(HANDLE hScript, int Jit);
	typedef int(		*FUNC_ScriptDumpByteCode)(HANDLE hScript, wchar_t * ByteCodeFile);
	typedef int(		*FUNC_ScriptDoString)(HANDLE hScript, const wchar_t * ScriptString);
	typedef int(		*FUNC_ScriptSetDebugger)(HANDLE hScript, void * debugger);
	typedef int(		*FUNC_ScriptSetScriptFileName)(HANDLE hScript, const wchar_t * ScriptFileName);
	typedef int(		*FUNC_ScriptGetObjectType)(HANDLE hScript, const wchar_t * ObjectName, wchar_t *ObjectTypeBuffer, int BufferLength);
	typedef int(		*FUNC_ScriptGetObjectFuncList)(HANDLE hScript, const wchar_t * ObjectName, wchar_t *ObjectFuncBuffer, int BufferLength);
#ifdef __cplusplus
}
#endif

