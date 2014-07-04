#include <Windows.h>
#include <iostream>
using namespace std;


int main() {
	HWND hwnd = FindWindow("D3 Main Window Class", "Diablo III");
	bool bWindowVisibility = IsWindowVisible(hwnd);


	cout << "\t\t\tDiablo 3 - Hider v.1.2 by Tracky\n\n\n";
	cout << "Numpad 8 -> Hide Diablo 3\n";
	cout << "Numpad 9 -> Show Diablo 3\n";
	cout << "Numpad 0 -> Close program\n\n\n";

	if (hwnd && IsWindowVisible(hwnd)) {
		cout << "WindowState = Visible\t\r";
	}
	else if (hwnd && !IsWindowVisible(hwnd)) {
		cout << "WindowState = Hidden\t\r";
	}

	while (hwnd) {


		if (bWindowVisibility && (GetAsyncKeyState(VK_NUMPAD8) & 0x8000)) {
			ShowWindow(hwnd, SW_HIDE);
			cout.flush();
			cout << "WindowState = Hidden\t\r";
			cout.flush();
			bWindowVisibility = FALSE;
		}


		if (!bWindowVisibility && (GetAsyncKeyState(VK_NUMPAD9) & 0x8000)) {
			ShowWindow(hwnd, SW_SHOW);
			SetForegroundWindow(hwnd);
			cout.flush();
			cout << "WindowState = Visible\t\r";
			bWindowVisibility = TRUE;
		}


		if (GetAsyncKeyState(VK_NUMPAD0) & 0x8000) {
			ShowWindow(hwnd, SW_SHOW);
			break;
		}
	}
	return 0;
}