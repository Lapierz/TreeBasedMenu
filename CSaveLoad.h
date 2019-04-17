#pragma once
#ifndef CSaveLoad_h
#define CSaveLoad_h

#include <string>
#include <iostream>
#include <fstream>
#include "CMenuItem.h"
#include "CMenu.h"
#include "CCONS_h.h"

class CSaveLoad
{
public:
	CSaveLoad() {}
	~CSaveLoad() {}
	void vSave(CMenuItem* parent);
	void vLoad();
private:
	bool bCorrect(string s_acc);
	bool bMenuCorrect(string data, int& i, bool correct);
	bool bMenuCommandCorrect(string data, int& i, bool correct);
	void vCreateMenu(string& data);
	CMenuCommand* cMenuCommand(string& data, int& i, CMenuItem &c_item);
	CMenu* cMenu(string& data, int& i, CMenuItem &c_item);
};

#endif
