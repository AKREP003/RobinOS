
#include "../../stdlib/kernel_headers.h"

struct ll* parse_folder(char* data){

   return split_string(data, '+');
   
}

int get_entry(struct ll* fold, char* key) {

   int buffer = 0;

    struct ll* carrier_buffer = fold;

    while ((carrier_buffer) != 0) {

      struct ll* entry = split_string((char*) get_element_val(carrier_buffer), '=' );

      if (string_eq((char*) get_nth_element(entry, 0), key)) {

         print_string((char*) get_nth_element(entry, 1));

      }

      carrier_buffer = carrier_buffer -> next;

    } ;

   return 0;

}

int parse_file_path(char* path) {
   
   return 0;

}
