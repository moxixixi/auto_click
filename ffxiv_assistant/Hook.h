#pragma once
#include <time.h>
#include <windows.h>
#include <functional>

typedef std::function<void(int nKeyId, ULONGLONG _time)> pHookMouseProc;

class CHook
{
public:
	CHook(pHookMouseProc pFn);
	~CHook();

public:
	void StartHook();
	void EndHook();

private:
	static LRESULT CALLBACK HookKeyProc(int nCode, WPARAM wParam, LPARAM lParam);
};