#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
//finished product.
using namespace std;

int main()
{
int x, qcounter=0;
ifstream queen;
ofstream sol;
string ss;
string Q="Q", slash="/";
vector<int> rows;
int valid=1;


//open the input file
queen.open("attack.fen");
if(queen.is_open()){

    //open the file that the data will be read into
    sol.open("attack.sol");
    if(sol.is_open()){

        while(getline(queen,ss)){
        valid=1;
        //read data to determine if line is a solution.
            if(ss.length()!=39){
            valid=0;}

            stringstream loc;
            loc << ss[0];
            loc >> x;
            rows.push_back(x);
            for(int i=0; i<=29; i++){
            if(ss[i]==slash[0]){
                for(int z=0; z<4; z++){
                    if(ss[i+z]==Q[0]){
                        qcounter++;
                    }
                    if (qcounter>1){
                        valid=0;
                        cout<<"too many queens in a row."<<endl;
                    }
                }
                qcounter=0;

                if(ss[i+1]!=Q[0]){
                    stringstream loc;
                    loc << ss[i+1];
                    loc>>x;
                    rows.push_back(x);
                }
                else if(ss[i+1]==Q[0]){
                    rows.push_back(0);
                }
            }
   //logic for determining solutions
            for (int j=0; j<rows.size(); j++){
                for (int l=0; l<rows.size(); l++){
                    if(rows[j]==rows[l] && j!=l){
                        valid=0;
                        cout<<"in the same column"<<endl;
                    }
                    if(j!=l){
                        if(rows[j]==rows[l] + abs(j-l) || rows[j]==rows[l] - abs(j-l)){
                            valid=0;
                        }
                    }
                }
            }


            }

            rows.clear();
            if(valid){
                sol<<ss+" 8 queens solution"<<endl;
            }
            else if (!valid){
                sol<<ss<<endl;
            }
        }


    }sol.close();
} queen.close();

//reads from solutions file
//queen.open("attack.sol");
//if(queen.is_open()){
//while(getline(queen,ss)){
//cout<<ss<<endl;
//}
//}queen.close();


    return 0;

}
