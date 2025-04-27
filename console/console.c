
#include "../stdlib/kernel_headers.h"

void console_init() {

    while (true)
    {
        short x = get_nth_fibo(4000);

        read_key();
        
        print_string("");

        if (KEY_READ == 0 || KEY_READ > 127) {
            continue;
        }

        if (KEY_READ == 13) {

            print_inline("");

            continue;

        }
        
        print_char(KEY_READ);

        
        
        x = get_nth_fibo(4000);

    }

}