#include "pch.h"
#include "CMenu.h"


CMenu::CMenu(string sName, string sCommand, string sString, CMenuItem* mParent) {
	s_command = sCommand;
	s_name = sName;
	s_display_text= sString;
	parrent = mParent;
} 

CMenu::CMenu() {
	s_command = S_MAIN;
	s_name = S_MENU;
	parrent = nullptr;
}

CMenu::~CMenu() {
	vDeleteAll();
}

void CMenu::vInitialize(CVector *vector) {

	CMenu* pi_create_m = new CMenu(S_CREATE_N, S_CREATE_C, S_TEXT_CREATE,this);
	CMenu* pi_print_m = new CMenu(S_DISPLAY_N, S_DISPLAY_C, S_TEXT_PRINT,this);
	CMenu* pi_delete_m = new CMenu(S_DELETE_N,S_DELETE_C, S_TEXT_DELETE,this);
	CMenu* pi_edit_m = new CMenu(S_EDIT_N, S_EDIT_C, S_TEXT_EDIT,this);

	CNewTable* pi_new = new CNewTable(vector->pi_pointer());
	CClone* pi_clone = new CClone(vector->pi_pointer());
	CPrintAllTab* pi_printall = new CPrintAllTab(vector->pi_pointer());
	CPrintTab* pi_print = new CPrintTab(vector->pi_pointer());
	CDeleteAllTab* pi_deleteall = new CDeleteAllTab(vector->pi_pointer());
	CDeleteTab* pi_delete = new CDeleteTab(vector->pi_pointer());
	CChangeLength* pi_changelen = new CChangeLength(vector->pi_pointer());
	CChangeName* pi_changename = new CChangeName(vector->pi_pointer());
	CChangeVal* pi_changeval = new CChangeVal(vector->pi_pointer());

	pi_create_m->vAddCommand(S_CREATE_NEW_TAB_N, S_CREATE_NEW_TAB_C, pi_new, S_TEXT_NEW);
	pi_create_m->vAddCommand(S_CLONE_TAB_N, S_CLONE_TAB_C, pi_clone, S_TEXT_CLONE);
	pi_print_m->vAddCommand(S_DISPLAY_ALL_N, S_DISPLAY_ALL_C, pi_printall, S_TEXT_PRINTALL);
	pi_print_m->vAddCommand(S_PRINT_ONE_TAB_N, S_PRINT_ONE_TAB_C, pi_print, S_TEXT_PRINTONE);
	pi_delete_m->vAddCommand(S_DELETE_ALL_TAB_N, S_DELETE_ALL_TAB_C, pi_deleteall, S_TEXT_DELETEALL);
	pi_delete_m->vAddCommand(S_DELETE_ONE_N, S_DELETE_ONE_C, pi_delete, S_TEXT_DELETEONE);
	pi_edit_m->vAddCommand(S_CHANGE_NAME_N, S_CHANGE_NAME_C, pi_changename, S_TEXT_CHANGENAME);
	pi_edit_m->vAddCommand(S_CHANGE_VAL_N, S_CHANGE_VAL_C, pi_changeval, S_TEXT_CHANGEVAL);
	pi_edit_m->vAddCommand(S_CHANGE_LEN_N, S_CHANGE_LEN_C, pi_changelen, S_TEXT_CHANELEN);

	v_piitems.push_back(pi_create_m);
	v_piitems.push_back(pi_delete_m);
	v_piitems.push_back(pi_edit_m);
	v_piitems.push_back(pi_print_m);
}

void CMenu::vAddMenu(string sName, string sCommand, string sDisplay,CMenuItem* cParrent) {
	bool b_check = true;
	for (int i = 0; i < (int)v_piitems.size(); i++) { //checking if menu already exists
		CMenuItem *pi_temp = v_piitems.at(i);
		if (pi_temp->sGetCommand() == sCommand || pi_temp->sGetName() == sName) {
			b_check = false;
		}
	}
	if (b_check) {
		CMenuItem *pi_temp = new  CMenu(sName, sCommand,sDisplay, cParrent);
		v_piitems.push_back(pi_temp);
	}
	else {
		cout << S_ERROR << endl;
	}
}

void CMenu::vAddCommand(string sName, string sCommand, CCommand *ccpi_command,string s_text) {
	bool b_check = true;
	for (int i = 0; i < (int)v_piitems.size(); i++) { //checking if command already exists
		CMenuItem *pi_temp = v_piitems.at(i);
		if (pi_temp->sGetCommand() == sCommand || pi_temp->sGetName() == sName) {
			b_check = false;
		}
	}
	if (b_check) {
		CMenuItem *pi_temp = new  CMenuCommand(sName, sCommand, ccpi_command,s_text);
		v_piitems.push_back(pi_temp);
	}
	else {
		cout << S_ERROR << endl;
	}
}

void CMenu::vAddCMenuItem(CMenuItem &CMenuItem_item) {
	v_piitems.push_back(&CMenuItem_item);
}

void CMenu::vDeleteAll() {
	for (int i = 0; i < v_piitems.size(); i++) {
		CMenuItem* p= v_piitems.at(i);
		delete p;
	}
}

string CMenu::sGetCommand() {
	return s_command;
} 

string CMenu::sGetName() {
	return s_name;
}

void CMenu::vPrint(bool bBol) {
	if (bBol) {
		cout << S_PART;
		cout << endl << S_MENU_EXIT << endl;
		cout << endl << S_MENU_BACK << endl;
		cout << endl << S_MENU_SEARCH << endl;
		cout << endl << S_MENU_HELP << endl;
	}
	cout << S_PART << endl;
	cout << endl << s_name + S_COLON + s_command << endl;
	for (int i = 0; i < (int)v_piitems.size(); i++) {
		cout << to_string(i) + S_SPACE + v_piitems.at(i)->sGetName() + S_OPEN_BRACKET + v_piitems.at(i)->sGetCommand() + S_CLOSED_BRACKET << endl;
	}
	cout << endl << S_PART << endl;
	cout << S_ENTER_COMM;
}

string CMenu::sGetText() {
	return s_display_text;
}

void CMenu::split(const string& s_string, char c_char, vector<string>& v_vec) {
	string::size_type i = 0;
	string::size_type j = s_string.find(c_char);
	while (j != string::npos) {
		v_vec.push_back(s_string.substr(i, j - i));
		i = ++j;
		j = s_string.find(c_char, j);
		if (j == string::npos) {
			v_vec.push_back(s_string.substr(i, s_string.length()));
		}
	}
}

CMenuItem* CMenu::mGetParrent() {
	return this->parrent;
}

string CMenu::vSave(string s_acc) {
	string s_localacc;
	s_localacc = S_REC_1 + sGetName() + S_REC_2 + S_REC_3 + sGetCommand() + S_REC_4;
	for (int i = 0; i < v_piitems.size(); i++) {
		if (i == 0 || i == v_piitems.size()) {
			s_localacc += v_piitems.at(i)->vSave(s_acc);
		}
		else {
			s_localacc += S_REC_5 + v_piitems.at(i)->vSave(s_acc);
		}
	}
	return s_acc + s_localacc + S_REC_6;
}

bool  CMenu::sSearch(string sCommand,vector <string> *v_string,string s_path) { //searches  for path
	bool bol = false;
	if (sGetCommand() == sCommand) {
		v_string->push_back(s_path+sGetCommand());
		v_string->push_back(this->sGetText());
		return true;
	}
	for (int i = 0; i < v_piitems.size(); i++) {
		if (v_piitems.at(i)->sSearch(sCommand, v_string, s_path + sGetName() + S_ARROW)) {
			bol = true;
		}
	}
	return bol;
}



//fix Run
string CMenu::sRun() {
	string s_string;
	bool b_com = false ;
	vector<string> v_string;

	vPrint(true);
	getline(cin, s_string);
	
	if (s_string == S_EXIT) {
		return  S_EXIT;

	}
	else {
		b_com = false;
		while (s_string != S_BACK) {	
			bool b_f = false;
			for (int i = 0; i < (int)v_piitems.size(); i++) {
				if (s_string == v_piitems.at(i)->sGetCommand()) {      //searching for command with name entered from keyboard
					b_com = true;
					string s_string_return = v_piitems.at(i)->sRun();
					if (s_string_return == S_EXIT) {
						return  S_EXIT;
					}
					vPrint(false);
					b_f = true;
				}
			}
			b_com = b_f;
			if(!b_com) {
				split(s_string+ C_SPACE, C_SPACE, v_string);
				if (s_string != v_string.at(0)) {
					if (v_string.at(0) == S_SEARCH) { //search command
						CMenuItem* parent = this;
						b_com = true;
						while (parent->mGetParrent()!=nullptr) {
							parent = parent->mGetParrent();
						}
						vector <string> v_vec;
						vector <string>* v_pi = &v_vec;
						bool done = false;
						done =parent->sSearch(v_string.at(1),v_pi,S_EMPTY_STRING);
						if (done) {
							cout << endl << v_vec.at(0) << endl << v_vec.at(1) << endl << endl;	
						}
						v_pi->clear();
						v_pi = nullptr;
						delete v_pi;
						
					}
					if (v_string.at(0) == S_HELP) { //help command
						for (int i = 0; i < v_piitems.size(); i++) {
							if (v_piitems.at(i)->sGetCommand() == v_string.at(1)) {
								cout << v_piitems.at(i)->sGetText() << endl<<endl;
							}
						}
						b_com = true;
					}
				}
				v_string.clear();
			}
			getline(cin, s_string);
			if (s_string == S_EXIT) {
				return S_EXIT;
			}
			if (!b_com) {
				cout << S_WRONG_COMM << endl << endl;;
			}
		}
		return S_EMPTY_STRING;
	}
}