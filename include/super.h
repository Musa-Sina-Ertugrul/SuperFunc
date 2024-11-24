#ifndef SUPER
#define SUPER
#include <hashmap.h>

typedef struct super_t *super_t_ptr;

struct super_t {
  
  super_t_ptr self;
  void** answer;
  super_t_ptr (*put_t)(node_t*,hashmap_t*);
  super_t_ptr (*get_t)(const char* name,hashmap_t* map);
  super_t_ptr (*new_t)(size_t);
  super_t_ptr (*del_t)(const char*,hashmap_t*);
  super_t_ptr (*clear_t)(hashmap_t*);
  super_t_ptr (*kill_t)(hashmap_t*);

};

struct super_t super;

void init_super();

super_t_ptr super_put(node_t* node, hashmap_t* map);

super_t_ptr super_get(const char* name, hashmap_t* map);

super_t_ptr super_new(size_t size);

super_t_ptr super_del(const char* name,hashmap_t* map);

super_t_ptr super_clear(hashmap_t* map);

super_t_ptr super_kill(hashmap_t* map);

#ifdef test

int check_name(const char* name);

#endif

#endif
