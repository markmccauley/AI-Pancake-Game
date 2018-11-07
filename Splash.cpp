#include "Splash.h"
#include <string>
#include <unistd.h>
using namespace std;

void Splash::show_splash() {
    int key_input;

    //Initialize ncurses
    initscr(); 
    cbreak(); //makes sure ctrl + c lets you exit the program
    noecho(); // doesn't show what the user types on the screen

    //Initialize colors
    start_color();
    init_pair(1, COLOR_CYAN, COLOR_BLACK);

	keypad(stdscr, TRUE); // makes it so we can use keypad
	
    blinking_button();
    print_title();
    print_team();
    print_animation();

    while(isPressed()) {
        key_input = getch();
        if (key_input == 10) {
            enter = false;
        }
    }
}

void Splash::print_title() {
     /*adds a character on the window at the current 
     cursor position, and the cursor position is advanced then*/
    curs_set(0);
    start_color();
    init_pair(1, COLOR_CYAN, COLOR_BLACK);

    attron(COLOR_PAIR(1));
    mvprintw(2,18, " _____                 _          _____ _ _     ");
    mvprintw(3,18, "|  _  |___ ___ ___ ___| |_ ___   |   __| |_|___ ");
    mvprintw(4,18, "|   __| .'|   |  _| .'| '_| -_|  |   __| | | . |");
    mvprintw(5,18, "|__|  |__,|_|_|___|__,|_,_|___|  |__|  |_|_|  _|");
    mvprintw(6,18, "                                           |_|  ");
       
    attroff(COLOR_PAIR(1));
}

void Splash::blinking_button() {
    curs_set(0);
    attron(A_BLINK);
    mvprintw(32, 27, " -----------------------");
	mvprintw(33, 27, "| Press Enter to Begin. |");
    mvprintw(34, 27, " -----------------------");
	attroff(A_BLINK);
}

void Splash::print_team() {
    curs_set(0);
    start_color();
    init_pair(1, COLOR_CYAN, COLOR_BLACK);

    attron(COLOR_PAIR(1));
    mvprintw(38,1, "By: DustyLeopards (Team 33)");
    mvprintw(39,1,"Mark, Siman, Joseph, Lasse, Eddie");
    attroff(COLOR_PAIR(1));
}

void Splash::print_animation(){
    curs_set(0);
    start_color();
    init_pair(2, COLOR_YELLOW, COLOR_BLACK);

    attron(COLOR_PAIR(2));
    mvprintw(10,33, "+-----------+");
    mvprintw(11,33, "|     6     |");
    mvprintw(12,33, "+-----------+");
    mvprintw(13,33, "  +-------+");
    mvprintw(14,33, "  |   4   |");
    mvprintw(15,33, "  +-------+");
    mvprintw(16,33, " +---------+");
    mvprintw(17,33, " |    5    |");
    mvprintw(18,33, " +---------+");
    mvprintw(19,33, "    +---+");
    mvprintw(20,33, "    | 2 |");
    mvprintw(21,33, "    +---+");
    mvprintw(22,33, "   +-----+");
    mvprintw(23,33, "   |  3  |");
    mvprintw(24,33, "   +-----+");
    mvprintw(25,33, "     +-+");
    mvprintw(26,33, "     |1|");
    mvprintw(27,33, "     +-+");
    
    // //Highlight selected pancake
    // attron(A_BOLD);
    // attron(A_BLINK);
    // mvprintw(16,49, " +---------+");
    // mvprintw(17,49, " |    5    |");
    // mvprintw(18,49, " +---------+");
    // attroff(A_BOLD);
    // attroff(A_BOLD);
    // refresh();

    attroff(COLOR_PAIR(2));
}