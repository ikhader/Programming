#include <iostream>
using namespace std;

class Base 
{
public:
    virtual void show() { cout<<" In Base \n"; }
    void overload_show() { cout<<" In Base overload show \n"; }
    Base(){ cout<<"Base constructor \n"; }
    virtual ~Base(){cout<<"Base Destructor \n";}
};

class Derived: public Base
 {
public:
    void show() { cout<<"In Derived \n"; }
    void overload_show() { cout<<" In DERV overload show \n"; }
    Derived(){ cout<<"Derived constructor \n"; }
    ~Derived(){ cout<<"Derived Destructor \n"; }
};


int main()
{
  cout<<"creating base *p = new base:" <<endl;
  Base *p1 = new Base();
  p1->show();
  p1->overload_show();
  delete p1;
  
  
  cout <<"------------------------------------ \n";
  cout<<"creating base *p = new derv:" <<endl;
  Base *p2 = new Derived();
  p2->show();
  p2->overload_show();
  delete p2;
  
  cout <<"------------------------------------ \n";
  cout<<"creating derv *p = new derv:" <<endl;
  Derived *p3 = new Derived();
  p3->show();
  p3->overload_show();
  delete p3;
  
  //Derived *p4 = new Base(); --> will not compile: Invalid conversion
  
return 0;
}

/*
expected output
With NO "virtual" keyword in base class:
################################################

creating base *p = new base:
Base constructor 
 In Base 
 In Base overload show 
Base Destructor 
------------------------------------ 
creating base *p = new derv:
Base constructor 
Derived constructor 
In Derived 
 In Base overload show 
Base Destructor 
------------------------------------ 
creating derv *p = new derv:
Base constructor 
Derived constructor 
In Derived 
 In DERV overload show 
Derived Destructor 
Base Destructor 
###########################################################

With VIRTUAL destructor:
creating base *p = new base:
Base constructor 
 In Base 
 In Base overload show 
Base Destructor 
------------------------------------ 
creating base *p = new derv:
Base constructor 
Derived constructor 
In Derived 
 In Base overload show 
Derived Destructor 
Base Destructor 
------------------------------------ 
creating derv *p = new derv:
Base constructor 
Derived constructor 
In Derived 
 In DERV overload show 
Derived Destructor 
Base Destructor 
*/
