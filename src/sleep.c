#include "sleep.h"

// Definição da função
void mSleep(int milliseconds) {
    long pause;
    clock_t now, then;

    pause = milliseconds * (CLOCKS_PER_SEC / 1000);
    then = clock();

    do {
        now = clock();
    } while (now - then < pause);
}