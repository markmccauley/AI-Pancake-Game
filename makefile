all: game

Splash.o: Splash.cpp
	g++ -std=c++17 -c -g Splash.cpp -Wall -Wextra -pedantic -fno-omit-frame-pointer -lncurses++ -lmenu -lpanel -lform -lutil -lncurses

Selector.o: Selector.cpp
	g++ -std=c++17 -c -g Selector.cpp -Wall -Wextra -pedantic -fno-omit-frame-pointer -lpanel -lncurses
	
ScoreBoard.o: ScoreBoard.cpp
	g++ -std=c++17 -c -g ScoreBoard.cpp -Wall -Wextra -pedantic -fno-omit-frame-pointer -lpanel -lncurses

Pancake_Stack.o: Pancake_Stack.cpp
	g++ -std=c++17 -c -g Pancake_Stack.cpp -Wall -Wextra -pedantic -fno-omit-frame-pointer -lpanel -lncurses
	
Main.o: Main.cpp
	g++ -std=c++17 -c -g Main.cpp -Wall -Wextra -pedantic -fno-omit-frame-pointer -lpanel -lncurses

game: Main.o Splash.o Selector.o
	g++ -std=c++17 -o game Main.o Splash.o Selector.o -Wall -Wextra -fno-omit-frame-pointer -lpanel -lncurses

clean:
	rm *.o
