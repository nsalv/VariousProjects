#include <iostream>

using namespace std;

int increment(int n)
{
    n++;
    cout<<"The increment of n is "<<n<<endl;
}


int main()
{
    int n=1;
    increment(n);
    return 0;
}
