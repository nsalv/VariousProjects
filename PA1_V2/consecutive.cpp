//Submitted by Nick Salvador
#include <iostream>
#include <vector>

using namespace std;

int main()
{

int counter=2;
int y=1;
int input;
int num;
int store, store1;

cout << "Enter the number of consecutive numbers you wish to find." << endl;
cin >> input;

cout << "Enter the sequence of numbers you want to test." << endl;
cin >> store;
cin >> store1;




//make sure input is vaid.
if (input<1) {
cout << "Error. Invalid input." << endl;
}

//ensures a sequence is entered.

do
{

//determine if a consecutive sequence is resent.
if (store1==store + 1) {

    counter+=1;
    store = store1;
    cin>> store1;

}

else if (store1 != store+1) {
    counter = 2;
    store = store1;
    cin>> store1;
}

if (counter==input) {
    cout << "Sequence found: ";

    for (int j=0; j<input; j++)
    {
        cout << ((store1-input+1)+j) << " ";
    }

    }



} while (counter!=input);

return 0;
}

