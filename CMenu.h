//Plik : CMenu.h

#pragma once
#ifndef CMenu_h
#define Cmenu_h

#include <vector>
#include <iostream>
#include <string>
#include "CMenuItem.h"
#include "CMenuCommand.h"
#include "CVector.h"
#include "CCONS_h.h"
#include "CNewTable.h"
#include "CClone.h"
#include "CPrintTab.h"
#include "CDeleteAllTab.h"
#include "CDeleteTab.h"
#include "CChangeLength.h"
#include "CChangeName.h"
#include "CChangeVal.h"
#include "CVector.h"
#include "CCONS_h.h"

class CMenu : public virtual CMenuItem
{
public:
	~CMenu();
	CMenu();
	CMenu(string sName, string sCommand,string sString,CMenuItem * mParrent);
	string sRun();
	void vInitialize(CVector *vector);
	void vAddCommand(string sName, string sCommand, CCommand *ccpi_command,string s_text);
	void vAddMenu(string sName, string sCommand, string sDisplay,CMenuItem* cParrent);
	virtual string sGetText();
	virtual string sGetCommand();
	virtual string sGetName();
	CMenuItem* mGetParrent();
	bool sSearch(string sCommand, vector <string>* v_string,string s_droga);
	void split(const string& s, char c, vector<string>& v);
	virtual void vDeleteAll();
	string vSave(string s_acc);
	void vAddCMenuItem(CMenuItem &CMenuItem_item);
private:
	vector <CMenuItem*> v_piitems;
	void vPrint(bool bBol);
	string s_display_text;
};
#endif