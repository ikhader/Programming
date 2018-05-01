#ifndef __QUEUE__
#define __QUEUE__
#include <vector>

using namespace std;

class queue
{
  private:
    vector<int> *Q;
    int enq, deq, size;
  public:
    queue(int size = 10);
    ~queue();
    bool EnQ(int ele);
    int DeQ();
    void print_q();
    void get_q(vector<int> &v);
    
};

vector<int>* q_create(int size);
  
#endif //__QUEUE__
