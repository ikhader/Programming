#include<iostream>
using namespace std;

class Point {
public:
    Point() { cout << "Normal Constructor called\n"; }
    Point(const Point &t) { cout << "Copy constructor called\n"; }
    Point& operator = (const Point &t){cout<<"Assignment operator called \n";}
};

int main()
{
   Point *t1, *t2;
   t1 = new Point();
   t2 = new Point(*t1);
   Point t3 = *t1;
   Point t4;
   t4 = t3;
   return 0;
}

/*
Output:
Normal Constructor called
Copy constructor called
Copy constructor called
Normal Constructor called
Assignment operator called 
*/
