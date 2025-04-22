
#include "../../stdlib/kernel_headers.h"


void wait_sec(short seconds) {

    get_current_time();

    short current_seconds = SEC;

    while (true) {

        get_current_time();

        print_integer(SEC - current_seconds);

        
        if ((SEC - current_seconds) > seconds) {break;}

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
