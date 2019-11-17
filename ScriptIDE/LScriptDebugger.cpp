#include "stdafx.h"
#include "LScriptDebugger.h"
#include <algorithm>
#include "MainFrm.h"
#include "../include/ScriptEngineDll.h"

LScriptDebugger::LScriptDebugger()
{
	hEngine = NULL;
	Init();
}


LScriptDebugger::~LScriptDebugger()
{
	CloseHandle(heventDebug);
}

int LScriptDebugger::SetRunMode(SCRIPTRUNTYPE runmode)
{
	scriptRunMode = runmode;	
	return scriptRunMode;
}

int LScriptDebugger::SetBreakPoint(const wchar_t * scriptFile, int linenumber, bool set)
{
	if (mpBreakPoints.find(scriptFile) != mpBreakPoints.end())
	{
		VtScriptBreakPoints& breakpoints = mpBreakPoints[scriptFile];
		ItScriptBreakPoints it = std::find(breakpoints.begin(), breakpoints.end(), linenumber);
		if (it == breakpoints.end())
		{
			if (set)
			{
				breakpoints.push_back(linenumber);
			}
			else
			{
				breakpoints.erase(it);
			}
		}
		
	}
	else
	{
		if (set)
		{
			VtScriptBreakPoints breakpoints;
			breakpoints.push_back(linenumber);
			mpBreakPoints[scriptFile] = breakpoints;
		}
	}
	return 0;
}

void LScriptDebugger::SetDebugEvent()
{
#ifdef _WIN32
	SetEvent(heventDebug);
#endif
}

int LScriptDebugger::CheckDebugEvent(const wchar_t * currentScript, int currentLine, int timeOut)
{
	if (matchBreakPoint(currentScript, currentLine))
	{
		std::wstring mess = L"BreakPointMatched! At Line ";
		wchar_t buffer[32] = { 0 };
		mess += _itow(currentLine, buffer,10);
		if (mainframe)
		{
			mainframe->m_wndOutput.AppendDebugOutput(mess.c_str());

			VTSTRINGS *objs;
			ScriptEnumObjects(hEngine, &objs);
			mainframe->m_wndClassView.m_wndClassView.DeleteAllItems();
			HTREEITEM itemRoot = mainframe->m_wndClassView.m_wndClassView.InsertItem(L"È«¾Ö");
			mainframe->m_wndClassView.m_wndClassView.SetItemState(itemRoot, TVIS_BOLD, TVIS_BOLD);
			for (ITSTRINGS it = objs->begin();it != objs->end();it++)
			{				
				std::wstring temp = (*it);
				HTREEITEM item = mainframe->m_wndClassView.m_wndClassView.InsertItem(temp.c_str(), itemRoot);
				
				
/*				std::wstring temp2;
				size_t pos = temp.find(L",");
				if (pos != std::wstring::npos)
				{
					temp2 = temp.substr(0, pos);
					temp = temp.substr(pos + 1, temp.length() - pos - 1);
				}
				HTREEITEM item=mainframe->m_wndClassView.m_wndClassView.InsertItem(temp.c_str(), itemRoot);			*/	
			}
			mainframe->m_wndClassView.m_wndClassView.Expand(itemRoot, TVE_EXPAND);
			ScriptReleaseObjects(&objs);
		}
		
		WaitDebugEvent(timeOut);
	}
	return 0;
}

bool LScriptDebugger::matchBreakPoint(const wchar_t * scriptFile, int linenumber)
{
	if (scriptRunMode == RUN_SINGLESTEP)
	{
		return true;
	}
	else
	{

		if (mpBreakPoints.find(scriptFile) != mpBreakPoints.end())
		{
			VtScriptBreakPoints& breakpoints = mpBreakPoints[scriptFile];
			if (std::find(breakpoints.begin(), breakpoints.end(), linenumber) != breakpoints.end())
			{
				return true;
			}
		}
	}
	return false;
}
void LScriptDebugger::ClearBreakPoints()
{
	std::map<std::wstring, VtScriptBreakPoints>::iterator it = mpBreakPoints.begin();
	while (it != mpBreakPoints.end())
	{
		VtScriptBreakPoints& breakpoints = it->second;
		breakpoints.clear();
		it = mpBreakPoints.erase(it);
	}
}
void LScriptDebugger::Init()
{
#ifdef WIN32
	heventDebug = CreateEvent(NULL, TRUE, FALSE, NULL);
#else
#endif

}

int LScriptDebugger::WaitDebugEvent(int timeOut)
{
	int  ret = 0;
#ifdef _WIN32
	DWORD dwWait=WaitForSingleObject(heventDebug, timeOut);
	if (dwWait != WAIT_OBJECT_0)
	{
		ret = -1;
	}
	ResetEvent(heventDebug);
#endif
	return ret;
}
