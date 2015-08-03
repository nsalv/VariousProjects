//submitted by Nick Salvador
#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    int num, bin, sum, test;
    int result = 1;
    int counter = 0;

    cin >> num;
    cin >> bin;
    test = bin;
    int convert=bin;

    if (num < 0) {
        cout << "Number must be postive." << endl;
    }

    if (bin < 0) {
        cout << "Sequence must be positive" << endl;
    }

//testing to ensure that sequence is binary
    while (test>0) {
            if (test%10==2) {
            result = 0;
            }
            test/=10;
    }



    if (result==1)
    {
//converting binary to base 10.
        while (convert>0) {
            if (convert%10 != 0) {
                sum += pow(2,counter);
            }
            convert/=10;
            counter+=1;
        }
//determing if number is divisible by sequence.
        if (num%sum==0) {
            cout << "Sequence " << bin << " occurs in " << num << "." <<endl;
        }
        else {
        cout << "Sequence " << bin << " does not occur in " << num <<"." << endl;
        }
    }
    else{
    cout << "Sequence must be binary" << endl;
    }


    return 0;
}

