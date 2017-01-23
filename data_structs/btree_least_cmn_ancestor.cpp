#include <iostream>
#include <map>
#include <stdio.h>
#include <malloc.h>

using namespace std;

/*
         90
        /  \
      10   40
     / \   / \
   20  30 50  60

   LCA (20,30) = 10
   LCA (30, 50) = 90
   LCA (40,20) = 90
*/

typedef struct __node
{
  int data;
  struct __node *l;
  struct __node *r;
}stnode;

#define ROOT_PARENT -1

void binarytree_get_parent_child_map(stnode *h, int parent_data, map<int, int> &pc_map)
{
  if(!h)
    return;
  pc_map[h->data] = parent_data;
  binarytree_get_parent_child_map(h->l, h->data, pc_map);
  binarytree_get_parent_child_map(h->r, h->data, pc_map);
}

void print_int_map(map<int, int> m)
{
  cout<<"MAP IS: " <<endl;
  for(map<int, int>::iterator it = m.begin(); it != m.end(); it++)
  {
    cout<< it->first << " -- " << it->second << endl;
  }
}

/*
 * to find out Lowest Common Ansestor (LCA) use this logic
 * 1. create parent child map, meaning map<child> = parent
 * 2. once we have map just run back
 *
*/
void binarytree_lowest_common_ancestor(stnode *h, int ele_1, int ele_2, int &lca)
{
  map<int, int> parent_child_map;

  binarytree_get_parent_child_map(h, ROOT_PARENT, parent_child_map);

  map<int, int>::iterator it1 = parent_child_map.find(ele_1);
  map<int, int>::iterator it2 = parent_child_map.find(ele_2);
  if(it1 == parent_child_map.end() || it2 == parent_child_map.end() )
  {
    cout<<"Either element 1 or element 2 not present" <<endl;
    lca = -1;
    return ;
  }

  //print_int_map(parent_child_map);
  /*
  serach for parents now - as soon as we find one break
  */
  bool bDone = false;
  map<int, int>::iterator it; 
  
  while(!bDone)
  {
    if (it1->second == it2->second)
    {
      lca = it1->second;
      cout<<"Common parent found: " << it1->second<<endl;
      bDone = true;
      break;
    }

    //cout<<"Ele_1: " <<it1->first <<endl;
    it = parent_child_map.find(it1->second);
    if(ROOT_PARENT ==  it->second)
    {
      bDone = true;
      lca = it1->second;
      //cout<<"Ele1 hit root - time to break " << it->second<<endl;
    }
    else
      it1 = it;

    //cout<<"Ele_2: " <<it2->first <<endl;
    it = parent_child_map.find(it2->second);
    if(ROOT_PARENT ==  it->second)
    {
      bDone = true;
      //cout<<"Ele2 hit root - time to break " << it->second<<endl;
      lca = it2->second;
    }
    else
      it2 = it;
    
  }
}

stnode * binarytree_createnode(int data)
{
  stnode *pnode = (stnode*) malloc(sizeof(stnode));
  if(!pnode)
    return NULL;
  pnode->data = data;
  pnode->l = NULL;
  pnode->r = NULL;
 
  return pnode;  
}

int main()
{
  stnode *pstHead = NULL;
  int count = 0;  

  pstHead = binarytree_createnode(90);

  pstHead->l = binarytree_createnode(10);
  pstHead->l->l = binarytree_createnode(20);
  pstHead->l->r = binarytree_createnode(30);


  pstHead->r = binarytree_createnode(40);
  pstHead->r->l = binarytree_createnode(50);
  pstHead->r->r = binarytree_createnode(60);

  int lca = -1;
  binarytree_lowest_common_ancestor(pstHead, 2, 30, lca);
  cout<<"Expected: element not found" <<endl;  

  lca = -1;
  binarytree_lowest_common_ancestor(pstHead, 20, 30, lca);
  cout<<"Expected: 10 received: " <<lca<< endl;  

  lca = -1;
  binarytree_lowest_common_ancestor(pstHead, 60, 30, lca);
  cout<<"Expected: 90 received: " <<lca<< endl;  

  lca = -1;
  binarytree_lowest_common_ancestor(pstHead, 40, 30, lca);
  cout<<"Expected: 90 received: " <<lca<< endl;  

  lca = -1;
  binarytree_lowest_common_ancestor(pstHead, 10, 60, lca);
  cout<<"Expected: 90 received: " <<lca<< endl;  
  
  return 0;
}


