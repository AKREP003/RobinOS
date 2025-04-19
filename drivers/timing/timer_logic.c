
#include "../../stdlib/kernel_headers.h"


void wait_sec(int seconds) {

    get_current_time();

    int current_seconds = SEC;

    while (1) {

        get_current_time();

        print_char('\r');

        if (SEC - current_seconds >= seconds) {break;}

    }

}

int get_nth_fibo(int n) {

    int x1 = 1;

    int x2 = 1;

    for (int i = 3; i <= n; i++) {

        int buffer = x2;

        x2 = x1 + x2;

        x1 = buffer;

    }

    return x2;

}
