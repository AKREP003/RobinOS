#include "../stdlib/kernel_headers.h"

struct key_value {

    char* key;

    uintptr_t val;

};

struct print_val {

    char* key;

};

struct mov_val {

    char* key1;

    char* key2;

};

enum inst_type {

    in_prnt = 0

};

struct instruct {

    enum inst_type type;

    uintptr_t inst;

};

struct proc {

    struct ll* data;

    struct ll* text;

};

uintptr_t get_val(struct ll* data, char* key) {

    struct ll* buffer = data;

    while (buffer != 0)
    {
        
        if (string_eq(((struct key_value*) (buffer -> val)) -> key, key)) {

            return ((struct key_value*) (buffer -> val)) -> val;

        }

        buffer = LL buffer -> next;

    }
    
    return 0;

}

void eval_prnt(struct ll* data, struct print_val* prnt) {

    char* val = STR get_val(data, prnt -> key);

    if (data != 0) {print_inline(val);}

}

void eval_mov(struct ll* data, struct mov_val* mov) {

    char* val = STR get_val(data, mov -> key1);

    if (val == 0) {return;}

    struct ll* buffer = data;

    while (buffer != 0)
    {
        
        if (string_eq(((struct key_value*) (buffer -> val)) -> key, mov -> key2)) {
 
            ((struct key_value*) (buffer -> val)) -> val = val;

        }

        buffer = LL buffer -> next;

    }
    
    

}

void eval_inst(struct ll* data, struct instruct* i){


    switch (i -> type)
    {
    case in_prnt:

        
        eval_prnt(data, (struct print_val*) i -> inst);

        break;
    
    default:
        break;
    }

}

void start_proc(struct proc* p) {

    struct ll* buffer = p -> text;

    while (buffer != 0)
    {
        
        eval_inst(p -> data, (struct instruct*) (buffer -> val));

        buffer = LL buffer -> next;

    }
    
    

}

enum bool proc_test() {

    struct ll* data = new_ll();

    uintptr_t str = allocate_str("www");

    struct key_value* v = (struct key_value*) alloc(sizeof(struct key_value));

    v -> key = STR str;

    v -> val = PTR str;

    push_dyn(data, PTR v);

    struct print_val* p = (struct print_val*) alloc(sizeof(struct print_val));

    p -> key = STR str;

    struct ll* text = new_ll();

    struct instruct* i = (struct instruct*) alloc(sizeof(struct instruct));

    i -> type = in_prnt;

    i -> inst = PTR p;

    push_dyn(text, PTR i);

    struct proc* r = (struct proc*) alloc(sizeof(struct proc));

    r -> data = data;

    r -> text = text;

    start_proc(r);

    return true;

}
