
#include "../../stdlib/kernel_headers.h"


void wait_sec( short seconds) {

    get_current_time();

    short current_seconds = SEC;

    while (1) {

        get_current_time();

        print_char('\r');

        if ((SEC - current_seconds) >= seconds) {break;}

    }

}

void wait_tick( short ticks) {

    get_current_time();

    short current_ticks = TICKS_LOW;

    while (1) {

        get_current_time();

        print_char('\r');

        if ((TICKS_LOW - current_ticks) >= ticks) {break;}

    }

}

short get_nth_fibo(short n) {

    short x1 = 1;

    short x2 = 1;

    for (short i = 3; i <= n; i++) {

        short buffer = x2;

        x2 = x1 + x2;

        x1 = buffer;

    }

    return x2;

}
