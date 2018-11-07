#include "Splash.h"
#include "Selector.h"

int main(void) {
	//GameData data;
    Splash splash_screen;
    Selector difficulty_selector;

    splash_screen.show_splash();
    difficulty_selector.show_selector();
	//endwin(); //deallocates memory and ends ncurses
	return 0;
}