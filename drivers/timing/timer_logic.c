
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
