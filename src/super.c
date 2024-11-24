#include "super.h"
#include <hashmap.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* RESERVED_TABLE[] = { "prototypes", "garbage" };

int check_memory_type(void* ptr)
{
  char last_stack_ptr = '\0';
  return (size_t)&last_stack_ptr < (size_t)ptr;
}



super_t_ptr super_new(size_t size)
{

  if (!size) {
    fprintf(stderr, "size can not be 0");
    return NULL;
  }
  hashmap_t* map = (hashmap_t*)malloc(sizeof(hashmap_t));
  map->map = (node_t**)malloc((size + 2) * sizeof(node_t*));
  map->size = size;
  node_t* prototypes = (node_t*)malloc(sizeof(node_t));
  prototypes->name = calloc(11, sizeof(char));
  prototypes->name = strcpy(prototypes->name, RESERVED_TABLE[0]);
  prototypes->structer = (node_t*)malloc(size * sizeof(node_t));

  if (!put(prototypes, map)) {
    fprintf(stderr, "ERROR: Could not put prototype \n");
    return NULL;
  }

  node_t* garbage = (node_t*)malloc(sizeof(node_t));
  garbage->structer = (hashmap_t*)malloc(sizeof(hashmap_t));
  ((hashmap_t*)garbage->structer)->size = size;
  ((hashmap_t*)garbage->structer)->map = (node_t**)malloc(sizeof(node_t*) * size);

  if (!put(prototypes, garbage->structer)) {
    fprintf(stderr, "ERROR: Could not initiliaze garbage \n");
    return NULL;
  }

  if (!put(garbage, map)) {
    fprintf(stderr, "ERROR: Could not put garbage \n");
    return NULL;
  }

  return map;
}

super_t_ptr super_put(node_t* node, hashmap_t* map)
{

}

super_t_ptr super_get(const char* name,hashmap_t* map){

}

super_t_ptr super_del(const char* name,hashmap_t* map){

}

super_t_ptr super_clear(hashmap_t* map){

}

super_t_ptr super_kill(hashmap_t* map){

}

int check_name(const char* name)
{

  size_t name_len = strlen(name);
  if (name_len < 3) {
    return 0;
  }

  node_name_state_t* seperated_name = seperate_name_state(name);

  if (name_len == (strlen(seperated_name->name) + 1)) {
    free(seperated_name);
    return 0;
  }
  free(seperated_name);
  return 1;
}

node_t* dfs(const char* name, hashmap_t* current_node)
{
  if (!current_node) {
    return NULL;
  }
  hashmap_t* inner_map = (hashmap_t*)get(name, current_node->structer)->structer;
  node_t* inner_node = get(name, );
}

void init_super(){
  super.self = &super;
  super.answer = NULL;
  super.put_t = super_put;
  super.get_t = super_get;
  super.new_t = super_new;
  super.del_t = super_del;
  super.clear_t = super_clear;
  super.kill_t = super_kill;
}

