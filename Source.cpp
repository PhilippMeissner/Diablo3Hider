#include <Windows.h>
#include <iostream>
using namespace std;


int main () {
	HWND hwnd = FindWindow("D3 Main Window Class", "Diablo III");
	bool bWindowVisibility = IsWindowVisible(hwnd);

	cout << "\t\t\tDiablo 3 - Hider by v.1.1 Tracky\n\n\n";
	cout << "Numpad 8 -> Hide Diablo 3\n";
	cout << "Numpad 9 -> Show Diablo 3\n";
	cout << "Numpad 0 -> Close program\n";

	while (hwnd) {

		if (bWindowVisibility && (GetAsyncKeyState(VK_NUMPAD8) & 0x8000)) {
			ShowWindow(hwnd, SW_HIDE);
			cout << "WindowState = Hidden\n";
			bWindowVisibility = FALSE;
			Sleep(100);
		}

		if (!bWindowVisibility && (GetAsyncKeyState(VK_NUMPAD9) & 0x8000)) {
			ShowWindow(hwnd, SW_SHOW);
			cout << "WindowState = Visible\n";
			bWindowVisibility = TRUE;
			Sleep(100);
		}

		if (GetAsyncKeyState(VK_NUMPAD0) & 0x8000) {
			ShowWindow(hwnd, SW_SHOW);
			break;
		}
	}
	return 0;
}