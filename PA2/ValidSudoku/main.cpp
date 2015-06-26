#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>

using namespace std;

int main(int argc, const char *argv[])
{


//read in file to matrix c
ifstream blah;
string ss;

char c[9][9];
int b=0, counter=1, valid=1;

if (argc < 2) {
blah.open("sudokuboard.txt");
}

else{blah.open(argv);}



if (blah.is_open()){
  while (!blah.eof())
  {
        getline(argv,ss);
        for(int a=0;a<10; a++){
            c[b][a]=ss(a);
        }
        b+=1;
  }





    int place=9;
    //two loops to itereate through every value of every row and column
        for (int i=1; i<10; i++){
            for(int j=1; j<10; j++){
                for (int z=place; z>=0; z--){
                    //checks each column for two of the same value
                        if(c[i][j]==c[i][j+z]){
                        //displays invalid if invalid parameter is met
                        cout<<"invalid."<<endl;
                        valid=0;
                        }
                        else {
                        //checks rows for two of the same value
                            if (c[j][i]==c[j+z][i]){
                                cout<<"invalid."<<endl;
                                valid=0;
                            }
                        }
                }
                place-=1;
            }

        }

        //check for same 2 values in a box
        for (int k=1; k<=6; k++){
            for (int g=1; g<=6; g++) {
                for (int l=1; l<=3; l++) {
                     if (c[k][g]==c[k+l][g+l]) {
                        cout<<"invalid."<<endl;
                        valid=0;
                        }
                }
            }
        }


}
blah.close();

        if(valid) {
        cout<< "valid." <<endl;
        }


else{
cout<<"invalid."<<endl;
}

        return 0;
}
