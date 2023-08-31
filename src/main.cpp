#include<windows.h>
#include<conio.h>
#include<vector>
#include "optionslist.hpp"
#include "custom_io.hpp"
bool clicking;
int x;
int y;

static void startclicker()
{
	while (true) {
		if (GetAsyncKeyState(VK_NUMPAD1)) {
			Sleep(100);
			POINT cursorPos;
			GetCursorPos(&cursorPos);
			x = cursorPos.x;
			y = cursorPos.y;
			printf("[Mouse Position X]: %d\n", x);
			printf("[Mouse Position Y]: %d\n", y);
		}
		
		if (GetAsyncKeyState(VK_ESCAPE)) {
			printOut("Bye Bye~ <3");
			Sleep(150);
			exit(0);
		}
		
		if (GetAsyncKeyState(VK_NUMPAD2)) {
			printOut("! Clicking !");
			Sleep(100);
			clicking = true;
			while (true) {
				if (!clicking) {
					break;
				}

				SetCursorPos(x, y);
				mouse_event(MOUSEEVENTF_LEFTDOWN, x, y, 0, 0);
				mouse_event(MOUSEEVENTF_LEFTUP, x, y, 0, 0);

				if (GetAsyncKeyState(VK_NUMPAD3)) {
					clicking = false;
					printOut("Stopping the clicker...");
				}

				if (GetAsyncKeyState(VK_ESCAPE)) {
					printOut("Bye Bye~ <3");
					Sleep(100);
					exit(0);
				}
			}
		}
	}
}

static void init()
{
	clicking = false;
	system("TITLE C++ Auto Clicker by Equinoxtic");
	printOut("C++ Auto-Clicker by Equinoxtic", "\n\n", "\n");
	printOut("====================================================================", "\n\n");
	printOut("[ HOTKEYS ]", "\n\n");
	/* printOut("NumPad1 = save mouse position");
	printOut("NumPad2 = activate autoclicker on saved position");
	printOut("NumPad3 = STOP");
	printOut("Escape  = Close", "\n\n"); */
	OPTIONS_LIST options_ls = {
		{ "NumPad1", "Save Mouse position." },
		{ "NumPad2", "Activate Auto-clicker on saved position." },
		{ "NumPad3", "Stop Auto-clicker operation." },
		{ "Escape", "Close / Exit." }
	};
	createListFromStrings(options_ls);
	printOut("====================================================================", "\n\n", "\n");
	printOut("[ LOG ]", "\n\n");
	
	// startclicker();
}

int main(void)
{
	init();
	_getch();
	return EXIT_SUCCESS;
}
