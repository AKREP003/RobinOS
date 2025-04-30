
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

      carrier_buffer = (struct ll*) carrier_buffer -> next;

      free_ll(PTR entry);



    } ;

   return 0;

}



short parse_file_path(char* path) {

   if (string_eq(path, "")) {return base_file_location;}

   

   struct ll* folder_location = split_string(path, '>');

   uintptr_t folder_copy = PTR folder_location;

   short index = 0;

   short parental_loc = base_file_location;

   while (true) {

      char* base_file = STR read_file(parental_loc);

      struct ll* parsed = parse_folder(base_file);

      short fold_loc = get_entry(parsed, STR get_element_val(folder_location));

      if (folder_location -> next == 0) {

         return fold_loc;

      }

      free(PTR base_file);

      free_ll(PTR parsed);

      parental_loc = fold_loc;

      folder_location = LL folder_location -> next;

   }

   free_ll(PTR folder_copy);

}

short get_folder_entry(short fold_loc, char* name) {

   char* contents = STR read_file(fold_loc);

   struct ll* entries = parse_folder(contents);

   short entry = get_entry(entries, name);

   free(PTR contents);

   free_ll(PTR entries);

   return entry;

}

struct file_cache* create_file_cache_from(char* location) {

   

   struct ll* path_data = split_string(location, ':');

   char* parent_path;

   short parent_folder_loc;

   char* name;

   if (get_ll_size(path_data) > 1) {

      parent_path = (char*) get_element_val(path_data);

      name = (char*) get_nth_element(path_data, 1);

   } else {

      parent_path = "";

      name = (char*) get_nth_element(path_data, 0);

   }

   parent_folder_loc = parse_file_path(parent_path);

   
   short disc_loc = get_folder_entry(parent_folder_loc, name);

   

   struct file_cache* buffer = (struct file_cache*) alloc(sizeof(struct  file_cache));

   struct file_header* head = read_file_header(disc_loc);

   buffer -> size = head ->size;

   free(PTR head);

   buffer -> name = STR allocate_str(name);

   buffer -> disc_loc = disc_loc;

   buffer -> buffer = read_file(disc_loc);

   
   buffer -> parent_loc = parent_folder_loc;

   buffer -> lock = false;

   buffer -> tree_loc = STR allocate_str(parent_path);

   

   free_ll(PTR path_data);

   free(PTR buffer);

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


void add_folder_entry(short fold_loc, short file_loc, char* name) {

   char* contents = STR read_file(fold_loc);

   short size = str_size(contents);

   char* res = "               ";

   char* file_loc_str = itoa(file_loc, res, 10);

   char* entry_buffer = STR alloc(str_size(name) + str_size(file_loc_str) + 3);

   entry_buffer[0] = '+';

   cpy(PTR entry_buffer + 1, PTR name, str_size(name));

   entry_buffer[str_size(name) + 1] = '=';

   cpy(PTR (entry_buffer + str_size(name) + 2), PTR file_loc_str, str_size(file_loc_str));

   entry_buffer[str_size(name) + str_size(file_loc_str) + 2] = (char) 0;

   uintptr_t new_buffer = alloc(size + str_size(entry_buffer) + 1);

   cpy(new_buffer, PTR contents, size);

   cpy(new_buffer + size, PTR entry_buffer, str_size(entry_buffer));

   (STR new_buffer)[size + str_size(entry_buffer) + 1] = (char) 0;

   write_to_file(fold_loc, PTR new_buffer, str_size(STR new_buffer) + 1);

   free(PTR contents);

   free(PTR entry_buffer);

   free(PTR new_buffer);

}



struct file_cache* create_file_cache(char* location) {
   
   

   struct ll* path_data = split_string(location, ':');

   char* parent_path;

   short parent_folder_loc;

   char* name;

   if (get_ll_size(path_data) > 1) {

      parent_path = (char*) get_element_val(path_data);

      parent_folder_loc = parse_file_path(parent_path);

      name = (char*) get_nth_element(path_data, 1);

   } else {

      parent_path = "";

      parent_folder_loc = parse_file_path(parent_path);

      name = (char*) get_nth_element(path_data, 0);

   }

   short disc_loc = write_file_header(name);

   add_folder_entry(parent_folder_loc, disc_loc, name);

   struct file_cache* buffer = (struct file_cache*) alloc(sizeof(struct  file_cache));

   buffer -> name = STR allocate_str(name);

   buffer -> disc_loc = disc_loc;

   buffer -> buffer = read_file(disc_loc);

   buffer -> parent_loc = parent_folder_loc;

   buffer -> lock = false;

   buffer -> tree_loc = STR allocate_str(parent_path);

   buffer -> size = 0;

   free_ll(PTR path_data);

   free(PTR buffer);

   return  buffer; 
   
}



void file_system_init() {

   short disc_loc = write_file_header("base");
   
   base_file_location = disc_loc;

   char* str = "a=70";

   write_to_file(base_file_location, (uintptr_t) str, str_size(str) + 1);

   
   
}

void write_to_cache(char* text, struct file_cache* cache) {

   short size = str_size(text) + 1;

    uintptr_t secret_buffer = alloc(size);

    cpy(secret_buffer, PTR text, size);
    
    cache -> buffer = secret_buffer;

    cache -> size = size;

    commit_file_cache(cache);

    free(secret_buffer);

}

void free_cache(struct file_cache* p) {

   free(p -> buffer);

   free(PTR p ->name);

   free(PTR p->tree_loc);

   free(PTR p);

}

enum bool file_handling_test() {

   char* str = "ads";

   struct file_cache* test = create_file_cache(":god");

   free(test -> buffer);
   
   test ->buffer = alloc(20);

   cpy(test ->buffer, PTR str, 4);

   test -> size = 4;

   commit_file_cache(test);

   char* str2 = "axs";

   cpy(test ->buffer, PTR str2, 4);

   refresh_file_cache(test);  

   enum bool cond = string_eq(STR test -> buffer, str);

   print_string("aaaaaa");

   struct file_cache* create_from = create_file_cache_from(":god");

   print_string("bbbbbbb");

   enum bool cond2 = (create_from -> disc_loc) == (test -> disc_loc);

   free_cache(test);

   free(PTR create_from);

   return cond && cond2;

}