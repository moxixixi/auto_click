#pragma once
#include <time.h>
#include <windows.h>
#include <functional>

typedef std::function<void(int x, int y, ULONGLONG _time)> pHookMouseProc;

class CHook
{
public:
	CHook(pHookMouseProc pFn);
	~CHook();

public:
	void StartHook();
	void EndHook();

private:
	static LRESULT CALLBACK HookMouseProc(int nCode, WPARAM wParam, LPARAM lParam);
};