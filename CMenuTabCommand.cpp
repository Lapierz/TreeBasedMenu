#include "pch.h"
#include "CMenuTabCommand.h"

string CMenuTabCommand::sUserInput() {
	string s_input;
	cin >> s_input;
	cout << endl;
	if (cin) {
		return s_input;
	}
	else {
		cout << S_ERROR << endl;
		return S_ERROR;
	}
}

int CMenuTabCommand::iUserInput(int iLeft, int iRight) {
	int i_input;
	cin >> i_input;
	cout << endl;
	if (cin && iLeft <= i_input && i_input <= iRight) {
		cin.ignore();
		return i_input;
	}
	else {
		cout << S_REC_9 + to_string(iLeft) + S_REC_10 + to_string(iRight) << endl;
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), C_NEWLINE);
		return iUserInput(iLeft, iRight);
	}
}