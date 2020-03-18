#include "ffxiv_assistant.h"
#include <windows.h>
#include <tlhelp32.h>

std::vector<Process> processes;

ffxiv_assistant::ffxiv_assistant(QWidget *parent)
	: QWidget(parent)
	, m_pHook(nullptr)
	, m_pDoAction(nullptr)
{
	ui.setupUi(this);

	init();
}

void ffxiv_assistant::init()
{
	// process
	enumProcess();
	// ctrl
	initctrl();
	// signal and slot
	connectSignalAndSlot();
	// status
	updateStatus(Wait);
	// hook
	auto func = std::bind(&ffxiv_assistant::HookKeyProc, this, std::placeholders::_1, std::placeholders::_2);
	m_pHook = new (std::nothrow)CHook(func);
	m_pDoAction = new (std::nothrow)CDoAction();
}

BOOL CALLBACK EnumWindowsProc(HWND hwnd, LPARAM lParam)
{
	DWORD pid = (DWORD)lParam;
	DWORD dwProcessID = 0;
	::GetWindowThreadProcessId(hwnd, &dwProcessID);
	if (dwProcessID == pid
		&& IsWindow(hwnd)
		&& NULL == GetParent(hwnd)
		)
	{
#ifndef DEMO_TEST
		char buf[256] = { 0 };
		GetWindowTextA(hwnd, buf, 256);
		if (strcmp(buf, "最终幻想XIV") == 0)
#endif
		{
			Process tmp;
			tmp.nPid = dwProcessID;
			tmp.hWnd = hwnd;
			processes.push_back(tmp);
		}
	}

	return TRUE;
}

void ffxiv_assistant::enumProcess()
{
	HANDLE hProcessSnap = NULL;
	PROCESSENTRY32 pe32;
	pe32.dwSize = sizeof(PROCESSENTRY32);
	hProcessSnap = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);
	BOOL bFind = Process32First(hProcessSnap, &pe32);
	while (bFind)
	{
#ifndef DEMO_TEST
		if (strcmp("ffxiv_dx11.exe", pe32.szExeFile) == 0 ||
			strcmp("ffxiv.exe", pe32.szExeFile) == 0)
#else
		if (strcmp("notepad++.exe", pe32.szExeFile) == 0)
#endif
		{
			EnumWindows(EnumWindowsProc, (DWORD)pe32.th32ProcessID);
		}
		bFind = Process32Next(hProcessSnap, &pe32);
	}
	CloseHandle(hProcessSnap);

}

void ffxiv_assistant::initctrl()
{
	ui.kRecord_start->setEnabled(true);
	ui.kRecord_end->setEnabled(false);

	ui.kDo_start->setEnabled(false);
	ui.kDo_end->setEnabled(false);

	for each (auto var in processes)
	{
		char buf[256] = { 0 };
		sprintf_s(buf, 256, "ffxiv_%d", var.nPid);
		ui.comboBox->addItem(QString(buf));
	}
}

void ffxiv_assistant::connectSignalAndSlot()
{
	connect(ui.kRecord_start, &QPushButton::clicked, [=]() {
		ui.kRecord_start->setEnabled(false);
		ui.kRecord_end->setEnabled(true);
		updateStatus(Recording);
		ActiveTop(true);
		recordAction(true);
		
	});
	connect(ui.kRecord_end, &QPushButton::clicked, [=]() {
		ui.kRecord_start->setEnabled(true);
		ui.kRecord_end->setEnabled(false);
		updateStatus(Recorded);
		ActiveTop(false);
		recordAction(false);
	});
	connect(ui.kDo_start, &QPushButton::clicked, [=]() {
		ui.kDo_start->setEnabled(false);
		ui.kDo_end->setEnabled(true);
		updateStatus(Doing);
		doAction(true);
	});
	connect(ui.kDo_end, &QPushButton::clicked, [=]() {
		ui.kDo_start->setEnabled(true);
		ui.kDo_end->setEnabled(false);
		updateStatus(Recorded);
		doAction(false);
	});
}

void ffxiv_assistant::updateStatus(Status _status)
{
	QString status_str;
	switch (_status)
	{
	case Wait:
		status_str = QString::fromLocal8Bit("等待记录...");
		break;
	case Recording:
		status_str = QString::fromLocal8Bit("正在记录...");
		break;
	case Recorded:
		status_str = QString::fromLocal8Bit("已记录完毕!");
		break;
	case Doing:
		status_str = QString::fromLocal8Bit("正在执行...");
		break;
	default:
		break;
	}

	ui.label_status->setText(status_str);
}

void ffxiv_assistant::recordAction(bool bStart)
{
	if (bStart)
	{	// start
		m_vecPosinfo.clear();
		StatusInfo tmp;
		tmp.nKeyId = -1;
		tmp._time = ::GetTickCount64();
		m_vecPosinfo.push_back(tmp);
		if (nullptr != m_pHook)
		{
			m_pHook->StartHook();
		}
	}
	else
	{	// end
		if (nullptr != m_pHook)
		{
			m_pHook->EndHook();
		}
		if (m_vecPosinfo.size() >= 2)
		{
			StatusInfo tmp;
			tmp.nKeyId = -1;
			tmp._time = ::GetTickCount64();
			m_vecPosinfo.push_back(tmp);

			ui.kDo_start->setEnabled(true);
		}
	}
}

void ffxiv_assistant::doAction(bool bStart)
{
	if (bStart)
	{	// start
		if (nullptr != m_pDoAction &&
			m_vecPosinfo.size() > 1 &&
			ui.comboBox->count() > 0 &&
			processes.size() > ui.comboBox->currentIndex())
		{
			m_pDoAction->StartAction(m_vecPosinfo, processes[ui.comboBox->currentIndex()].hWnd);
		}
	}
	else
	{	// end
		if (nullptr != m_pDoAction)
		{
			m_pDoAction->EndAction();
		}
	}
}

void ffxiv_assistant::HookKeyProc(int nKeyId, ULONGLONG _time)
{
	StatusInfo tmp;
	tmp.nKeyId = nKeyId;
	tmp._time = _time;
	m_vecPosinfo.push_back(tmp);
	char buf[256] = { 0 };
	sprintf_s(buf, 256, "[add key record] key: %d\n", tmp.nKeyId);
	OutputDebugString(buf);
}

void ffxiv_assistant::ActiveTop(bool bTop)
{
	setWindowFlag(Qt::WindowStaysOnTopHint, bTop);
	this->showNormal();
}
