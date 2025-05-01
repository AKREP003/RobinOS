#include "../stdlib/kernel_headers.h"



void aaa() {
    
    //test_em_all();

    start_video_mode();

    print_inline("");
    print_inline(" /$$$$$$$            /$$       /$$            /$$$$$$   /$$$$$$ ");
    print_inline("| $$__  $$          | $$      |__/           /$$__  $$ /$$__  $$");
    print_inline("| $$  \\ $$  /$$$$$$ | $$$$$$$  /$$ /$$$$$$$ | $$  \\ $$| $$  \\__/");
    print_inline("| $$$$$$$/ /$$__  $$| $$__  $$| $$| $$__  $$| $$  | $$|  $$$$$$ ");
    print_inline("| $$__  $$| $$  \\ $$| $$  \\ $$| $$| $$  \\ $$| $$  | $$ \\____  $$");
    print_inline("| $$  \\ $$| $$  | $$| $$  | $$| $$| $$  | $$| $$  | $$ /$$  \\ $$");
    print_inline("| $$  | $$|  $$$$$$/| $$$$$$$/| $$| $$  | $$|  $$$$$$/|  $$$$$$/");
    print_inline("|__/  |__/ \\______/ |_______/ |__/|__/  |__/ \\______/  \\______/ ");
    print_inline("");

    
    //test_em_all();

    file_system_init();

    char* str = "ads";

    struct file_cache* test = create_file_cache(":god");

    free(test -> buffer);
    
    test ->buffer = alloc(20);

    cpy(test ->buffer, PTR str, 4);

    test -> size = 4;

    commit_file_cache(test);

    dump_allocations();

    print_inline("");
    
    console_init();
    

}



