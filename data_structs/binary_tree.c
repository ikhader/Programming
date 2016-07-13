#include <stdio.h>
#include <malloc.h>
#include <stdbool.h>
#include <string.h>

typedef struct __node
{
  int data;
  struct __node *l;
  struct __node *r;
}stnode;

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

int max(int a, int b)
{
  return a > b ? a : b;
}

int min(int a, int b)
{
  return a < b ? a : b;
}

int binarytree_getsum(stnode *pstHead)
{
  if(pstHead == NULL)
    return 0;
  return pstHead->data + binarytree_getsum(pstHead->l) + binarytree_getsum(pstHead->r); 
}

int binarytree_getmax(stnode *pstHead)
{
  if(pstHead == NULL)
    return 0;
  return max(pstHead->data, binarytree_getmax(pstHead->r));
}

int binarytree_getmin(stnode *pstHead)
{
  if(pstHead == NULL)
    return 100; //TODO FIX up this
  return min(pstHead->data, binarytree_getmin(pstHead->l));
}

void binarytree_copy_all_elements_to_array( stnode *h, int *p, int *i)
{

  if(h == NULL)
    return ;

  p[*i] = h->data;
  ++*i;
  binarytree_copy_all_elements_to_array(h->l, p, i);
  binarytree_copy_all_elements_to_array(h->r, p, i);

}

int binarytree_findmiddlevalue(stnode *h, int *p, int running_at)
{
  int i = 0;
  if (h == NULL)
    return ;

//  binarytree_findmiddlevalue(h->l, p, running_at);
//  p[running_at++] = h->data;
//  p[running_at++] = binarytree_findmiddlevalue(h->r, p, running_at);
}

bool binarytree_addnode(stnode **pstHead, int data)
{
  stnode *t, *p ;
  bool badd = false;

  p = binarytree_createnode(data);
  if(!p)
    return false;
  
  if(*pstHead == NULL)
  {
    *pstHead = p;
    return true;
  }

  t = *pstHead; 

  while (!badd)
  {
    if(t->data >= p->data)
    {
      if(t->l)
        t = t->l;
      else
      {
        t->l = p;
        badd = true;
      }
    }
    else
    {
      if(t->r)
        t = t->r;
      else
      {
        t->r = p;
        badd = true;
      }
    }
    
  }
  return true;
}

int main()
{
  int a[] = { 50, 20, 30, 10, 90, 60};
  int i ;
  int *p = (int *) malloc(sizeof(int) * sizeof(a)/sizeof(a[0]));
  stnode *pstHead = NULL;
  

  for( i = 0; i < sizeof(a)/sizeof(a[0]); i++)
  {
    binarytree_addnode(&pstHead, a[i]);
  }

  memset(p, 0x00, sizeof(int) * sizeof(a)/sizeof(a[0]));  
  i = 0;
  binarytree_copy_all_elements_to_array(pstHead, p, &i);
  printf("Elements are: \n");
  for( i = 0; i < sizeof(a)/sizeof(a[0]); i++)
  {
    if(p[i])
    printf("[%d] ", p[i]);
  }
  printf("\n");
  //binarytree_findmiddlevalue(pstHead, p, 0);
  printf("SUM of all nodes [%d]\n", binarytree_getsum(pstHead));
  printf("Find max value[%d]\n", binarytree_getmax(pstHead));
  printf("Find min value[%d]\n", binarytree_getmin(pstHead));
  
  return 0;
}



