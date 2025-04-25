
#include "../../stdlib/kernel_headers.h"

short base_file_location = 0;

struct file_data {

   char* name;

   short disc_loc;

   short parent_loc;

   uintptr_t buffer;

   char* tree_loc;

   enum bool lock;

};


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

struct file_system_location{

   char* name;

   short parent_loc;

};

short parse_file_path(char* path) {

   if (string_eq(path, "")) {return base_file_location;}

   struct ll* folder_location = split_string(path, '>');

   

   char* base_file = (char*) read_file(base_file_location);

   
   
   return 0;

}

struct file_data read_file_data(short disc_loc, char* location) {

   

   struct ll* path_data = split_string(location, ':');

   char* name = (char*) get_nth_element(path_data, 1);

   char* parent_path = (char*) get_nth_element(path_data, 0);
   
   short parent_folder_loc = parse_file_path(parent_path);

   struct file_data buffer = {allocate_str(name), disc_loc, parent_folder_loc, 0, allocate_str(parent_path), false};

   return  buffer; 

}

void refresh_file_data(struct file_data* dat) {

   free(dat -> buffer);

   dat -> buffer = read_file(dat -> disc_loc);

}

struct  file_data* create_file(char* location) {
   
   

   struct ll* path_data = split_string(location, ':');

   

   char* name = (char*) get_nth_element(path_data, 1);

   

   char* parent_path = (char*) get_nth_element(path_data, 0);

   short disc_loc = write_file_header(name);

   
   
   short parent_folder_loc = parse_file_path(parent_path);

   

   struct file_data* buffer = (struct file_data*) alloc(0); //{name, disc_loc, parent_folder_loc, 0, parent_path, false}; //allocate name and parent path
   
   

   return  buffer; 
   
}



void file_system_init() {

   short disc_loc = write_file_header("base");
   
   base_file_location = disc_loc;

   char* str = "base";

   write_to_file_pointer(base_file_location, (uintptr_t) str, 5);

   print_inline("file system initialised");   
   
}

enum bool file_handling_test() {

   struct file_data* test = create_file("base>test_folder:test");

   
   return true;

}