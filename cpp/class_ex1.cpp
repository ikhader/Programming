#include <iostream>
using namespace std;

class Base 
{
public:
    virtual void show() { cout<<" In Base \n"; }
    void overload_show() { cout<<" In Base overload show \n"; }
    Base(){ cout<<"Base constructor \n"; }
};

class Derived: public Base
 {
public:
    void show() { cout<<"In Derived \n"; }
    void overload_show() { cout<<" In DERV overload show \n"; }
    Derived(){ cout<<"Derived constructor \n"; }
};


int main()
{
  cout<<"creating base *p = new base:" <<endl;
  Base *p1 = new Base();
  p1->show();
  p1->overload_show();
  
  cout <<"------------------------------------ \n";
  cout<<"creating base *p = new derv:" <<endl;
  Base *p2 = new Derived();
  p2->show();
  p2->overload_show();
  
  cout <<"------------------------------------ \n";
  cout<<"creating derv *p = new derv:" <<endl;
  Derived *p3 = new Derived();
  p3->show();
  p3->overload_show();
  
return 0;
}

/*
Expected output:
creating base *p = new base:
Base constructor 
 In Base 
 In Base overload show 
------------------------------------ 
creating base *p = new derv:
Base constructor 
Derived constructor 
In Derived 
 In Base overload show 
------------------------------------ 
creating derv *p = new derv:
Base constructor 
Derived constructor 
In Derived 
 In DERV overload show 
*/
