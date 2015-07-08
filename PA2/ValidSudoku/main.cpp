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

else{blah.open(argv[1]);}



if (blah.is_open()){
  while (!blah.eof())
  {
        getline(blah,ss);
        cout<<ss<<endl;
        for(int a=0;a<10; a++){

            c[b][a]=ss[a];
        }
        b+=1;

  }


    int place=8;
    //two loops to itereate through every value of every row and column
        for (int i=0; i<9; i++){
            for(int j=0; j<9; j++){
                for (int z=place; z>=1; z--){
                    //checks each column and row for two of the same value
                        if(c[i][j]==c[i][j+z] || c[j][i]==c[j+z][i]){
                        valid=0;
                        cout<<"!"<<endl;
                        }
                }
                place-=1;
            }

        }

        //check for same 2 values in a box
        for (int box=0; box<=6; box+=3){
        for (int k=0; k<=2; k++){
            for (int g=0; g<=2; g++){
                for (int l=2; l<=1; l--){
                    if (c[k+box][g+box]==c[k+l+box][g+box]) {
                        valid=0;
                        cout<<"?"<<endl;
                    }

                    if (c[k+box][g+box]==c[k+box][g+l+box]) {
                        valid=0;
                        cout<<"?"<<endl;
                    }

                     if (c[k+box][g+box]==c[k+l+box][g+l+box]) {
                        valid=0;
                        cout<<"?"<<endl;
                    }
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
