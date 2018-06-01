

#ifndef __HASH_MAP_G_TEST__
#define __HASH_MAP_G_TEST__

#include "linked_list.h"

//farword declaration
struct hash_map;
typedef bool (*insert)(hash_map *,  int key, int value);
#define MAX_ELE  20
struct hash_map
{
  stNode *map[MAX_ELE];
  int max_elements;
  insert pfn_insert;
  
};


#endif //__HASH_MAP_G_TEST__
