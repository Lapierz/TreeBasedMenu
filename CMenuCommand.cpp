#include "pch.h"
#include "CMenuCommand.h"

CMenuCommand::CMenuCommand() {
	s_command = S_DEF_COMMAND;
	s_name = S_DEF_NAME;
	ccpi_command = nullptr;
}

CMenuCommand::CMenuCommand(string sName, string sCommand,CCommand *ccpi_command,string sText) {
	s_command = sCommand;
	s_name = sName;
	this->ccpi_command = ccpi_command;
	s_display_text = sText;
}

CMenuCommand::~CMenuCommand() {
	delete ccpi_command;
}

string CMenuCommand::sGetCommand() {
	return s_command;
} 

string CMenuCommand::sGetName() {
	return s_name;
} 

string CMenuCommand::sGetText() {
	return s_display_text;
}


CMenuItem *CMenuCommand::mGetParrent() {
	return nullptr;
}
bool CMenuCommand::sSearch(string sCommand, vector <string> *v_string, string sPath) {
	if (sGetCommand() == sCommand) {
		v_string->push_back(sPath +sCommand);
		v_string->push_back(sGetText());
		return true;
	}
	return false;
}

string CMenuCommand::vSave(string s_acc) {
	return S_REC_7 + sGetName() + S_REC_8 + sGetCommand() + S_REC_8 + sGetText()+ S_REC_9;
}

string CMenuCommand::sRun() {
	if (!ccpi_command) {
		cout << S_EMPTY_COMMAND << endl;
	}
	else {
		ccpi_command->vRunCommand();
	}
	return S_EMPTY_STRING;
}

