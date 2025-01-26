#include "arkanoid.hpp"
#include <ncurses.h>
#include <chrono> 
#include <unistd.h>


int main() {
    
    initscr();
    noecho(); 
    keypad(stdscr, true);
    cbreak();
    curs_set(0);

    Arkanoid game;
 

    while ( true ) {
        wclear(stdscr);

        auto x = game.getArr();
        for (int i = 0; i < x.size(); i++) {
            printw("|");
            for (int j = 0; j < x[i].size(); j++) {
                if ( x[i][j] == 0 ) 
                    printw( " "); // Выводим текст
                else if ( x[i][j] == 1 ) 
                    printw("#");
                else if ( x[i][j] == 2 ) 
                    printw("o");
                else 
                    printw("-");
            }
            printw("|\n");
        }
        refresh();

        auto start = std::chrono::high_resolution_clock::now();
        halfdelay(1);
        auto key = getch();
        switch (key) {
            case KEY_LEFT :
                game.shiftPlatform(Arkanoid::TYPE_STEP::left);
        		break;
    	    case KEY_RIGHT :
	            game.shiftPlatform(Arkanoid::TYPE_STEP::right);
    	        break;
        }
        auto end = std::chrono::high_resolution_clock::now();
        double elapsed = (std::chrono::duration_cast<std::chrono::milliseconds>(end - start)).count();
        if ( elapsed < 100 ) 
            usleep((100 - elapsed) * 1000);

        if ( game.step() ) 
            break;
        //       refresh(); 
        flushinp();
    }
    printw("End game");
    getch();
    getch();
    curs_set(1);
    endwin();
}
