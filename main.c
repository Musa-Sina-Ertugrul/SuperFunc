#include <hashmap.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include "super.h"

node_t* init_node(){
  node_t* node = (node_t*) malloc(sizeof(node_t));
  node->name = calloc(9,sizeof(char));
  node->name = strcpy(node->name,"s_test_1\0");
  node->structer = malloc(sizeof(char));
  return node;
}

hashmap_t* init_hashmap(){
  
}

int main(){
  node_t* test_node_1 = init_node();
  super_t_ptr super;
  init_super(super);
  printf("1 Test passed \n");
  super->new_t(super,19);
  printf("2 Test passed \n");
  assert((node_t*) get("garbage",((hashmap_t*)super->answer)));
  printf("3 Test passed \n");
  assert((node_t*) get("prototypes",((hashmap_t*)super->answer)));
  printf("4 Test passed \n");
  hashmap_t* class_A = (hashmap_t*) super->answer;
  super->put_t(super,test_node_1,class_A,0);
  printf("5 Test passed \n");
  ((node_t*)super->get_t(super,"test_1",class_A))->structer;
  printf("6 Test passed \n");
  super->del_t(super,"test_1",class_A);
  assert(!get("test_1",class_A));
  printf("7 Test passed \n");
  return 0;
}
