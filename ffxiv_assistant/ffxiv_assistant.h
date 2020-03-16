#pragma once

#include <QtWidgets/QWidget>
#include "ui_ffxiv_assistant.h"
#include "struct_def.h"
#include <vector>

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

private:
	Ui::ffxiv_assistantClass ui;

private:
	std::vector<StatusInfo> m_vecPosinfo;
};
