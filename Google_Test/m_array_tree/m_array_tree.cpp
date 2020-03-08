#include <iostream>
#include <vector>
#include <queue>
#include <map>

using namespace std;

struct __stnode;
typedef vector<__stnode*> temporary; 
typedef struct __stnode
{
  vector<__stnode*> *kidoos;
  int data;
  uint children_count;
}stnode;

stnode * m_tree_create_node(int data)
{
    stnode *n = (stnode *) malloc(sizeof(stnode));
    if(NULL == n)
    {
        cerr <<"Error in allocating memory - m_tree_create_node" << endl;
        return NULL;
    }
    n->kidoos = new vector<stnode*>(0);
    n->children_count = 0;
    n->data = data;
    return n;
}

bool m_tree_add_node(stnode *head, stnode* n)
{
    if ( NULL == head || NULL == n)
    {
        return false;
    }
    
    head->kidoos->push_back(n);
    head->children_count++;
    return true;
}

void m_tree_erase(stnode *h)
{
    queue<stnode *> Q;
    Q.push(h);
    while(Q.size())
    {
        h = Q.front();
        Q.pop();

        for(int i = 0; i < h->children_count ; i++)
        {
            Q.push(h->kidoos->operator[](i));
        }
        //cout <<"delete: " << h->data << endl;
        free(h);

    }
}

void m_tree_delete_node(stnode *n)
{
    if (NULL == n) return;

    for(int i = 0; i < n->children_count; i++)
    {
        free(n->kidoos->operator[](i));
    }
    free (n);
}

void m_tree_print_children(stnode *head)
{
    cout <<"parent node: " << head->data <<endl;
    cout << "list of children: " <<endl;
    for (vector<__stnode*>::iterator ite = head->kidoos->begin(); ite != head->kidoos->end(); ite++)
    {
        cout<<(*ite)->data << " ";
    }
    cout <<endl;
}

#define SEPERATOR NULL

void m_tree_get_level_order(stnode *h, vector<int> &details, int sep)
{
    if (NULL == h) return;

    queue<stnode*> Q;

    Q.push(h);
    Q.push(SEPERATOR);

    details.push_back(h->data);
    //cout <<" Pushing " << h->data <<endl;
    details.push_back(sep);

    while(Q.size())
    {
        stnode *t = Q.front();
        Q.pop();
        while(t != SEPERATOR)
        {
            int i = 0;
            while(i < t->children_count)
            {
                details.push_back(t->kidoos->operator[](i)->data);
                //cout <<"Pushing: " << t->kidoos->operator[](i)->data << endl;
                Q.push(t->kidoos->operator[](i));
                i++;
            }
            t = Q.front();
            Q.pop();
        }
        if(Q.size())
          Q.push(SEPERATOR);
        details.push_back(sep);
    }
}

long long m_tree_sum_all_nodes(stnode *h)
{
    if (NULL == h) return 0;
    long long total = 0;

    vector<stnode *> v;
    v.push_back(h);

    cout <<"size is: " << v.size() <<endl;

    while(v.size())
    {
        h = v.back();
        v.pop_back();
        total += h->data;
        //cout << "running total: " << total << " current node: " << h->data << endl;
        //v.insert(v.end(), h->kidoos->begin(), h->kidoos->end());
        for (int i = 0; i < h->kidoos->size(); i++)
          v.push_back(h->kidoos->operator[](i));

    }
    return total;
}

void copy_parent_child_to_hash_map(stnode *n, map<stnode*, stnode*>&h)
{
  for(int i = 0; i < n->children_count; i++)
    h[n->kidoos->operator[](i)] = n;
}

void generate_parent_child_map(stnode *h, map<stnode *, stnode *> &m)
{
  if (NULL == h) return ;

  queue<stnode *> Q;

  Q.push(h);
  while(Q.size())
  {
    stnode *t = Q.front();
    Q.pop();
    copy_parent_child_to_hash_map(t, m);
    for(int i = 0; i < t->kidoos->size(); i++)
    {
      Q.push(t->kidoos->operator[](i));
    }
  }

}

void print_parent_child_map(map <stnode *, stnode*> m)
{
  for(map<stnode *, stnode *>::iterator it = m.begin(); it != m.end(); it++)
  {
    cout << "child: " << it->first->data << " parent: " << it->second->data <<endl;
  }
}

/*
         10
--------------------   
   /      |       \       \
  20     30       40      50
 / \   /          / |  \
60 70 80        90 100  110
     +++++              +++++++++++++
    /  |   \           /   |   |     \
  120 130  140        150  160 170  180
 */

stnode * m_tree_create(stnode **head)
{
   stnode *h = m_tree_create_node(10);

   stnode *t =  m_tree_create_node(20);
   m_tree_add_node(h, t);
 
   t =  m_tree_create_node(30);
   m_tree_add_node(h, t);
   t =  m_tree_create_node(40);
   m_tree_add_node(h, t);
   t =  m_tree_create_node(50);
   m_tree_add_node(h, t); 


   t =  m_tree_create_node(60);
   m_tree_add_node(h->kidoos->operator[](0), t);
   t =  m_tree_create_node(70);
   m_tree_add_node(h->kidoos->operator[](0), t);
   
   t =  m_tree_create_node(80);
   m_tree_add_node(h->kidoos->operator[](1), t);

   t =  m_tree_create_node(90);
   m_tree_add_node(h->kidoos->operator[](2), t);
   t =  m_tree_create_node(100);
   m_tree_add_node(h->kidoos->operator[](2), t);
   t =  m_tree_create_node(110);
   m_tree_add_node(h->kidoos->operator[](2), t);
   
   stnode *n80 = h->kidoos->operator[](1)->kidoos->operator[](0);
   stnode *n110 = h->kidoos->operator[](2)->kidoos->operator[](2);
   //cout << "n80 data: " << n80->data <<endl;
   //cout << "n110 data: " << n110->data <<endl;
   t =  m_tree_create_node(120);
   m_tree_add_node(n80, t);
   t =  m_tree_create_node(130);
   m_tree_add_node(n80, t);
   t =  m_tree_create_node(140);
   m_tree_add_node(n80, t);

   t =  m_tree_create_node(150);
   m_tree_add_node(n110, t);
   t =  m_tree_create_node(160);
   m_tree_add_node(n110, t);
   t =  m_tree_create_node(170);
   m_tree_add_node(n110, t);
   t =  m_tree_create_node(180);
   m_tree_add_node(n110, t);


  (*head) = h;

  return h;
}

int main(int argc, char *argv[])
{
  cout <<"Hello world - welcome to m-array tree" <<endl;
  stnode *h;
  m_tree_create(&h);

  //m_tree_print_children(h);
  //cout <<endl;
  //m_tree_print_children(h->kidoos->operator[](0));
  //cout <<endl;
  //m_tree_print_children(h->kidoos->operator[](1));
  //cout <<endl;
  //m_tree_print_children(h->kidoos->operator[](2));
  //cout <<endl;

//   vector<int> level_order;
//   m_tree_get_level_order(h, level_order, -1);

//   for(int i = 0; i < level_order.size(); i++)
//   {
//       if (level_order[i] == -1)
//         cout << endl;
//       else
//         cout << level_order[i] << " ";
//   }

  long long total = m_tree_sum_all_nodes(h);
  cout<<"Sum of all nodes: " << total <<endl;

  map<stnode*, stnode*>m;
  generate_parent_child_map(h, m);
  cout << "Map size is " << m.size() << endl;
  print_parent_child_map(m);
  m_tree_erase(h);

  return 0;
}
