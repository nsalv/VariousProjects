#include <iostream>
#include <fstream>

using namespace std;
//now need to fix logic and allow multiple boards to be passed through the functions at once
//reading too many wins and losses for one board.
//reading same board over and over

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
    string X="x", O="o", space="#";
    ofstream done;

    done.open("tttstatus.txt");
    if (done.is_open()){

    for (int z=0; z<9; z++){
        if (ss[z]==X[0]){
            x++;}
        if (ss[z]==O[0]){
            o++;}
        if (ss[z]==space[0]){
            blank++;}
    }

    if (x!=o && x!=o+1){
        valid=0;
        ss = ss + " i";
        done<<ss<<endl;
    }

    x=0;
    o=0;

    if (valid==1){
        for (int i=0; i<3; i++){
            for (int j=0; j<3; j++){
                //check for x in each column
                if (c[i][j]==X[0]){
                    x++;}
                //check for o in each column
                if (c[i][j]==O[0]){
                    o++;}
                //check for 3 x's
                if (x==3){
                    xwin=1;
                    ss = ss + " x";}
                //check for 3 o's
                if (o==3){
                    owin=1;
                    ss = ss + " o";}
            }
            //reset couner after it checks each row
            x=0;
            o=0;

            for (int k=0; k<3; k++){

                if (c[k][i]==X[0]){
                    x++;}
                if (c[k][i]==O[0]){
                    o++;}

                if (x==3){
                    xwin=1;
                    ss = ss + " x";
                    done<<ss<<endl;}
                if (o==3){
                    owin=1;
                    ss = ss + " o";
                    done<<ss<<endl;}
            }

        }

        x=0;
        o=0;
        //check diagonal
        for (int l=0; l<3; l++){
                if (c[1+l][1+l]==X[0]){
                    x++;}
                if (c[1+l][1+l]==O[0]){
                    o++;}

                if (x==3){
                    xwin=1;
                    ss = ss + " x";
                    done<<ss<<endl;}
                if (o==3){
                    owin=1;
                    ss = ss + " o";
                    done<<ss<<endl;}
            }

        //check diagonal
        for (int h=0; h<3; h++){
            if (c[2-h][2-h]==X[0]){
                    x++;}
            if (c[2-h][2-h]==O[0]){
                o++;}

            if (x==3){
                xwin=1;
                ss = ss + " x";
                done<<ss<<endl;}
            if (o==3){
                owin=1;
                ss = ss + " o";}
                done<<ss<<endl;
        }
    if (xwin==1 && owin==1){
        ss = ss + " i";
        done<<ss<<endl;}

    if (xwin==0 && owin==0 && blank!=0){
        ss = ss + " c";
        done<<ss<<endl;}

    if (xwin==0 && owin==0 && blank==0){
        ss = ss + " t";
        done<<ss<<endl;}

    }
    }done.close();
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
            //cout<<ss<<endl;

        }
        tic.close();
    }
    return ss;
}


int main()
{
    char c[3][3];
    string X="x", O="o", space="#";
    string temp;
    int valid=1;

    temp=readBoard("practice.txt");
    convert(temp,c);
    check(valid,temp,c);
    output();
    display(c);


    return 0;
}
