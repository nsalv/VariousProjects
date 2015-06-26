#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

int main()
{

ifstream queen;
ofstream sol;
string ss;
int valid=1, rowcounter=1, colcounter=1;
char c[8][8];

//open the input file
queen.open("attack.fen");
if(queen.is_open()){

    //open the file that the data will be read into
    sol.open("attack.sol");
    if(sol.is_open()){

        while(getline(queen,ss)){
        //read data to determine if line is a solution.
            if(ss.length()!=39){
            valid=0;}
            for(int i=0; i<=29; i++){
                if(ss.at(i)=="/"){
                    rowcounter++;
                    continue;
                }
                else if(ss.at(i)!="Q"){
                    for(int j=0; j<=stoi(ss.at(i),nullptr,10); j++){
                    c[rowcounter][j]="o";
                    colcounter++;
                    }
                }
                else if(ss[i]=="Q"){
                    c[rowcounter][colcounter+1]="x";
                    colcounter++;
                }

            }

        int place=7;
                //three loops to check for repeats row and column
        for (int h=1; h<=8; h++){
            for(int l=1; l<=8; l++){
                for (int z=place; z>=0; z--){
                    //checks each column for two of the same value
                        if(c[h][l]==c[h][l+z]){
                            //displays invalid if invalid parameter is met
                            valid=0;
                        }
                        //checks rows for two of the same value
                        if (c[h][l]==c[h+z][l]){
                            valid=0;
                        }

                }
                place-=1;
            }

        }





            if(valid){
                sol<<ss+" 8 queens solution ";
            }
        }


    }sol.close();
} queen.close();

//queen.open("attack.sol");
//if(queen.is_open()){
//while(getline(queen,ss)){
//cout<<ss<<endl;
//}
//}queen.close();


    return 0;
}
