#pragma once
#include "struct_def.h"
#include <vector>
#include <thread>

class CDoAction
{
public:
	CDoAction();
	~CDoAction();

public:
	void StartAction(const std::vector<StatusInfo>& posinfo, HWND hWnd);
	void EndAction();

private:
	void run();

private:
	std::vector<StatusInfo> m_posinfo;
	HWND m_hWnd;
	volatile bool m_bStop;
	std::thread* m_trd;
};

