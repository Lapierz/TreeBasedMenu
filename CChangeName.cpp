#include "pch.h"
#include "CChangeName.h"

CChangeName::CChangeName(vector <CTable*> *v_vector) {
	this->v_vector = v_vector;
}

CChangeName::~CChangeName() {
	delete v_vector;
}

void CChangeName::vRunCommand() {
	if (v_vector->empty()) {
		cout << S_EMPTY_TAB << endl;
		return;
	}
	else {
		cout << S_WHAT_TAB_INPUT << endl;
		int i_input = iUserInput(0, v_vector->size() - 1);
		cout << S_WHAT_NAME << endl;
		string s_input = sUserInput();
		v_vector->at(i_input)->vSetName(s_input);
	}
}