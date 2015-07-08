#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int main()
{
    cout<<"Jeez I'd love to get this to work."<<endl;

    ifstream blah;
    string ss;
    vector<string> ugh;

    blah.open("sudokugood1.txt");
    if (blah.is_open()) {

    while(!blah.eof()){

    getline(blah,ss);
    cout<<ss<<endl;


    }
        blah.close();
    }

    cout<<"way to go, buddy"<<endl;
    return 0;
}
