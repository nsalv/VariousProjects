//Submitted by Nick Salvador
#include <iostream>

using namespace std;

int main()
{
int y=1;
    while(y)
        {
        cout<<"Enter a number to test for perfectness"<<endl;
        int x;
        int divsum =0;
        cin >> x;


        for (int i=1; i<x; i++){

            if (x%i==0 && x!=i && x>i)
                {
                divsum+=i;
                }

                }

            if (cin.eof())
            {
            cout << "Goodbye" << endl;
            y=0;
            break;
            }

            if (x==0)
            {
            cout << "Goodbye" << endl;
            y=0;
            break;
            }


            if(divsum==x)
                {
                cout << x << " is perfect" << endl;
                }
            else if (divsum!=x)
                {
                cout<< x << " is not perfect" << endl;
                }



            }

    return 0;
}


