#include "super.h"
#include <hashmap.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static char* RESERVED_TABLE[] = { "prototypes", "garbage" };

int check_memory_type(void* ptr)
{
  char last_stack_ptr = '\0';
  return (size_t)&last_stack_ptr < (size_t)ptr;
}

super_t_ptr super_new(super_t_ptr super,size_t size)
{

  if (!size) {
    fprintf(stderr, "ERROR: size can not be 0 \n");
    return NULL;
  }
  hashmap_t* map = (hashmap_t*)malloc(sizeof(hashmap_t));
  map->map = (node_t**)malloc(size * sizeof(node_t*));
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
  garbage->name = calloc(8,sizeof(char));
  garbage->name = strcpy(garbage->name,RESERVED_TABLE[1]);
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

  super->answer = (void*) map;
  return super;
}

super_t_ptr super_put(super_t_ptr super,node_t* node, hashmap_t* map,int flag)
{
  if (!put_name_w_states(node,map)){
    fprintf(stderr,"ERROR: Could not put node in map \n");
    return NULL;
  }
  hashmap_t* prototype = (hashmap_t*)  (get("prototypes",map)->structer);
  hashmap_t* garbage = (hashmap_t*)  (get("garbage",map)->structer);
  if (flag){
    if (!put_name_w_states(node,prototype)){
    fprintf(stderr,"ERROR: Could not put node in prototype \n");
    return NULL;
   }
  }
  if (!put_name_w_states(node,garbage)){
    fprintf(stderr,"ERROR: Could not put node in garbage \n");
    return NULL;
  }
  return super;
}

super_t_ptr super_get(super_t_ptr super,const char* name, hashmap_t* map)
{
  node_t* node = get(name,map);
  if (!node){
    fprintf(stderr,"ERROR: Could not get node \n");
    return NULL;
  }
  super->answer = (void*) node;
  return super;
}

super_t_ptr super_del(super_t_ptr super,const char* name, hashmap_t* map)
{
  size_t hash = hashing(name,map->size);
  size_t garbage_hash = hashing("garbage\0",map->size);
  node_t* node = map->map[hash];
  hashmap_t* garbage = (hashmap_t*) map->map[garbage_hash]->structer;
  if (check_memory_type(node->structer)){
    fprintf(stderr,"ERROR: Initiliazed memory is not from heap node structure \n");
    return NULL;
  }
  free(node->structer);

  if (check_memory_type(node->name)){
    fprintf(stderr,"ERROR: Initiliazed memory is not from heap node name \n");
    return NULL;
  }
  free(node->name);

  if (check_memory_type(node)){
    fprintf(stderr,"ERROR: Initiliazed memory is not from heap node \n");
    return NULL;
  }
  free(node);
  garbage->map[hash] = NULL;
  map->map[hash] = NULL;
  return super;
}

super_t_ptr super_clear(super_t_ptr super,hashmap_t* map)
{
  return super;
}

super_t_ptr super_kill(super_t_ptr super,hashmap_t* map)
{
  return super;
}

void init_super(super_t_ptr super)
{
  super->self = super;
  super->answer = NULL;
  super->put_t = super_put;
  super->get_t = super_get;
  super->new_t = super_new;
  super->del_t = super_del;
  super->clear_t = super_clear;
  super->kill_t = super_kill;
}
