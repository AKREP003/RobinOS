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

    
    test_em_all();

    
    char* str = "mein secret";

    struct file_cache* test = create_file_cache(":gott");

    

    write_to_cache_disk(str, test);

    

    print_inline("");

    wait_sec(2);
    
    console_init();
    

}



