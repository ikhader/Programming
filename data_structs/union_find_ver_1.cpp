#include <iostream>
#include <vector>


using namespace std;

/*
 * This class will help us to solve union find probelm
 * Algo:
 *   1. constructor: will accept max number of entries, every element is connected to itself. 
 *   2. print_uf_array: prints values of array
 *   3. union(int a, int b): uf_array[b] = uf_array[a]; also changes all the elements that has value uf_array[a]
 *   4. is_connected(int a, int b): returns uf_array[a] == uf_array[b].. 
 *   
*/

class union_find
{
  private:
    vector<int> uf_array;
    int max_entries;
  public:
    /*
      constructor accepts max number of entries
      makes each element self connected
    */
    union_find(int entries):max_entries(entries)
    {
      cout<<"constructor-entries: " << entries<< endl;
      for(int i = 0; i < entries; i++)
        uf_array.push_back(i);
    }
    /*
       prints array values
    */
    void print_uf_array()
    {
      for(vector<int>::iterator it = uf_array.begin(); it != uf_array.end(); it++ )
        cout << *it <<" ";
      cout <<endl;
    }

    /*
      checks values at indexes a, b. Returns true(if equal) false (if not equal, or out of range)
    */
    bool is_connected(int a, int b)
    {
      if (a < 0 || a > max_entries || b < 0 || b > max_entries)
       return false;

      return uf_array[a] == uf_array[b];
    }
    
    /*
     creates link between a & b 
     @args: int a, int b
     re-intilizes for all values in array uf_array with value uf_array[b] to uf_array[a]
     return true(if successfull)/false (if out of range)
    */
    bool union_values(int a, int b)
    {
      if (a < 0 || a > max_entries || b < 0 || b > max_entries)
        return false;

      int  chk_val = uf_array[b];
      int  rep_val = uf_array[a];
      for(int i = 0; i < uf_array.size(); i++)
      {
        if(uf_array[i] == chk_val)
          uf_array[i] = rep_val;
      }
      return true;
    }
    
};

int main(int argc, char *argv[])
{
  cout << "Union find probelm"<< endl;

  int max_entries = 10;
  
  union_find *uf = new union_find(max_entries) ;

  uf->print_uf_array();

  cout << "2,3 connected? "<< uf->is_connected(2,3) << endl;
  cout << "2,9 connected? "<< uf->is_connected(2,9) << endl;

  uf->union_values(2, 3);
  cout << "2,3 connected? "<< uf->is_connected(2,3) << endl;
  cout << "2,9 connected? "<< uf->is_connected(2,9) << endl;

  uf->union_values(2, 9);
  cout << "2,3 connected? "<< uf->is_connected(2,3) << endl;
  cout << "2,9 connected? "<< uf->is_connected(2,9) << endl;

  uf->print_uf_array();

  cout <<endl<<endl;

  uf->union_values(1, 8);
  cout << "1,8 connected? "<< uf->is_connected(1,8) << endl;

  uf->union_values(1, 9);
  cout << "1,9 connected? "<< uf->is_connected(1,9) << endl;
  cout << "1,2 connected? "<< uf->is_connected(1,2) << endl;

  uf->print_uf_array();
}
