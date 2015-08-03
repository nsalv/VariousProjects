//Submitted by Nick Salvador
#include <iostream>

using namespace std;

int divisorsum()
{

   for (int i=2; i<1001; i++){
        int divsum =0;
        for (int j=1; j<1001; j++){

            if (i%j==0 && i!=j && i>j){
            divsum+=j;
            }

        }
    cout << divsum << endl;

   }
    return 0;
}

