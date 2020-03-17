#pragma once

#include <QtWidgets/QWidget>
#include "ui_ffxiv_assistant.h"
#include "struct_def.h"
#include <vector>
#include "Hook.h"
#include "DoAction.h"

class ffxiv_assistant : public QWidget
{
	Q_OBJECT

public:
	ffxiv_assistant(QWidget *parent = Q_NULLPTR);

private:
	void init();
	void enumProcess();
	void initctrl();
	void connectSignalAndSlot();
	void updateStatus(Status _status);
	void recordAction(bool bStart);
	void doAction(bool bStart);
	void HookMouseProc(int x, int y, ULONGLONG _time);
	void ActiveTop(bool bTop);

private:
	Ui::ffxiv_assistantClass ui;

private:
	std::vector<StatusInfo> m_vecPosinfo;
	CHook* m_pHook;
	CDoAction* m_pDoAction;
};
