#ifndef SUPER
#define SUPER
#include <hashmap.h>

typedef struct super_t *super_t_ptr;

struct super_t {
  
  super_t_ptr self;
  void** answer;
  super_t_ptr (*put_t)(super_t_ptr,node_t*,hashmap_t*,int flag);
  super_t_ptr (*get_t)(super_t_ptr,const char* name,hashmap_t* map);
  super_t_ptr (*new_t)(super_t_ptr,size_t);
  super_t_ptr (*del_t)(super_t_ptr,const char*,hashmap_t*);
  super_t_ptr (*clear_t)(super_t_ptr,hashmap_t*);
  super_t_ptr (*kill_t)(super_t_ptr,hashmap_t*);

};

void init_super(super_t_ptr);

super_t_ptr super_put(super_t_ptr,node_t* node, hashmap_t* map,int flag);

super_t_ptr super_get(super_t_ptr,const char* name, hashmap_t* map);

super_t_ptr super_new(super_t_ptr,size_t size);

super_t_ptr super_del(super_t_ptr,const char* name,hashmap_t* map);

super_t_ptr super_clear(super_t_ptr,hashmap_t* map);

super_t_ptr super_kill(super_t_ptr,hashmap_t* map);

#endif
