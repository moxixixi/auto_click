#pragma once
#include "struct_def.h"
#include <vector>

class CDoAction
{
public:
	CDoAction();
	~CDoAction();

public:
	void StartAction(const std::vector<StatusInfo>& posinfo, HWND hWnd);
	void EndAction();

private:
	std::vector<StatusInfo> m_posinfo;
	HWND m_hWnd;
};

