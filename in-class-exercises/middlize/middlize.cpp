// Functions middlize and themiddle
#include <iostream>
using namespace std;

// write a function middlize(x,y,z) which changes x, y, and z
// to be the "middle value"
// for example, if x=5,y=12,z=3, then middlize(x,y,z)
// will set them all to 5.
// x y and z are all int

//your block below here
void middlize(int& x, int& y, int& z){

    if (x<y && x>z){
        y=x;
        z=x;
    }
    if (x>y && x<z){
        y=x;
        z=x;
    }
    if(y>x && y<z){
        x=y;
        z=y;
    }
    if (y>z && y<x){
        x=y;
        z=y;
    }
    if(z>x && z<y){
        y=z;
        x=z;
    }
    if (z<x && z>y){
        y=z;
        x=z;
    }

}
//your block above here


// write a function themiddle(x,y,z) which returns
// the middle value, but does not change x, y, or z
// for example, if x=5,y=12,z=3, then themiddle(x,y,z) is 5
// and will not change x, y, or z.
//
// x y and z are all int
//your block below here
//...
int themiddle(int x, int y, int z){

if (x<y && x>z){
        return x;
    }
    if (x>y && x<z){
        return x;
    }
    if(y>x && y<z){
        return y;
    }
    if (y>z && y<x){
        return y;
    }
    if(z>x && z<y){
        return z;
    }
    if (z<x && z>y){
        return z;
    }



}

//your block above here

// Difficult/Optional problem.
// make a template version of themiddle and middlize
// that will middlize and themiddle any type.

//your block below here
//...
//your block above here



int main()
{
  cout << "themiddle testing" << endl;
  int a1(3),a2(5),a3(0);
  cout << "orig " << a1 << " " << a2 << " " << a3 << endl;
  cout << "themiddle is " << themiddle(a1,a2,a3) << endl;
  cout << "now  " << a1 << " " << a2 << " " << a3 << endl;

  cout << "middlize/themiddle testing" << endl;
  int a,b,c;

  while (cin >> a >> b >> c)
  {
   cout << "orig1 " << a << " " << b << " " << c << endl;
   cout << "the middle is " << themiddle(a,b,c) << endl;
   cout << "orig2 " << a << " " << b << " " << c << endl;

   middlize(a,b,c);
   cout << "now   " << a << " " << b << " " << c << endl;

   }

   //optional test code
   //string m("bac"),n("weq"),o("ad");
   //cout << "orig1 " << m+" "+n+" "+o << endl;
   //cout << themiddle(m,n,o) << endl;
   //cout << "orig2 " << m+" "+n+" "+o << endl;
   //middlize(o,m,n);
   //cout << "now   " << m+" "+n+" "+o << endl;


}
