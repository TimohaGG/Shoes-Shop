#include"UI/Menu/Menu.h"

	int main() {
		srand(time(NULL));
		setlocale(0,"");
		HWND hWindowConsole = GetConsoleWindow();
		RECT r;
		GetWindowRect(hWindowConsole, &r); //stores the console's current dimensions
		MoveWindow(hWindowConsole, r.left, r.top, 900, 900, TRUE);
	
	
	Menu menu;
	
	return 0;
}