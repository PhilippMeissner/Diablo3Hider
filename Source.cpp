#include <Windows.h>
#include <iostream>
using namespace std;


int main () {
	HWND hwnd = FindWindow( NULL, "Diablo III");

	cout << "\t\t\tDiablo 3 - Hider by Tracky\n\n\n";
	cout << "Numpad 8 -> Hide Diablo 3\n";
	cout << "Numpad 9 -> Show Diablo 3\n";
	cout << "Numpad 0 -> Close program\n";

	while (hwnd) {

		if (GetAsyncKeyState(VK_NUMPAD8) & 0x8000) {
			ShowWindow(hwnd, SW_HIDE);
			cout << "WindowState = Hidden\n";
			Sleep(500);
		}

		if (GetAsyncKeyState(VK_NUMPAD9) & 0x8000) {
			ShowWindow(hwnd, SW_SHOW);
			cout << "WindowState = Visible\n";
			Sleep(500);
		}

		if (GetAsyncKeyState(VK_NUMPAD0) & 0x8000) {
			ShowWindow(hwnd, SW_SHOW);
			break;
		}
	}
	return 0;
}