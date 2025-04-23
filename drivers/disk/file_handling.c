
#include "../../stdlib/kernel_headers.h"

short base_file_location = 0;

struct ll* parse_folder(char* data){

   return split_string(data, '+');
   
}

short get_entry(struct ll* fold, char* key) {

   short buffer = 0;

    struct ll* carrier_buffer = fold;

    while ((carrier_buffer) != 0) {

      struct ll* entry = split_string((char*) get_element_val(carrier_buffer), '=' );

      if (string_eq((char*) get_nth_element(entry, 0), key)) {

         return atoi((char*) get_nth_element(entry, 1));

      }

      carrier_buffer = carrier_buffer -> next;

    } ;

   return 0;

}

short parse_file_path(char* path) {

   if (string_eq(path, "")) {return base_file_location;}

   struct ll* folder_location = split_string(path, '>');

   char* base_file = (char*) read_file(base_file_location);

   return base_file_location;

}

void create_file(char* name, char* location) {

   short disc_loc = write_file_header(name);
   
   //short parent_folder = parse_file_path(location);

   

}



void file_system_init() {

   short disc_loc = write_file_header("base");
   
   base_file_location = disc_loc;

   char* str = "base";

   write_to_file(base_file_location, (uintptr_t) str, 5);

   print_inline("file system initialised");   
   
}

enum bool file_handling_test() {

   create_file("test", "test_fold");

   return true;

}