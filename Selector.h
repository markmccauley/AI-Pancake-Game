#include <ncurses.h>
#include <panel.h>

using namespace std;

class Selector {
private:
    int n;
    int key_input;
    int choice;
    bool canEnter;
    char initials[3]; 
    int score;

public:
    // default constructor?

    WINDOW* create_win();
    void show_selector();
    void pancake_choices(WINDOW *win, int n);
    void show_AIstrength_selector(int n);
    void show_initializer();
    void initializer_instructions();
    void specify_state();
    void show_scores();
    void play_game();
    char* getInitials(){return initials;};
    int getScore(){return score;};
    void show_username();
    
};
