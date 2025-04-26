
#include "../../stdlib/kernel_headers.h"

short base_file_location = 0;

struct file_cache {

   char* name;

   short disc_loc;

   short parent_loc;

   uintptr_t buffer;

   char* tree_loc;

   short size;

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

      carrier_buffer = (struct ll*) carrier_buffer -> next;

    } ;

   return 0;

}



short parse_file_path(char* path) {

   if (string_eq(path, "")) {return base_file_location;}

   struct ll* folder_location = split_string(path, '>');

   short index = 0;

   //char* base_file = (char*) read_file(base_file_location);

   
   //short fold_loc = get_entry(parse_folder(base_file), STR get_element_val(folder_location));
   
   
   //print_integer(fold_loc);

   return 0;

}

struct file_cache* create_file_cache_from(short disc_loc, char* location) {

   

   struct ll* path_data = split_string(location, ':');

   char* name = (char*) get_nth_element(path_data, 1);

   char* parent_path = (char*) get_nth_element(path_data, 0);
   
   short parent_folder_loc = parse_file_path(parent_path);

   struct file_header* head = read_file_header(disc_loc);

   
   struct file_cache* buffer = (struct file_cache*) alloc(sizeof(struct  file_cache));

   buffer -> name = STR allocate_str(name);

   buffer -> disc_loc = disc_loc;

   buffer -> buffer = read_file(disc_loc);


   buffer -> parent_loc = parent_folder_loc;

   buffer -> lock = false;

   buffer -> tree_loc = STR allocate_str(parent_path);

   buffer -> size = head -> size;

   

   return  buffer; 

   
}

void refresh_file_cache(struct file_cache* dat) {



   free(dat -> buffer);

   
   dat -> buffer = read_file(dat -> disc_loc);

   
}

void commit_file_cache(struct file_cache* dat) {

   write_to_file(dat -> disc_loc, dat -> buffer, dat -> size);

   dat -> size = read_file_header(dat -> disc_loc) -> size;

}

struct file_cache* create_file_cache(char* location) {
   
   

   struct ll* path_data = split_string(location, ':');

   char* parent_path = (char*) get_element_val(path_data);

   

   short parent_folder_loc = parse_file_path(parent_path);

   
   char* name = (char*) get_nth_element(path_data, 1);



   short disc_loc = write_file_header(name);

   
   
   

   

   struct file_cache* buffer = (struct file_cache*) alloc(sizeof(struct  file_cache));

   buffer -> name = STR allocate_str(name);

   buffer -> disc_loc = disc_loc;

   buffer -> buffer = read_file(disc_loc);

   buffer -> parent_loc = parent_folder_loc;

   buffer -> lock = false;

   buffer -> tree_loc = STR allocate_str(parent_path);

   buffer -> size = 0;

   return  buffer; 
   
}



void file_system_init() {

   short disc_loc = write_file_header("base");
   
   base_file_location = disc_loc;

   char* str = "folder=70";

   write_to_file(base_file_location, (uintptr_t) str, str_size(str) + 1);

   
   
}

enum bool file_handling_test() {

   char* str = "ads";

   struct file_cache* test = create_file_cache("folder>w:test");

   

   free(test -> buffer);
   
   test ->buffer = alloc(20);

   cpy(test ->buffer, PTR str, 4);

   //test -> size = 4;

   //commit_file_cache(test);

   //char* str2 = "axs";

   //cpy(test ->buffer, PTR str2, 4);

   //refresh_file_cache(test);

   

   enum bool cond = true;//string_eq(STR test -> buffer, str);


   free(PTR test);

   
   return cond;

}