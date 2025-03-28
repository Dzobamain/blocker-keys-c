#include <stdio.h>
#include <unistd.h>
#include <termios.h>

void setup_terminal() {
    struct termios settings;
    tcgetattr(0, &settings);
    settings.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(0, TCSANOW, &settings);
}

void reset_terminal() {
    struct termios settings;
    tcgetattr(0, &settings);
    settings.c_lflag |= (ICANON | ECHO);
    tcsetattr(0, TCSANOW, &settings);
}

int main() {
    char c;
    setup_terminal();

    printf("Press keys (press ESC to quit):\n");

    read(0, &c, 1);

    if (c == 27 /* ESC */) {
        printf("Exiting...\n");
        reset_terminal();
        return -1;
    }

    printf("You pressed: '%c' (ASCII: %d, HEX: 0x%02X)\n", c, c, c);

    reset_terminal();
    return -1;
}
