
#include "../stdlib/kernel_headers.h"

char* entry_buffer = STR 25000;

short index = 0;

struct ll* split_args(char* promopt) {

    struct ll* buffer_ll = split_string(promopt, ' ');

    return buffer_ll;

}

void print_pointer(uintptr_t ptr) {print_string(STR ptr); print_string(" ");}
void print_pointer_ln(uintptr_t ptr) {print_inline(STR ptr); print_inline("");}

void digest_console_prompt(struct ll* prompt) {

    char* primer = STR get_nth_element(prompt, 0);

    if (string_eq(primer, "echo")) {
        
        struct ll* params = LL prompt -> next;

        for_each(params, print_pointer);

        print_inline("");

    }

    if (string_eq(primer, "lf")) {
        
        print_inline("");

        

        

        print_inline("");

    }

    if (string_eq(primer, "rd")) {
        
        print_inline("");

        short r = parse_file_path(STR get_nth_element(prompt, 1));

        
        if (r != 0) {

            print_inline(STR read_file(r));

        }

        

        print_inline("");

    }

    

}

void console_init() {

    entry_buffer = STR alloc(64);

    print_inline("Console init:");

    print_string("\r\n");

    print_string("-> ");

    while (true)
    {
        short x = get_nth_fibo(4000);

        read_key();
        
        

        if (KEY_READ == 0 || KEY_READ > 127) {
            continue;
        }

        if (KEY_READ == 13 || index >= 62) {

            print_string("\r\n");

            struct ll* split = split_string(entry_buffer, ' ');

            print_integer(PTR split);

            //digest_console_prompt(split);

            free_ll(PTR split);

            print_string("-> ");

            index = 0;

            entry_buffer[0] = (char) 0x0;
            
            continue;

        }
        
        print_char(KEY_READ);

        enum bool cont_flag = false;

        switch (KEY_READ) {
            
            case (8):

                entry_buffer[index] = 0;
                index  = max(0, index - 1);
                
                cont_flag = true;

                break;
            

        }
        
        if (cont_flag) {continue;}

        entry_buffer[index] = KEY_READ;

        entry_buffer[index + 1] = (char) 0x0;

        index++;
        
        x = get_nth_fibo(4000);

    }

}



