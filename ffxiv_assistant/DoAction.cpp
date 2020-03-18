#include "DoAction.h"
#include <functional>

CDoAction::CDoAction()
	: m_posinfo()
	, m_hWnd(NULL)
	, m_bStop(true)
	, m_trd(nullptr)
{
}

CDoAction::~CDoAction()
{
}

void CDoAction::StartAction(const std::vector<StatusInfo>& posinfo, HWND hWnd)
{
	if (m_bStop)
	{
		m_bStop = false;
		m_posinfo = posinfo;
		m_hWnd = hWnd;
		m_trd = new (std::nothrow)std::thread(std::bind(&CDoAction::run, this));
	}
}

void CDoAction::EndAction()
{
	m_bStop = true;
	m_trd->join();
	delete m_trd;
}

void CDoAction::run()
{
	while (!m_bStop)
	{
		ULONGLONG tNow = ::GetTickCount64();
		ULONGLONG tFirst = m_posinfo[0]._time;
		for (int i = 1; i < m_posinfo.size(); ++i)
		{
			while (!m_bStop)
			{
				ULONGLONG tCur = ::GetTickCount64();
				if ((m_posinfo[i]._time - tFirst) <= (tCur - tNow))
				{
					if (i == (m_posinfo.size() - 1))
					{
						break;
					}
					::PostMessage(m_hWnd, WM_KEYDOWN, m_posinfo[i].nKeyId, 1);
					::PostMessage(m_hWnd, WM_KEYUP, m_posinfo[i].nKeyId, 1);

					char buf[256] = { 0 };
					sprintf_s(buf, 256, "[post key] key: %d\n", m_posinfo[i].nKeyId);
					OutputDebugString(buf);

					break;
				}
				Sleep(200);
			}
		}
	}
}