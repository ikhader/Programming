#include <iostream>
#include <vector>
#include "quick_find.h"


/*
v1 = get value at uf_array[q];
v2 = get value at uf_array[p]
run through the array and update all values of v2 with v1
*/
void quick_find::connect_nodes(int p, int q)
{
  int v1 = uf_array->operator[](p);
  int v2 = uf_array->operator[](q);

  for(int i = 0; i < uf_array->size(); i++)
  {
    if(v2 == uf_array->operator[](i))
    {   
      uf_array->at(i) = v1; 
    }   
  }
}


quick_find::quick_find(int max_ele)
{
  //uf_array = new std::vector<int>(max_ele);
  uf_array = new std::vector<int>;

  cout <<"sizeof vector: "<<uf_array->size()<< endl;

  for(int i = 0; i < max_ele; i++)
  {
    uf_array->push_back(i);
  }
  print_array();
}

bool quick_find::is_connected(int p, int q)
{
  return (uf_array->operator[](p) == uf_array->operator[](q));
}

void quick_find::print_array()
{
  cout <<"array is size:"<< uf_array->size() << endl;
  for(std::vector<int>::iterator it =  uf_array->begin(); it != uf_array->end(); it++)
    cout<<*it << " ";
  cout <<endl;
}

quick_find::~quick_find()
{
  delete uf_array;
}
int quick_find::get_size()
{
  return uf_array->size();
}
