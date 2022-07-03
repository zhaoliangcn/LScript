#ifndef _H_SCRIPTDEBUGGER
#define _H_SCRIPTDEBUGGER


#ifndef _EM_SCRIPTRUNTYPE
#define _EM_SCRIPTRUNTYPE
typedef enum _tag_SCRIPTRUNTYPE
{
	RUN_NORMAL,
	RUN_DEBUG,
	RUN_SINGLESTEP,
}SCRIPTRUNTYPE;

#endif //_EM_SCRIPTRUNTYPE

class IScriptDebugger
{
public:
	IScriptDebugger()
	{

	}
	~IScriptDebugger()
	{

	}
	virtual int SetRunMode(SCRIPTRUNTYPE runmode) = 0;
	virtual int SetBreakPoint(const wchar_t* scriptFile, int linenumber, bool set) = 0;
	virtual void SetDebugEvent() = 0;
	virtual int CheckDebugEvent(const wchar_t* currentScript, int currentLine,int timeOut)=0;
};
#endif//_H_SCRIPTDEBUGGER