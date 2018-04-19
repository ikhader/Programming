#ifndef __QUICK_FIND__
#define __QUICK_FIND__

#include <vector>

using namespace std;

class quick_find
{
  private:
    vector<int> *uf_array;
  public:
    quick_find(int max = 5);
    ~quick_find();
    bool is_connected(int p, int q);
    void print_array();
    bool connect_nodes(int p, int q);
    int get_size();
  
};

#endif //__QUICK_FIND__
