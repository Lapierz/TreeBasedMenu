
#include "pch.h"
#include "CDeleteTab.h"

CDeleteTab::CDeleteTab(vector <CTable*> *v_vector) {
	this->v_vector = v_vector;
}

CDeleteTab::~CDeleteTab() {
	delete v_vector;
}

void CDeleteTab::vRunCommand() {
	if (v_vector->empty()) {
		cout << S_EMPTY_TAB << endl;
	}
	else {
		cout << S_WHAT_TAB_INPUT << endl;
		int i_input = iUserInput(0, v_vector->size() - 1);
		CTable *pict_temp = v_vector->at(i_input);
		delete pict_temp;
		v_vector->erase(v_vector->begin() + (i_input));
		cout << S_DEL_SUCC << endl;
	}
}