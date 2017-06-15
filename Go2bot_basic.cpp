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

using namespace std;

class Button {
public:
	void startGame();
	void chooseInstance();
	void selectFleets();
	void loadFleets();
	void enterInstance();
	void collectMail();
	void tabRename(const TCHAR* name);
	void handleGet();
	void leftClick(int* Array, string button);
	void amountOfbots();
	void resetHandles();

private:
	int mailNotification[3]{ 300, 70, 400 };
	int increaseFleet[3]{ 700, 160, 500 };
	int allConfirmed[3]{ 710, 115, 500 };
	int itemLetter[3]{ 445, 105, 100 };
	int rewardMail[3]{ 500, 240, 400 };
	int allCharge[3]{ 630, 500, 100 };
	int fleetPos1[3]{ 340, 210, 100 };
	int fleetPos2[3]{ 515, 210, 100 };
	int fleetPos3[3]{ 700, 210, 100 };
	int fleetPos4[3]{ 340, 310, 100 };
	int fleetPos5[3]{ 515, 310, 100 };
	int fleetPos6[3]{ 700, 310, 100 };
	int fleetPos7[3]{ 340, 410, 100 };
	int fleetPos8[3]{ 515, 410, 100 };
	int fleetPos9[3]{ 700, 410, 100 };
	int spaceBase[3]{ 670, 618, 300 };
	int supplyAll[3]{ 350, 115, 200 };
	int loadHe3[3]{ 580, 500, 500 };
	int instance[3]{ 785, 220, 400 };
	int tutorial[3]{ 22, 173, 500 };
	int exitMail[3]{ 813, 56, 500 };
	int cancel[3]{ 722, 540, 100 };
	int Delete[3]{ 240, 500, 500 };
	int normal[3]{ 255, 92, 300 };
	int next[3]{ 595, 553, 400 };
	int I27[3]{ 478, 461, 100 };
	int go[3]{ 705, 130, 500 };
	int ok[3]{ 765, 500, 500 };
	int delay = 1;
	int bots = 1;

	const TCHAR* botWindows[10]{ L"Go2bot 1", L"Go2bot 2", L"Go2bot 3", L"Go2bot 4", L"Go2bot 5"
		L"Go2bot 6", L"Go2bot 7", L"Go2bot 8", L"Go2bot 9", L"Go2bot 10" };

	HWND Go2bot1, Go2bot2, Go2bot3, Go2bot4, Go2bot5,
		Go2bot6, Go2bot7, Go2bot8, Go2bot9, Go2bot10;

	HWND windowHandles[10]{ Go2bot1, Go2bot2, Go2bot3, Go2bot4, Go2bot5,
		Go2bot6, Go2bot7, Go2bot8, Go2bot9, Go2bot10 };

	HWND HWnd;
	HWND hwndchild1;
	HWND hwndchild2;
	HWND hwndchild3;
};

int i;
int time;

//gets window handle ID.
void Button::handleGet() {
	HWnd = FindWindow(L"MozillaWindowClass", L"iframe - Mozilla Firefox");
	hwndchild1 = FindWindowEx(HWnd, NULL, L"MozillaWindowClass", L"");
	hwndchild2 = FindWindowEx(hwndchild1, NULL, L"GeckoPluginWindow", L"");
	hwndchild3 = FindWindowEx(hwndchild2, NULL , L"GeckoFPSandboxChildWindow", L"");
}

//sets childwindows to new names grabbed from char array.
void Button::tabRename(const TCHAR* name) {
	SetWindowText(HWnd, name);
}

//Gets the amount of bots that need to be operated and renames window handles to sperate them.
void Button::amountOfbots() {
	cout << "Enter the amount of tabs you wish to bot (no more than 10 bots are currently allowed): ";
	cin >> bots;
	cout << "Enter delay multiplier: ";
	cin >> delay;

	if (bots > 10) {
		bots = 10;
		cout << "Can't do more than 10 bots." << endl;
		Sleep(1000);
	}
	else if (delay < 0) {
		delay = 1;
		cout << "Can't have a delay of 0 or less." << endl;
		Sleep(1000);
	}

	resetHandles();
	for (int i = 0; i < bots; i++) {
		handleGet();
		windowHandles[i] = hwndchild3;
		tabRename(botWindows[i]);
		if (hwndchild3 == 0) {
			cout << "Error could not find window number: " << i + 1 << endl;
		}
		else if (hwndchild3 != 0) {
			cout << "Window handle " << i + 1 << " HEX: " << hwndchild3 << endl;
		}
	}

}

void Button::resetHandles() {
	for (int i = 0; i < bots; i++) {
		HWnd = FindWindow(L"MozillaWindowClass", botWindows[i]);
		SetWindowText(HWnd, L"iframe - Mozilla Firefox");
	}
}


//virtualized left click on a defined window handle.
void Button::leftClick(int* Array, string button) {
	for (int i = 0; i < bots; i++) {
		PostMessage(windowHandles[i], WM_LBUTTONDOWN, MK_LBUTTON, MAKELPARAM(Array[0], Array[1]));
		PostMessage(windowHandles[i], WM_LBUTTONUP, MK_LBUTTON, MAKELPARAM(Array[0], Array[1]));
		Sleep (((Array[2] * delay )/ bots) + 150);
		if (i == bots - 1) {
			cout << button << " x" << bots;
			double time = 0.00;
			time = (((Array[2] * delay )/ bots) + 150) * bots;
			time /= 1000;
			cout << "	Time taken: " << time << " Seconds" <<endl;
		}
	}
}

//Start game.
void Button::startGame() {
	leftClick(cancel, "Cancel");
	leftClick(spaceBase, "Space Base");
}

//Choose i27 (only atm).
void Button::chooseInstance() {
	leftClick(tutorial, "Tutorial");
	leftClick(instance, "Instance");
	leftClick(normal, "Normal");
	leftClick(I27, "I27 Broken Pact");
}	

//Selects 15 fleets in order.
void Button::selectFleets() {
	leftClick(increaseFleet, "Increase Fleet");
	leftClick(fleetPos1, "fleet 1");
	leftClick(fleetPos2, "fleet 2");
	leftClick(fleetPos3, "fleet 3");
	leftClick(fleetPos4, "fleet 4");
	leftClick(fleetPos5, "fleet 5");
	leftClick(fleetPos6, "fleet 6");
	leftClick(fleetPos7, "fleet 7");
	leftClick(fleetPos8, "fleet 8");
	leftClick(fleetPos9, "fleet 9");
	leftClick(next, "Next");
	leftClick(fleetPos1, "fleet 10");
	leftClick(fleetPos2, "fleet 11");
	leftClick(fleetPos3, "fleet 12");
	leftClick(fleetPos4, "fleet 13");
	leftClick(fleetPos5, "fleet 14");
	leftClick(fleetPos6, "fleet 15");
	leftClick(ok, "OK");
}

//Loads fleets with fuel.
void Button::loadFleets() {
	leftClick(increaseFleet, "Increase Fleet");
	leftClick(loadHe3, "Load He3");
	leftClick(supplyAll, "Supply All");
	leftClick(allConfirmed, "All Confirmed");
}

//Enters the Instance.
void Button::enterInstance() {
	leftClick(go, "GO");
	leftClick(spaceBase, "Space Base");
}

//collects mail.
void Button::collectMail() {
	leftClick(mailNotification, "Mail Notification");
	leftClick(itemLetter, "Item Letter");
	leftClick(rewardMail, "Reward Mail");
	leftClick(allCharge, "All Charge");
	leftClick(Delete, "Delete");
	leftClick(exitMail, "Exit Mail");
}
void delaySeconds(int milisecond) {
	Sleep(milisecond * 1000);
}

//garbage still.
int main()
{
	Button click;
	cout << "Version 2.1" << endl;
	cout << "Enter the time it takes to do i27 in Seconds for all/slowest account(s): ";
	cin >> time;

	click.amountOfbots();
	click.startGame();
	while (true) {
		click.chooseInstance();
		click.selectFleets();
		click.loadFleets();
		click.enterInstance();
		delaySeconds(time);
		click.collectMail();
		i++;
		cout << "I27 Runs: " << i << endl;
		delaySeconds(1);
	}
}

