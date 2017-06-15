#include "stdafx.h"
#include <stdio.h>
#include "stdafx.h"
#include <windows.h>
#include <winuser.h>
#include <iostream>
#include <conio.h>
#include <tchar.h>
#include <cstdlib>
#include <wingdi.h>
#include <string>
#include <vector>
#include <atlstr.h> 
using namespace std;

class Button {
public:
	void handleGet();
	void leftClick(int* Array, HWND handle);
	void keyPress(HWND handle, char letter, int delay);
	void amountOfbots();
	void tabRename(const TCHAR* name);
	void postConstuct();

private:
	int chat[3]{ 250, 655, 100 };
	int chatEnter[3]{ 320, 655, 100 };
	int botRotation = 0;
	int bots = 0;
	HWND HWnd, hwndchild1, hwndchild2, hwndchild3;
	const TCHAR* botWindows[10]{ L"Go2bot 1", L"Go2bot 2", L"Go2bot 3", L"Go2bot 4", L"Go2bot 5",
		L"Go2bot 6", L"Go2bot 7", L"Go2bot 8", L"Go2bot 9", L"Go2bot 10" };
	HWND Go2bot1, Go2bot2, Go2bot3, Go2bot4, Go2bot5, Go2bot6, Go2bot7, Go2bot8, Go2bot9, Go2bot10;
	HWND windowHandles[10]{ Go2bot1, Go2bot2, Go2bot3, Go2bot4, Go2bot5, Go2bot6, Go2bot7, Go2bot8, Go2bot9, Go2bot10 };
	vector<string> lyrics;
	string song = " ";
	int begin, end = 0;
};


void Button::handleGet() {
	HWnd = FindWindow(NULL, L"Play Galaxy Online, a free online game on Kongregate - Mozilla Firefox");
	hwndchild1 = FindWindowEx(HWnd, NULL, L"MozillaWindowClass", L"");
	hwndchild2 = FindWindowEx(hwndchild1, NULL, L"GeckoPluginWindow", L"");
	hwndchild3 = FindWindowEx(hwndchild2, NULL, L"GeckoFPSandboxChildWindow", L"");
}


void Button::leftClick(int* Array, HWND handle) {
	SendMessage(handle, WM_LBUTTONDOWN, MK_LBUTTON, MAKELPARAM(Array[0], Array[1]));
	SendMessage(handle, WM_LBUTTONUP, MK_LBUTTON, MAKELPARAM(Array[0], Array[1]));
	Sleep(Array[2]);
}


void Button::tabRename(const TCHAR* name) {
	SetWindowText(hwndchild1, name);
	SetWindowText(hwndchild2, name);
	SetWindowText(hwndchild3, name);
}


void Button::amountOfbots() {
	cout << "Enter the amount of tabs you wish to bot (no more than 10 bots are currently allowed): ";
	cin >> bots;
	for (int i = 0; i < bots; i++) {
		handleGet();
		windowHandles[i] = hwndchild3;
		tabRename(botWindows[i]);
	}
}

void Button::keyPress(HWND handle, char letter, int delay) {
	SendMessage(handle, WM_CHAR, (WPARAM)letter, NULL);
	Sleep(delay);
}

void Button::postConstuct() {
	HWND handle;
	string input = " ";
	cout << "enter song: " << endl;

	while (getline(cin, input)){
		lyrics.push_back(input);
		cout << song.length() << "rotation" << endl;

		if (input == "#") {
			break;
		}
	}
	Sleep(5000);
	for (int i = 0; i < lyrics.size() - 1; i++) {
		string line = lyrics[i];
		if (botRotation == 10) {
			botRotation = 0;
		}
		handle = windowHandles[botRotation];
		botRotation++;
		leftClick(chat, handle);
		cout << " clicked: chat" << endl;
		for (int j = 0; j < line.length(); j++) {
			keyPress(handle, line[j], 0);
			cout << line[j];
		}
		cout << endl;
		leftClick(chatEnter, handle);
		cout << " clicked: chatEnter" << endl;
		Sleep(1000);
	}
	Sleep(5000);
}

int main()
{
	Button click;
	int value = 0;
	click.amountOfbots();

	while (true) {
		click.postConstuct();
	}
}
