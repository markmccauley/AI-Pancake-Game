#include "Selector.h"
#include "ScoreBoard.h"
#include <iostream>
#include <cstring>
#include <tuple>


WINDOW* Selector::create_win() {
    // get screen size
    int yMax, xMax;
    getmaxyx(stdscr, yMax, xMax);

    // create a window for input
    WINDOW *input_win = newwin(3, xMax - 46, yMax - 10, 22);
    box(input_win, 8, 0);
    refresh();
    wrefresh(input_win);

    return input_win;
}

void Selector::show_selector() {
    // erase previous screen
    erase();

    // print instructions
    mvprintw(10, 22, "How many pancakes would you like?.");
    mvprintw(11, 26, "Please enter a number 2-9");
    WINDOW *input_n_win = create_win();

    canEnter = false;

    while (1) {

        // get user input for num of pancakes
        key_input = wgetch(input_n_win);

        if (key_input > 49 && key_input < 58) {

            // store n
            n = key_input - 48;
            choice = n;

            // concatenate message (weird format to work with ncurses)
            string convert = to_string(choice);
            char const *c = convert.c_str();
            char mesg1[] = "    You chose ";
            char mesg2[] = " pancakes    ";
            strcat(mesg1, c);
            strcat(mesg1, mesg2);

            // print message
            mvwprintw(input_n_win, 1, 3, "%s", mesg1);
            wrefresh(input_n_win);

            // ask user to confirm choice
            attron(A_STANDOUT);
            mvprintw(18, 24, "Press Enter to confirm choice");
            attroff(A_STANDOUT);
            canEnter = true;
            refresh();
        }
        else if (canEnter && key_input == 10) { // check if enter was pressed
            

            show_AIstrength_selector(choice);
        } else {
            // print message
            mvwprintw(input_n_win, 1, 3, "     Input a number 2-9    ");
            wrefresh(input_n_win);
            canEnter = false;
        }
    }
}

//void Selector::pancake_choices(WINDOW *win, int n) {

//}

void Selector::show_AIstrength_selector(int a) {

    // erase previous screen
    erase();

    // concatenate message (weird format to work with ncurses)
    string convert = to_string(a);
    char const *c = convert.c_str();
    char mesg[] = "Please input a number 2-";
    strcat(mesg, c);
    mvprintw(10, 22, "How strong should your opponent be?");
    mvprintw(11, 26, "%s", mesg);
    WINDOW *input_diff_win = create_win();

    canEnter = false;

    while (1) {

        // get user input for num of pancakes
        int diff = wgetch(input_diff_win);

        if (diff > 49 && diff < a + 49) {

            // convert from ASCII
            choice = diff - 48;

            // concatenate message (weird format to work with ncurses)
            string convert = to_string(choice);
            char const *c = convert.c_str();
            char mesg1[] = "  You chose a difficulty of ";
            char mesg2[] = "  ";
            strcat(mesg1, c);
            strcat(mesg1, mesg2);

            // print message
            mvwprintw(input_diff_win, 1, 3, "%s", mesg1);
            wrefresh(input_diff_win);

            // ask user to confirm choice
            attron(A_STANDOUT);
            mvprintw(18, 24, "Press Enter to confirm choice");
            attroff(A_STANDOUT);
            refresh();

            canEnter = true;
        }
        else if (canEnter && diff == 10) {

            show_username();
            show_initializer(); // *** CHANGE TO show_username();
        } else {
            // print message
            mvwprintw(input_diff_win, 1, 1, "     Input a valid choice      ");
            wrefresh(input_diff_win);
            canEnter = false;
        }
    }
}



void Selector::show_username() {
/* PROMPT USER FOR NAME */
    erase();

    //Prompt user for input
    mvprintw(10, 22, "Please enter your initails as three characters");
    
    //Creates window to enter value
    WINDOW *input_initials_win = create_win();

   // char emptyString[3] = {}; 
     
    string input; 

    while(1){ //iterates until you get a good value

        //c stores a char and it will be added to the string input
        int c = wgetch(input_initials_win);
        
        if(c == 127){ //If the backspace button is hit
            if(input.length() != 0){
                //If the string can be backspaced
                input.erase(input.length()-1, input.length());
                //Weird string stuff to output string onto screen
                char const *cha = input.c_str();
                    char mesg1[] = "  ";
                    char mesg2[] = "  "; 
                    strcat(mesg1, cha);
                    strcat(mesg1, mesg2);
                    mvwprintw(input_initials_win, 1,3,"%s", mesg1);
            }
        }
        else if(isalpha(c)){ //If it is a character
            if(input.length() < 3){//Only allows three characters in the window
                //Add character to input string
                 
                //input.erase(0,input.length()); 
                input.push_back(c); 
                //Weird stuff to output string onto screen
                char const *ch = input.c_str();
                    char mesg1[] = "  ";
                    char mesg2[] = "  "; 
                    strcat(mesg1, ch);
                    strcat(mesg1, mesg2);
                    mvwprintw(input_initials_win, 1,3,"%s", "    "); 
                    mvwprintw(input_initials_win, 1,3,"%s", mesg1);
            }
        }

        //If the length of the string is 3 characters long then you will be allowed to hit enter
        if(input.length() == 3){
                attron(A_STANDOUT);
                mvprintw(18, 24, "Press Enter to confirm choice");
                attroff(A_STANDOUT);
                refresh();
                canEnter = true; 

        }else{//If string is not three characters long you can't enter
            canEnter = false; 
        }

        if(c == 10 && canEnter){
        //If you hit enter and the input is 3 chars long 
        //then the value is stored and the program continues to the menu
             
            //copys good input as global char[]: initials
            strcpy(initials, input.c_str());

            //loop is exited on good input
            break;
        }
    }


}


void Selector::show_initializer() {
    // erase previous screen
    erase();
    refresh();

    // set choices
    initializer_instructions();
	attron(A_STANDOUT);
	mvprintw(12, 26, "Specify initial state.");
	attroff(A_STANDOUT);
	mvprintw(13, 26, "Play Game (NOT FUNCTIONAL).");
	mvprintw(14, 26, "Show Score Board.");
	mvprintw(15, 26, "Exit Game (NOT FUNCTIONAL).");

    // create counter for menu
    int count = 1;

	while(1) {

        // menu options
		int ch = getch();
		if(ch == '\n') {
            cout << count << endl;
			switch(count) {
                case 1: 
                    specify_state();
                    break;
                case 2:
                    play_game();
                    break;
                case 3:
                    show_scores();
                    break;
                case 4:
                    //endwin();
                    break;
            }
		}
		else if(ch == KEY_UP) {
			if(count > 1) {
				count--;
			} else {
				count = 4;
			}
		}
		else if(ch == KEY_DOWN) {
			if(count < 4) {
				count++;
			} else {
				count = 1;
			}
		}
		switch(count) {
			case 1:
				erase();
                initializer_instructions();
	            attron(A_STANDOUT);
	            mvprintw(12, 26, "Specify initial state.");
	            attroff(A_STANDOUT);
	            mvprintw(13, 26, "Play Game (NOT FUNCTIONAL).");
	            mvprintw(14, 26, "Show Score Board.");
	            mvprintw(15, 26, "Exit Game (NOT FUNCTIONAL).");
				break;
			case 2:
				erase();
                initializer_instructions();
	            mvprintw(12, 26, "Specify initial state.");
                attron(A_STANDOUT);
	            mvprintw(13, 26, "Play Game (NOT FUNCTIONAL).");
                attroff(A_STANDOUT);
	            mvprintw(14, 26, "Show Score Board.");
	            mvprintw(15, 26, "Exit Game (NOT FUNCTIONAL).");
				break;
			case 3:
				erase();
                initializer_instructions();
	            mvprintw(12, 26, "Specify initial state.");
	            mvprintw(13, 26, "Play Game (NOT FUNCTIONAL).");
                attron(A_STANDOUT);
	            mvprintw(14, 26, "Show Score Board.");
                attroff(A_STANDOUT);
	            mvprintw(15, 26, "Exit Game (NOT FUNCTIONAL).");
				break;
			case 4:
				erase();
                initializer_instructions();
	            mvprintw(12, 26, "Specify initial state.");
	            mvprintw(13, 26, "Play Game (NOT FUNCTIONAL).");
	            mvprintw(14, 26, "Show Score Board.");
				attron(A_STANDOUT);
				mvprintw(15, 26, "Exit Game (NOT FUNCTIONAL).");
				attroff(A_STANDOUT);
				break;
        }
    }
}

void Selector::initializer_instructions() {
    mvprintw(8, 20, "If you do not specify the initial state,");
    mvprintw(9, 18, "The game will randomize the order by default");
}

void Selector::specify_state() {

    // erase previous screen
    erase();

    // concatenate message (weird format to work with ncurses)
    string convert = to_string(n);
    char const *c = convert.c_str();
    char mesg[] = "Please input a number 2-";
    strcat(mesg, c);
    mvprintw(10, 20, "What do you want the initial state to be?");
    mvprintw(11, 26, "%s", mesg);
    WINDOW *input_initial_win = create_win();

    canEnter = false;

    while (1) {

        // get user input for num of pancakes
        int initial = wgetch(input_initial_win);

        if (initial > 49 && initial < n + 49) {

            // convert from ASCII
            choice = initial - 48;

            // concatenate message (weird format to work with ncurses)
            string convert = to_string(choice);
            char const *c = convert.c_str();
            char mesg1[] = " You chose initial state of ";
            char mesg2[] = " ";
            strcat(mesg1, c);
            strcat(mesg1, mesg2);

            // print message
            mvwprintw(input_initial_win, 1, 3, "%s", mesg1);
            wrefresh(input_initial_win);

            // ask user to confirm choice
            attron(A_STANDOUT);
            mvprintw(18, 24, "Press Enter to confirm choice");
            attroff(A_STANDOUT);
            refresh();

            canEnter = true;
        }
        else if (canEnter && initial == 10) {
            show_initializer();
        } else {
            // print message
            mvwprintw(input_initial_win, 1, 1, "      Input a valid choice      ");
            wrefresh(input_initial_win);
            canEnter = false;
        }
    }
}

void Selector::show_scores() {
    // erase previous screen
    erase();

    //Output User's initals
    mvprintw(19, 20, "User: ");
    mvprintw(19, 26, getInitials());
    
    //Output User's score
    mvprintw(20, 20, "Score: ");
    mvprintw(20, 27, "%d",getScore());
    

    //Output List of highscores to the screen

    mvprintw(4, 18, "Highscores:");
    attron(A_STANDOUT);
    mvprintw(30, 24, "Press enter to exit.");
    attroff(A_STANDOUT);
   
    
    ScoreBoard scoreBoard ("data.csv");//initializes class ScoreBoard
    
    vector<tuple<string,double>> data =scoreBoard.getScore(); //gets vector of score board
    

    int size = data.size();
    //loop to go through each score and print it on the scrren
    for( int i = 0; i < size; i ++ ) {
        
        //converts string to character array
        
        char initials[4];
        strcpy(initials, get<0>(data.at(i)).c_str()); // copying the contents of the string to char array
        
        //grabs second element in tuple (score)
        int hScore = get<1>(data.at(i));
       
        mvprintw(6+(i*2), 18, "%d", i+1);
        mvprintw(6+(i*2), 20, initials);
        mvprintw(6+(i*2), 25, "%d", hScore);

    }
    
    int ch = getch();
    if (ch == '\n') {
        show_initializer();
    }

}

void Selector::play_game() {
    /* IMPLEMENT LATER 
    
    erase previous screens
    erase();

    mvprintw(10, 20, "Game not functional yet Ctrl + Z to exit");
    refresh(); */
}


