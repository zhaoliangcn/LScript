#pragma once
#include "../include/ScriptDebugger.h"
#include "stdafx.h"
#include <vector>
#include <string>
#include <map>

class CMainFrame;
typedef std::vector<int > VtScriptBreakPoints;
typedef std::vector<int >::iterator ItScriptBreakPoints;
class CMiniScriptDebuggerDlg;
class LScriptDebugger :
	public IScriptDebugger
{
public:
	LScriptDebugger();
	~LScriptDebugger();

	virtual int SetRunMode(SCRIPTRUNTYPE runmode);
	virtual int SetBreakPoint(const wchar_t* scriptFile, int linenumber,bool set);
	virtual void SetDebugEvent();
	virtual int CheckDebugEvent(const wchar_t* currentScript, int currentLine, int timeOut) ;

	bool matchBreakPoint(const wchar_t* scriptFile, int linenumber);
	void Init();
	int WaitDebugEvent(int timeOut);
	void ClearBreakPoints();

	std::map<std::wstring, VtScriptBreakPoints> mpBreakPoints;
	SCRIPTRUNTYPE scriptRunMode;
	CMainFrame *mainframe;
	HANDLE hEngine;
#ifdef WIN32
	HANDLE heventDebug;
#else 

#endif
};

