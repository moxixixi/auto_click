#include "ffxiv_assistant.h"
#include <windows.h>
#include <tlhelp32.h>

std::vector<Process> processes;

ffxiv_assistant::ffxiv_assistant(QWidget *parent)
	: QWidget(parent)
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
}

BOOL CALLBACK EnumWindowsProc(HWND hwnd, LPARAM lParam)
{
	DWORD pid = (DWORD)lParam;
	DWORD dwProcessID = 0;
	::GetWindowThreadProcessId(hwnd, &dwProcessID);
	if (dwProcessID == pid &&
		IsWindow(hwnd) &&
		NULL == GetParent(hwnd))
	{
		char buf[256] = { 0 };
		GetWindowTextA(hwnd, buf, 256);
		if (strcmp(buf, "最终幻想XIV") == 0)
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
		if (strcmp("ffxiv_dx11.exe", pe32.szExeFile) == 0 ||
			strcmp("ffxiv.exe", pe32.szExeFile) == 0)
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
		recordAction(true);
	});
	connect(ui.kRecord_end, &QPushButton::clicked, [=]() {
		ui.kRecord_start->setEnabled(true);
		ui.kRecord_end->setEnabled(false);
		updateStatus(Recorded);
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
	}
	else
	{	// end

	}
}

void ffxiv_assistant::doAction(bool bStart)
{
	if (bStart)
	{	// start
	}
	else
	{	// end

	}
}