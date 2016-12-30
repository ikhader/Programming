#include <iostream>
#include <vector>

using namespace std;
/*
 * this is version-2 to find if any of the two nodes in graph are connected
 * Algo: constructor will take maximum number of elements, intializes the values. 
 * Initialization will make sure every node is connected to itself
 * Union: in visualization this will make a tree. 
 *        in practical, we will construct a array & move values to root 
 *
 * is_connected: will check if both the elements have same root.
 *
*/
class quick_union_find
{
  private:
  vector<int> mv_array;
  int max_values;

  public:
  quick_union_find(int cnt):max_values(cnt)
  {
    for (int i = 0; i < cnt; i++)
      mv_array.push_back(i);
  }

  void print_array()
  {
    for(vector<int>::iterator it = mv_array.begin(); it != mv_array.end(); it++)
      cout<< *it << " " ;
    cout << endl;
  }

  int root(int val)
  {
    bool bDone = false;
    int a = val;
    while(!bDone)
    {
      if (a == mv_array[a])
      {
        bDone = 1;
        //cout <<"root of " << val << " is: " << a <<endl;
        return a;
      }
      a = mv_array[a];
    }
    return -1;
  }

  int is_connected(int a, int b)
  {
     return root(mv_array[a]) == root(mv_array[b]);
  }

  bool union_values(int a, int b)
  {
     if(a < 0 || a > max_values || b < 0 || b > max_values)
       return false;

     mv_array[a] = mv_array[b];
     return true;
  }
  
};

int main(int argc, char * argv[])
{
  quick_union_find *uf = new quick_union_find(10);

  cout << "ORIGINAL:" <<endl;
  uf->print_array();
  
  cout << "1, 2 are connected?: " << uf->is_connected(1,2) << endl;

  uf->union_values(1, 2);
  cout << "1, 2 are connected?: " << uf->is_connected(1,2) << endl;
  uf->print_array();


  uf->union_values(2, 8);
  cout << "2, 8 are connected?: " << uf->is_connected(8,2) << endl;
  uf->print_array();

  uf->union_values(3, 9);
  cout << "3, 9 are connected?: " << uf->is_connected(9,3) << endl;

  uf->union_values(8, 9);
  cout << "1, 9 are connected?: " << uf->is_connected(9,1) << endl;


  uf->print_array();


  delete uf;

  cout << "ALL DONE!!!!" <<  endl;
  return 0;
}
