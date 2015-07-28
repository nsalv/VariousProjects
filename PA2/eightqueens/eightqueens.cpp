#include <iostream>
#include <fstream>
#include <vector>
#include <string>

//Can't get the code to get along, stoi function is throwing an error and preventing the program from running
//Haven't even been able to test the logic yet...

using namespace std;

int main()
{

ifstream queen;
ofstream sol;
string ss, temp;
string Q="Q", slash="/";

int valid=1, rowcounter=0, colcounter=0, space;
char *c[8][8];


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

                if(ss[i]==slash[0]){
                    rowcounter++;
                    continue;
                }
                else if(ss[i]!=Q[0] && ss[i]!=slash[0]){

                    temp=ss[i];
                    space=stoi(temp,nullptr,10);

                    for(int j=0; j<=space; j++){
                    c[rowcounter][colcounter]="o";
                    colcounter++;
                    }
                }
                else if(ss[i]==Q[0]){
                    c[rowcounter][colcounter+1]="x";
                    colcounter++;
                }

            }

        int place=7;
                //three loops to check for repeats row and column
        for (int h=0; h<=7; h++){
            for(int l=1; l<=8; l++){
                for (int z=place; z>=0; z--){
                    //checks each column for two of the same value
                        if(c[h][l]==c[h][l+z] || c[h][l]==c[h+z][l]){
                            //displays invalid if invalid parameter is met
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
