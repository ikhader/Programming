
#include <iostream>

using namespace std;

class base_pub_mem
{
  public:
    int base_class_mem;
    base_pub_mem():base_class_mem(20)
    {
    }
    void base_print_pub()
    {
      cout<<"Base print public: "<< base_class_mem<< endl;
    }
};


class derv_pub_mem: public base_pub_mem
{
  public:
  void set_base_class_mem(int v )
  {
    base_class_mem = v;
  }
  void print_base_pub_mem()
  {
      cout<<"derv print public: "<< base_class_mem<< endl;
  }
    
};

class base_pro
{
  protected:
   int base_pro_mem;

  public:
    base_pro():base_pro_mem(1000)
    {
    }
    void base_print_pro()
    {
      cout<<"Base print protected: "<< base_pro_mem<< endl;
    }
  
};

class derv_pro_mem: public base_pro
//class derv_pro_mem: protected  base_pro
{
  public:
  void set_base_class_mem(int v )
  {
    base_pro_mem = v;
  }
  void derv_print_pro()
  {
    cout<<"deri print protected: "<< base_pro_mem<< endl;
  }
};
int main(int argc, char *argv[])
{
  derv_pub_mem dpm;

  dpm.base_print_pub();
  dpm.set_base_class_mem(99);
  dpm.base_print_pub();

  dpm.set_base_class_mem(11);
  dpm.print_base_pub_mem();
  cout<<"-------------------------------------"<<endl;

  derv_pro_mem dpro;
  dpro.base_print_pro();
  dpro.set_base_class_mem(777);
  dpro.base_print_pro();
  dpro.set_base_class_mem(888);
  dpro.base_print_pro();

  return 0;
}


