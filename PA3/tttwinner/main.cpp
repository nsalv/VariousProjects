#include <iostream>
#include <fstream>

using namespace std;
//need help pointing to locations within the string and matrix
//How can I send each individual line through my functions

void convert(string ss,char c[3][3]){

        for (int i=0;i<=2;i++){

            c[0][i]=ss[i];
            c[1][i]=ss[i+3];
            c[2][i]=ss[i+6];

        }

}
void check(int valid, string ss, char c[3][3]){
    int x=0, o=0, blank=0;
    int xwin=0, owin=0;

    for (int z=0; z<9; z++){
        if (ss[*z]=="x"){
            x++;}
        if (ss[z]=="o"){
            o++;}
        if (ss[z]=="#"){
            blank++;}
    }

    if (x!=o && x!=o+1){
        valid=0;
        ss = ss + " i";
    }

    x=0;
    o=0;

    if (valid==1){
        for (int i=0; i<3; i++){
            for (int j=0; j<3; j++){
                //check for x in each column
                if (c[i][j]=="x"){
                    x++;}
                //check for o in each column
                if (c[i][j]=="o"){
                    o++;}
                //check for 3 x's in a row
                if (x==3){
                    xwin=1;
                    ss = ss + " x";}
                //check for 3 o's in a row
                if (o==3){
                    owin=1;
                    ss = ss + " o";}
            }
            //reset couner after it checks each row
            x=0;
            o=0;

            for (int k=0; k<3; k++){

                if (c[k][i]=="x"){
                    x++;}
                if (c[k][i]=="o"){
                    o++;}

                if (x==3){
                    xwin=1;
                    ss = ss + " x";}
                if (o==3){
                    owin=1;
                    ss = ss + " o";}
            }

        }

        x=0;
        o=0;
        //check diagonal
        for (int l=0; l<3; l++){
                if (c[1+l][1+l]=="x"){
                    x++;}
                if (c[1+l][1+l]=="o"){
                    o++;}

                if (x==3){
                    xwin=1;
                    ss = ss + " x";}
                if (o==3){
                    owin=1;
                    ss = ss + " o";}
            }

        //check diagonal
        for (int h=0; h<3; h++){
            if (c[2-h][2-h]=="x"){
                    x++;}
            if (c[2-h][2-h]=="o"){
                o++;}

            if (x==3){
                xwin=1;
                ss = ss + " x";}
            if (o==3){
                owin=1;
                ss = ss + " o";}
        }
    if (xwin==1 && owin==1){
        ss = ss + " i";}

    if (xwin==0 && owin==0 && blank!=0){
        ss = ss + " c";}

    if (xwin==0 && owin==0 && blank==0){
        ss = ss + " t";}

    }
}

void output (string ss){
    ofstream done;
    done.open("tttstatus.txt");
    if (done.is_open){

        done << ss;
    }
    done.close();

}

void display(char c[3][3]){
    for (int j=0; j<3; j++){
                cout<<c[j][0]<<c[j][1]<<c[j][2]<<endl;
            }
        }

string readBoard(string board)
{
    ifstream tic;
    string ss;

    tic.open(board);
    if (tic.is_open())
    {
        while(!tic.eof())
        {
            getline(tic,ss);
            cout<<ss<<endl;

        }
        tic.close();
    }
    return ss;
}


int main()
{
    char c[3][3];
    string temp;
    int valid=1;

    temp=readBoard("practice.txt");
    convert(temp,c);
    check(valid,temp,c);
    output(temp);
    display(c);


    return 0;
}
