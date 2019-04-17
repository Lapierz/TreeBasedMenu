#pragma once
#ifndef CMenuCommand_h
#define CMenuCommand_h

#include "CCommand.h"
#include "CMenuItem.h"
#include <iostream>
#include "CCONS_h.h"

class CMenuCommand : public virtual CMenuItem
{
public:
	CMenuCommand ();
	CMenuCommand(string sName, string sCommand, CCommand *ccpi_command,string sText);
	~CMenuCommand();
	string sRun();
	virtual string sGetCommand();
	virtual string sGetName();
	CMenuItem* mGetParrent();
	virtual string sGetText();
	virtual bool sSearch(string sCommand, vector <string> *v_string,string droga);
	string vSave(string s_acc);
private:
	CCommand* ccpi_command ;
	string s_display_text;;
};
#endif 
