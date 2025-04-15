
#include "../../stdlib/kernel_headers.h"

int base_file_location = 0;

struct ll* parse_folder(char* data){

   return split_string(data, '+');
   
}

int get_entry(struct ll* fold, char* key) {

   int buffer = 0;

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

int parse_file_path(char* path) {

   if (string_eq(path, "")) {return base_file_location;}

   struct ll* folder_location = split_string(path, '>');

   char* base_file = (char*) read_file(base_file_location);
   
   print_string(base_file);

   return 0;

}

void create_file(char* name, char* location) {

   int disc_loc = write_file_header(name);
   
   int parent_folder = parse_file_path(location);

   print_integer(parent_folder);

}



void file_system_init() {

   int disc_loc = write_file_header("base");

   //write_to_file(disc_loc, (int*) "a", (str_size("a") + 1) * sizeof(char));
  
   base_file_location = disc_loc;

   //write_to_file(FILE_SYTEM_HEADER, (int*) "bbaa", 5);

   

   
}
