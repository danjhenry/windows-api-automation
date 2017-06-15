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
#include <atlstr.h>
#include <vector>
using namespace std;

class Button {
public:
	void handleGet();
	void leftClick(int* Array, HWND* handle, string action);
	void amountOfbots();
	void tabRename(const TCHAR* name);
	void runLucky();
	void buildSomething(int* buildtab, int* building, int* buildingPlacement, string buildName);
	void upgrade(int* building, int* upgradeLocation);
	void intstantUpgrade(int* building, int* upgradeLocation, string upgradeName);
	void spinLuck();
	void Constructor();
	void Destructor();
	void handleGet2(const TCHAR* window);
	void keyPress(HWND* handle, char letter, int delay);
	void resetWindows();
	void resetHandles();

private:
	int accountOk[3]{ 500, 332, 20000 };
	int accountOkfast[3]{ 500, 332, 1000 };
	int cancel[3]{ 722, 540, 2000 };
	int SelectAll[3]{ 237, 498, 700 };
	int Delete[3]{ 350, 498, 700 };
	int mailNotification[3]{ 300, 70, 700 };
	int exitMail[3]{ 813, 58, 1500 };
	int speedupBuild[3]{ 970, 440, 700 };
	int instaBuild[3]{ 613, 323, 700 };
	int luckWheelTab[3]{ 948, 641, 700 };
	int spaceBase[3]{ 670, 620, 1000 };
	int luckyWheelButton[3]{ 947, 545, 1500 };
	int spin[3]{ 500, 400, 1000 };
	int luckyWheelOk[3]{ 503, 422, 500 };
	int vouchers[3]{ 545, 417, 500 };
	int buyandSpin[3]{ 436, 445, 1000 };
	int End[3]{ 610, 586, 700 };
	int Galaxy[3]{ 635, 631, 1500 };
	int ursaMajor[3]{ 95, 76, 1500 };
	int abandonPlanet[3]{ 290, 29, 1500 };
	int abandonOk[3]{ 398, 635, 1000 };
	int abandonOk2[3]{ 440, 347, 1000 };
	int abandonOk3[3]{ 563, 350, 1000 };
	int deleteOk[3]{ 440, 346, 1000 };
	int warehouse_harvest[3]{ 580, 220, 1000 };
	int warehouse_Place[3]{ 486, 218, 700 };
	int questComplete[3]{ 200, 511, 1200 };
	int claimQuest[3]{ 757, 330, 700 };
	int questExit[3]{ 776, 111, 1500 };
	int skip[3]{ 573, 447, 1000 };
	int rejectFriend[3]{ 611, 248, 1000 };
	int socialTab[3]{ 852, 634, 1000 };
	int AH[3]{ 850, 568, 1000 };
	int Sell[3]{ 505, 121, 1000 };
	int Card[3]{ 243, 284, 1000 };
	int sellfirstCard[3]{ 381, 220, 1000 };
	int Totalprice[3]{ 742, 298, 1000 };
	int sellItem[3]{ 743, 491, 1000 };
	int AHexit[3]{ 814, 55, 1000 };
	int Rejoin[3]{ 500, 327, 1000 };

	//build
	int build[3]{ 760, 636, 700 };
	int constructBuilding[3]{ 760, 600, 700 };
	int military[3]{ 600, 158, 700 };
	int tradingCenter_build[3]{ 350, 391, 700 };
	int weaponResearch_build[3]{ 678, 280, 700 };
	int cityServices[3]{ 437, 158, 700 };
	int weaponCenter_Place[3]{ 606, 133, 700 };
	int tradeCenter_Place[3]{ 147, 400, 700 };
	int civicCenter_Upgrade[3]{ 743, 250, 700 };
	int civicCenter_Place[3]{ 768, 263, 700 };
	int technologyCenter_Place[3]{ 420, 70, 700 };
	int technologyCenter_build[3]{ 686, 273, 700 };
	int commandCenter_build[3]{ 350, 274, 700 };
	int commandCenter_Place[3]{ 262, 153, 700 };
	int commandCenter_Enter[3]{ 319, 130, 1000 };
	int drawCommander[3]{ 220, 488, 700 };
	int dissmissCommanders[3]{ 455, 482, 700 };
	int dissmissOk[3]{ 560, 350, 700 };
	int commandCenterExit[3]{ 824, 94, 700 };

	double totalTimesec = 0.000;
	double totalTimemin = 0.000;
	double totalTimehour = 0.000;
	vector<int> numbers;

	double timeTaken = 0.000;
	int sleepTime = 200;
	int eval = 0;
	bool keepGoing = true;
	string checker = " ";
	int botRotation = 0;
	int bots = 1;

	HWND HWnd, hwndchild1, hwndchild2, hwndchild3, window;

	const TCHAR* botWindows[30]{ L"Go2bot 1", L"Go2bot 2", L"Go2bot 3", L"Go2bot 4", L"Go2bot 5",
		L"Go2bot 6", L"Go2bot 7", L"Go2bot 8", L"Go2bot 9", L"Go2bot 10", L"Go2bot 11", L"Go2bot 12",
		L"Go2bot 13", L"Go2bot 14", L"Go2bot 15" , L"Go2bot16", L"Go2bot17", L"Go2bot18", L"Go2bot19",
		L"Go2bot20", L"Go2bot21", L"Go2bot22", L"Go2bot23", L"Go2bot24", L"Go2bot25",
		L"Go2bot26", L"Go2bot27", L"Go2bot28", L"Go2bot29", L"Go2bot30" };

	HWND Go2bot1, Go2bot2, Go2bot3, Go2bot4, Go2bot5,
		Go2bot6, Go2bot7, Go2bot8, Go2bot9, Go2bot10,
		Go2bot11, Go2bot12, Go2bot13, Go2bot14, Go2bot15,
		Go2bot16, Go2bot17, Go2bot18, Go2bot19, Go2bot20,
		Go2bot21, Go2bot22, Go2bot23, Go2bot24, Go2bot25,
		Go2bot26, Go2bot27, Go2bot28, Go2bot29, Go2bot30;

	HWND firefox1, firefox2, firefox3, firefox4, firefox5, firefox6, firefox7, firefox8, firefox9,
		firefox10, firefox11, firefox12, firefox13, firefox14, firefox15, firefox16, firefox17, firefox18,
		firefox19, firefox20, firefox21, firefox22, firefox23, firefox24, firefox25, firefox26, firefox27,
		firefox28, firefox29, firefox30;

	HWND firfoxHWND[30]{ firefox1, firefox2, firefox3, firefox4, firefox5, firefox6, firefox7, firefox8, firefox9,
		firefox10, firefox11, firefox12, firefox13, firefox14, firefox15, firefox16, firefox17, firefox18,
		firefox19, firefox20, firefox21, firefox22, firefox23, firefox24, firefox25, firefox26, firefox27,
		firefox28, firefox29, firefox30 };

	HWND windowHandles[30]{ Go2bot1, Go2bot2, Go2bot3, Go2bot4, Go2bot5,
		Go2bot6, Go2bot7, Go2bot8, Go2bot9, Go2bot10, Go2bot11, Go2bot12,
		Go2bot13, Go2bot14, Go2bot15, Go2bot16, Go2bot17, Go2bot18, Go2bot19,
		Go2bot20, Go2bot21, Go2bot22, Go2bot23, Go2bot24, Go2bot25,
		Go2bot26, Go2bot27, Go2bot28, Go2bot29, Go2bot30 };
};

//gets window handle ID.
void Button::handleGet() {
	HWnd = FindWindow(L"MozillaWindowClass", L"iframe - Mozilla Firefox");
	hwndchild1 = FindWindowEx(HWnd, NULL, L"MozillaWindowClass", L"");
	hwndchild2 = FindWindowEx(hwndchild1, NULL, L"GeckoPluginWindow", L"");
	hwndchild3 = FindWindowEx(hwndchild2, NULL, L"GeckoFPSandboxChildWindow", L"");
}



void Button::handleGet2(const TCHAR* window) {
	for (int i = 0; i < bots; i++) {
		HWnd = FindWindow(L"MozillaWindowClass", window);
		hwndchild1 = FindWindowEx(HWnd, NULL, L"MozillaWindowClass", L"");
		hwndchild2 = FindWindowEx(hwndchild1, NULL, L"GeckoPluginWindow", L"");
		hwndchild3 = FindWindowEx(hwndchild2, NULL, L"GeckoFPSandboxChildWindow", L"");
	}
}

//virtual mouse leftclick.
void Button::leftClick(int* Array, HWND* handle, string action) {
		for (int i = 0; i < bots; i++) {
			PostMessage(handle[i], WM_LBUTTONDOWN, MK_LBUTTON, MAKELPARAM(Array[0], Array[1]));
			PostMessage(handle[i], WM_LBUTTONUP, MK_LBUTTON, MAKELPARAM(Array[0], Array[1]));
			if (i == bots - 1) {
				cout << "clicked: " << action << " x" << bots;
				timeTaken = (Array[2] + (sleepTime * bots));
				timeTaken = timeTaken / 1000;
				cout << "                    Time duration: " << timeTaken << " Seconds" << endl;
				totalTimesec += timeTaken;
				if (totalTimesec > 60) {
					totalTimesec -= 60;
					totalTimemin++;
				}
				if (totalTimemin > 60) {
					totalTimemin -= 60;
					totalTimehour++;
				}
			}
			Sleep(Array[2] / bots);
			Sleep(sleepTime);
		}
	}

//virtual keyboard input.
void Button::keyPress(HWND* handle, char letter, int delay) {
	for (int i = 0; i < bots; i++) {
		SendMessage(handle[i], WM_CHAR, (WPARAM)letter, NULL);
		Sleep(delay / bots);
		Sleep(sleepTime);
	}
}

//sets childwindows to new names grabbed from char array.
void Button::tabRename(const TCHAR* name) {
	SetWindowText(HWnd, name);
}

//Gets the amount of bots that need to be operated and renames window handles to sperate them.
void Button::amountOfbots() {
	if (eval == 0) {
		for (int i = 0; i < bots; i++) {
			handleGet();
			firfoxHWND[i] = HWnd;
			windowHandles[i] = hwndchild3;
			tabRename(botWindows[i]);
			cout << " window handle: " << windowHandles[i] << " window number: " << i + 1 << endl;
		}
		eval++;
	}
	else {
		for (int i = 0; i < bots; i++) {
			handleGet2(botWindows[i]);
			windowHandles[i] = hwndchild3;
			tabRename(botWindows[i]);
		}
	}
}

void Button::resetHandles() {
	for (int i = 0; i < bots; i++) {
		HWnd = FindWindow(L"MozillaWindowClass", botWindows[i]);
		SetWindowText(HWnd, L"iframe - Mozilla Firefox");
	}
}

void Button::resetWindows() {
	cout << "Enter the amount of tabs you wish to bot (no more than 25 bots are currently allowed): ";
	cin >> bots;
	resetHandles();
	cout << "Enter sleep time avg. 200 - 300 ms: ";
	cin >> sleepTime;
	amountOfbots();
	leftClick(Rejoin, windowHandles, "rejoin");
	Sleep(1000);
	eval = 0;
	resetHandles();
	Sleep(1000);
	amountOfbots();
	cout << "Enter the amount of tabs you wish to bot (no more than 25 bots are currently allowed): ";
	cin >> bots;
	leftClick(cancel, windowHandles, "Cancel");
	leftClick(mailNotification, windowHandles, "Mail Notification");
	leftClick(SelectAll, windowHandles, "Select All");
	leftClick(Delete, windowHandles, "Delete");
	leftClick(deleteOk, windowHandles, "OK");
	leftClick(exitMail, windowHandles, "Exit Mail");
	leftClick(Galaxy, windowHandles, "Galaxy");
	leftClick(ursaMajor, windowHandles, "Ursa Major");
	leftClick(abandonPlanet, windowHandles, "Abandon Planet");
	leftClick(abandonOk, windowHandles, "OK");
	leftClick(abandonOk2, windowHandles, "OK");
	Sleep(1000 * bots);
	cout << "SLeep time: " << 1000 * bots << endl;
}

void Button::buildSomething(int* buildtab, int* building, int* buildingPlacement, string buildName) {
	leftClick(build, windowHandles, "build");
	leftClick(constructBuilding, windowHandles, "construct building");
	leftClick(buildtab, windowHandles, "build tab");
	Sleep(500);
	leftClick(building, windowHandles, "building");
	Sleep(1000);
	leftClick(buildingPlacement, windowHandles, "build placement");
	cout << buildName << "Constructed" << endl;
	Sleep(500);
}

void Button::intstantUpgrade(int* building, int* upgradeLocation, string upgradeName) {
	leftClick(building, windowHandles, "building");
	leftClick(upgradeLocation, windowHandles, "upgrade");
	leftClick(speedupBuild, windowHandles, "speed build");
	Sleep(300);
	leftClick(instaBuild, windowHandles, "insta build");
	cout << upgradeName << "Upgraded" << endl;
	Sleep(1500);
}

void Button::upgrade(int* building, int* upgradeLocation) {
	leftClick(building, windowHandles, "building");
	leftClick(upgradeLocation, windowHandles, "upgrade");
}

void Button::spinLuck() {
	leftClick(spin, windowHandles, "Spin");
	leftClick(buyandSpin, windowHandles, "buy&spin");
	leftClick(rejectFriend, windowHandles, "rejectFriend");
	Sleep(9000);
	leftClick(luckyWheelOk, windowHandles, "OK");
}

void Button::Constructor() {
	amountOfbots();
	leftClick(accountOk, windowHandles, "OK");
	Sleep(5000);
	leftClick(accountOkfast, windowHandles, "OK");
	Sleep(5000);
	leftClick(cancel, windowHandles, "Cancel");
	leftClick(mailNotification, windowHandles, "Mail Notification");
	leftClick(SelectAll, windowHandles, "Select All");
	leftClick(Delete, windowHandles, "Delete");
	leftClick(deleteOk, windowHandles, "OK");
	leftClick(exitMail, windowHandles, "Exit Mail");
	leftClick(warehouse_Place, windowHandles, "warehouse");
	leftClick(warehouse_harvest, windowHandles, "warehouse_harvest");
	leftClick(questComplete, windowHandles, "quest");
	leftClick(claimQuest, windowHandles, "quest claim");
	leftClick(questExit, windowHandles, "quest exit");
	intstantUpgrade(civicCenter_Place, civicCenter_Upgrade, "Civic Center");
	buildSomething(cityServices, technologyCenter_build, technologyCenter_Place, "Technology Center");
	leftClick(speedupBuild, windowHandles, "speed build");
	leftClick(instaBuild, windowHandles, "instabuild");
	buildSomething(military, weaponResearch_build, weaponCenter_Place, "Weapon Research Center");
	leftClick(speedupBuild, windowHandles, "speed build");
	leftClick(instaBuild, windowHandles, "instabuild");
	buildSomething(cityServices, tradingCenter_build, tradeCenter_Place, "Tradeing Center");
	leftClick(speedupBuild, windowHandles, "speed build");
	leftClick(instaBuild, windowHandles, "instabuild");
	buildSomething(military, commandCenter_build, commandCenter_Place, "commandCenter");
	leftClick(speedupBuild, windowHandles, "speed build");
	leftClick(instaBuild, windowHandles, "instabuild");
	leftClick(commandCenter_Place, windowHandles, "commandCenter");
	leftClick(commandCenter_Enter, windowHandles, "Enter");
	leftClick(drawCommander, windowHandles, "Draw Commander");
	leftClick(commandCenterExit, windowHandles, "Exit");
	leftClick(spaceBase, windowHandles, "Space Base");
	leftClick(luckWheelTab, windowHandles, "lucky wheel / Mall");
	leftClick(luckyWheelButton, windowHandles, "Lucky Wheel");
	leftClick(spin, windowHandles, "spin");
	Sleep(10000);
	leftClick(rejectFriend, windowHandles, "rejectFriend");
	leftClick(luckyWheelOk, windowHandles, "Ok");
	leftClick(spin, windowHandles, "spin");
	leftClick(vouchers, windowHandles, "vouchers");
	leftClick(skip, windowHandles, "skip");
	Sleep(1000);
}

void Button::Destructor() {
	leftClick(rejectFriend, windowHandles, "rejectFriend");
	leftClick(Rejoin, windowHandles, "rejoin");
	leftClick(End, windowHandles, "End");
	leftClick(Galaxy, windowHandles, "Galaxy");
	leftClick(ursaMajor, windowHandles, "Ursa Major");
	leftClick(abandonPlanet, windowHandles, "Abandon Planet");
	leftClick(abandonOk, windowHandles, "OK");
	leftClick(abandonOk2, windowHandles, "OK");
	Sleep(1500 * bots);
	cout << "SLeep time: " << 1500 * bots << endl;
}

void Button::runLucky() {
	cout << "Enter the amount of tabs you wish to bot (no more than 25 bots are currently allowed): ";
	cin >> bots;
	cout << "Enter sleep time avg. 200 - 300 ms: ";
	cin >> sleepTime;
	resetHandles();
	while (keepGoing) {
		Constructor();
		for (int i = 0; i < 12; i++) {
			spinLuck();
			cout << "Spin number: " << i + 1 << endl;
		}
		cout << "Total Time Spent: " << "Hours: " << totalTimehour << " / " << "Minuites: " << totalTimemin << " / " << "Seconds: " << totalTimesec << endl;
		/*
		int accountsVouchers;
		cout << "Enter how many accounts got vouchers: ";
		cin >> accountsVouchers;
		if (accountsVouchers > 0) {
			int accNumber;
			for (int i = 0; i < accountsVouchers; i++) {
				cout << "Account Number: ";
				cin >> accNumber;
				numbers.push_back(accNumber);
			}
			for (int i = 0; i < 60; i++) {
				spinLuck();
			}
		}
		*/
		cout << "Collect your shit" << endl;
		cout << "Enter 'continue' to keep going or 'stop' to stop: ";
		cin >> checker;
		if (checker == "continue" || checker == "Continue") {
			keepGoing = true;
		}
		else if (checker == "stop" || checker == "Stop") {
			keepGoing = false;
		}
		Destructor();
	}
}

int main()
{
	Button click;
	string reset = " ";
	cout << "Do you wish to reset? yes or no" << endl;
	cin >> reset;
	if (reset == "yes") {
		click.resetWindows();
	}
	click.runLucky();
}




