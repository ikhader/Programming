#include "hash_map.h"
#include <iostream>

int get_hash_index(int value)
{
  return value % 7;
}

bool chain_insert(hash_map *hm, int key, int value)
{
  int ind = get_hash_index(key);
  stNode *new_node = create_node(value);
  add_node(&(hm->map[ind]), new_node);
  return true;
}

bool chain_delete(hash_map *hm, int key)
{
  return true;
}

bool chain_get(hash_map *hm, int key)
{
  return true;
}

void chain_free(hash_map *hm)
{
  /*
  for(int i = 0; i < hm->max_elements; i++)
  {
    stNode *t = hm->map;
    if (NULL != t)
      delete_list(&t);
  }
  free(hm->map);
  hm->map = NULL;
  free(hm);
  */
}

hash_map* chain_create()
{
  hash_map * hm = (hash_map*) malloc(sizeof(hash_map));
  if(NULL == hm)
  {
    cout<<"Error in memory allocation for hash_map"<<endl;
    return NULL;
  }

  hm->max_elements = MAX_ELE;
  hm->pfn_insert = chain_insert;

  for(int i = 0; i < MAX_ELE; i++)
  {
    hm->map[i] = NULL;
  }
  return hm;
}


int main(int argc, char *argv[])
{
  
  hash_map *hm = chain_create(20);
  hm->pfn_insert(hm, 8, 8);
  hm->pfn_insert(hm, 15, 15);
}



