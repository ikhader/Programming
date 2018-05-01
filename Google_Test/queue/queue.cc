
#include <iostream>
#include "queue.h"
#include <vector>

using namespace std;

queue::queue(int s):enq(0), deq(0), size(s)
{
  Q = new vector<int>(s);
}

queue::~queue()
{
  delete Q;
}

bool queue::EnQ(int ele)
{
  if(enq >= size)
    return false;

  (*Q)[enq++] = ele;
  return true;
}

int queue::DeQ()
{
  if(enq == 0 || enq == deq)
    return -1;

  return (*Q)[deq++];
}

void queue::print_q()
{
  int i;
  for(i = deq; i < enq; i++)
    cout<<"ele: "<<(*Q)[i]<<endl;
}

void queue::get_q(vector<int> &v)
{
  int i;
  for(i = deq; i < enq; i++)
    v.push_back((*Q)[i]);
}

int main_(int argc, char *argv[])
{
  int arr[] = {10,20,30,40,50};

  queue *q = new queue(5);
  for(int i = 0; i < sizeof(arr)/sizeof(arr[0]); i++)
  {
    q->EnQ(arr[i]);
  }
  cout<<"after adding 5 elements: "<<endl;
  q->print_q();
  cout <<endl;  
  cout <<endl;  

  int ele = 0;
  ele = q->DeQ();
  cout<<"dequeud: " <<ele <<endl;
  ele = q->DeQ();
  cout<<"dequeud: " <<ele <<endl;
  ele = q->DeQ();
  cout<<"dequeud: " <<ele <<endl;
  ele = q->DeQ();
  cout<<"dequeud: " <<ele <<endl;
  ele = q->DeQ();
  cout<<"dequeud: " <<ele <<endl;

  cout<<"after popping first element: "<<endl;
  q->print_q();
  cout <<endl;  
  cout <<endl;  
  
  return 0;
}
