#include"pch.h"
#include"CChangeVal.h"

CChangeVal::CChangeVal(vector <CTable*> *v_vector) {
	this->v_vector = v_vector;
}

CChangeVal::~CChangeVal() {
	delete v_vector;
}

void CChangeVal::vRunCommand() {
	if (v_vector->empty()) {
		cout << S_EMPTY_TAB << endl;
		return;
	}
	else {
		cout << S_WHAT_TAB_INPUT << endl;
		int i_input = iUserInput(0, v_vector->size() - 1);
		cout << S_WHAT_VAL << endl;
		int i_input_val = iUserInput(INT_MIN, INT_MAX);
		cout << S_WHAT_CELL << endl;
		int i_tab_size = v_vector->at(i_input)->iReadSize();
		bool b_finish = true;
		while (b_finish) {
			int  i_input_cell = iUserInput(-1, i_tab_size - 1);
			if (i_input_cell == -1) {
				cout << S_RANGE + to_string(i_tab_size - 1) << endl;
			}
			else {
				v_vector->at(i_input)->vSetValue(i_input_cell, i_input_val);
				b_finish = false;
			}
		}
	}
}
