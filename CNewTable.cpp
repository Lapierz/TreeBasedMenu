#include "pch.h"
#include "CNewTable.h"

CNewTable::CNewTable(vector <CTable*> *v_vector) {
	this->v_vector = v_vector;
}

CNewTable::~CNewTable() {
	delete v_vector;
}

void CNewTable::vRunCommand() {
	cout << S_DEF_TAB << endl;
	cout << S_CUSTOM_TAB << endl;
	cout << S_DEF_TAB_MUL << endl << endl;
	int i_input = iUserInput(1, 3);
	if (i_input == 1) {
		CTable *pict_tab = new CTable();
		v_vector->push_back(pict_tab);
	} 
	else if (i_input == 2) {
		cout << S_WHAT_NAME << endl;
		string s_name = sUserInput();
		cout << S_ENTER_LEN_INPUT << endl;
		int s_lenght = iUserInput(1, INT_MAX);
		CTable *pict_tab = new CTable(s_name, s_lenght);
		v_vector->push_back(pict_tab);
	}
	else if (i_input == 3) {
		cout << S_HOW_MANY << endl;
		int i_number = iUserInput(1, INT_MAX);
		for (int i = 0; i < i_number; i++) {
			CTable *pict_tab = new CTable();
			v_vector->push_back(pict_tab);
		}
	}
	else {
		cout << S_ERROR << endl;
	}
}