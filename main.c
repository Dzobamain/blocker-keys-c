#include <stdio.h>
#include <ncurses.h>

int main() {
    int ch;

    initscr();
    raw(); 
    keypad(stdscr, TRUE);
    noecho();

    printw("(Esc to exit):\n");

    while (1) {
        ch = getch();

        if (ch == 27) {
            break;
        }

        printw("\%d\n", ch);

        refresh();
    }

    endwin();
    return 0;
}
