#pragma once
#include <string>
#include <windows.h>
#include <time.h>

typedef struct tagProcess
{
	DWORD nPid;
	HWND hWnd;
}Process;

enum Status
{
	Wait = 0,
	Recording,
	Recorded,
	Doing,
};

typedef struct tagStatusInfo
{
	int x;
	int y;
	ULONGLONG _time;
}StatusInfo;