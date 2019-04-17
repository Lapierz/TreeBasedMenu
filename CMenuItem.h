#pragma once
#ifndef CMenuItem_h
#define CMenuItem_h

#include <string>
#include <vector>
using namespace std;

class CMenuItem
{
protected:
	string s_command;
	string s_name;
	CMenuItem *parrent;
public:
	virtual ~CMenuItem() { }
	virtual string sRun() = 0;
	virtual string sGetCommand() = 0;
	virtual string sGetName() = 0;
	virtual string sGetText() = 0;
	virtual CMenuItem* mGetParrent() = 0;
	virtual bool  sSearch(string sCommand, vector <string> *v_string,string droga) = 0;
	virtual string vSave(string s_acc)=0;
};
#endif 