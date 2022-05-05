#include"UI/Menu/Menu.h"
//ѕринцип работы: при запуске у каждого пользовател€ генерируетс€ рандомное число игр. ¬се доступные игры и ники пользователей хран€тс€ в файлах. ѕароли по умолчанию "111".
	int main() {
		srand(time(NULL));
		setlocale(0,"");
		HWND hWindowConsole = GetConsoleWindow();
		RECT r;
		GetWindowRect(hWindowConsole, &r); //stores the console's current dimensions
		MoveWindow(hWindowConsole, r.left, r.top, 900, 500, TRUE);
	
	
	Menu menu;
	
	return 0;
}