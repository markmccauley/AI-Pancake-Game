#include <ncurses.h>
#include <panel.h>
using namespace std;

class Splash {
private:
    bool enter;

public:
    // default constructor
    Splash() : enter(true) {}

    // accessors
    bool isPressed() { return enter; }

    // methods
    void show_splash();
    void print_title();
    void blinking_button();
    void print_team();
    void print_animation();
};
