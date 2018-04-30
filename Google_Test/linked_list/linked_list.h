
#ifndef __LINKED_LIST__
#define __LINKED_LIST__

#include <vector>
using namespace std;

typedef struct _node
{
  int data;
  _node *n;
}stNode;

stNode * create_node(int data);
bool delete_list(stNode **h);
bool add_node(stNode **h, int data);
bool add_node(stNode **h, stNode *data);
bool get_node_details(stNode *h, vector<int> &dets);
int get_total_nodes(stNode *h);
bool delete_node_at_index(stNode **h, int index);
bool reverse_list(stNode **h);
#endif // __LINKED_LIST__
