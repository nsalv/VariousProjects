#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
//Finished Product.
using namespace std;


void check(vector<string>& line){
string temp,x;
stringstream convert;
vector<string> row;

    for (int i=0; i<line.size(); i++){
        int xwin=0, owin=0, blank=0, ex=0, oh=0,invalid=0;
        bool gameOver=0;
        temp = line[i];
        row.clear();

        //creates a vector where each entry is a different character from board
        for (int j=0; j<temp.size(); j++){
            stringstream convert;
            convert<<temp[j];
            convert>>x;
            row.push_back(x);
        }
        //begin logic for testing board situation
        //count number of occurances of each character

        for (int z=0; z<row.size(); z++){
            if (row[z]=="x"){
                ex++;}
            if (row[z]=="o"){
                oh++;}
            if (row[z]=="#"){
                blank++;}
        }

            //horizontal win
            for (int a=0; a<=6; a+=3){
                if (row[a]==row[a+1] && row[a]==row[a+2]){
                    if (row[0]=="o"){
                        owin++;
                    }
                    if (row[0]=="x"){
                        xwin++;
                    }
                }
            }
            //Vertical Win
            for (int b=0; b<=2; b++){
                if (row[b]==row[b+3] && row[b]==row[b+6]){
                    if (row[0]=="o"){
                        owin++;
                    }
                    if (row[0]=="x"){
                        xwin++;
                    }
                }
            }
            //Diagonal Win
            if (row[0]==row[4]&&row[0]==row[8]){
                if (row[0]=="o"){
                    owin++;
                }
                if (row[0]=="x"){
                    xwin++;
                }
            }
            if (row[2]==row[4]&&row[2]==row[6]){
                if (row[2]=="o"){
                    owin++;
                }
                if (row[2]=="x"){
                    xwin++;
                }
            }

            //check for too many wins
            if(xwin>1 || owin>1){
                if(gameOver==0){
                    invalid=1;
                    line[i] = line[i] + " i";
                    gameOver=1;
                }
            }
            if(xwin>=1 && owin>=1 && gameOver==0){
                invalid=1;
                line[i] = line[i] + " i";
                gameOver=1;
            }
            if (ex>oh+1 || ex<oh ){
                if(gameOver==0){
                    invalid=1;
                    line[i] = line[i] + " i";
                }
            }
            //log results
            if (!invalid){
                if(xwin){
                    line[i] = line[i] + " x";
                }
                if(owin){
                    line[i] = line[i] + " o";
                }
                if(xwin==0 && owin==0 && blank!=0){
                    line[i] = line[i] + " c";
                }
                if(xwin==0 && owin==0 && blank==0){
                    line[i] = line[i] + " t";
                }
            }

    }
ofstream store;
store.open("tttstatus.txt");
if(store.is_open()){
    for (int c=0; c<line.size(); c++){
        store<<line[c]<<endl;
    }
}store.close();

}




void output (){
    ifstream done;
    string out;
    done.open("tttstatus.txt");
    if (done.is_open()){

        while(!done.eof()){
        getline(done,out);
        cout<<out<<endl;
        }
    }done.close();

}

void readBoard(string board, vector<string>& line)
{
    ifstream tic;
    string ss;

    tic.open(board);
    if (tic.is_open())
    {
        while(!tic.eof())
        {
            getline(tic,ss);
            line.push_back(ss);

        }
        tic.close();
    }
}


int main()
{
    vector<string> line;
    string X="x", O="o", space="#";

    //confirmed that readBoard is working.
    readBoard("tictactoeboards.txt", line);

    check(line);
    //output();


    return 0;
}
