#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <string>

//need to be able to add more than one element to an output file line without overwriting.


using namespace std;

vector<string> firstWord (string fileName, string letters, int c, vector<string>& corrWords){

ifstream words;
ofstream output;
string ss, temp;
vector<string> remLetters;


int counter=0;

words.open(fileName);
if (words.is_open()){

    while(!words.eof()){
        getline(words,ss);

        //checks for first word
        if (ss.size()==c){
            counter=0;
            temp = letters;

            for (int i=0; i<ss.size(); i++){

                for (int j=0; j<temp.size(); j++){
                    if (ss[i]==temp[j]){
                        //prevents repeat matching
                        temp.erase(temp.begin()+j);
                        counter++;
                    }

                    if (counter==c-1){
                        corrWords.push_back(ss);
                        counter=0;
                        remLetters.push_back(temp);

                    }
                }
            }

}
}words.close();

}

return remLetters;
}

void secondWord(string fileName, vector<string> remLetters, vector<string>& corrWords){

ifstream words;
ofstream output;
string letters1, ss, ss1;
vector<string> out, out1;
string temp, temp1;

int calc, counter;
calc=remLetters[0].size();

output.open("match.txt");

for (int z=0; z<remLetters.size(); z++) {


        words.open(fileName);
        if (words.is_open()) {
        while(!words.eof()){
        getline(words,ss);

        //checks for second word
        if (ss.size()==calc){
            counter=0;
            letters1 = remLetters[z];

            for (int i=0; i<ss.size(); i++){

                for (int j=0; j<letters1.size(); j++){
                    if (ss[i]==letters1[j]){
                        //prevents repeat matching
                        letters1.erase(letters1.begin()+j);
                        counter++;
                    }

                    if (counter==calc-1){
                        out.push_back(ss);
                        out1.push_back(corrWords[z]);
                        output<<ss+" "+corrWords[z]<<endl;
                        counter=0;
                    }
                }
            }

}


}
} words.close();

}output.close();

//should display both words seperately but for some reason they overlap.
for (int g=0; g<out.size(); g++){
    cout<<out1[g]+" "+out[g]<<endl;
}



}


void display (string fileOutName){
    ifstream output;
    string ss;

    output.open(fileOutName);
    if (output.is_open()){

        while (!output.eof()){
            getline(output,ss);
            cout<<ss<<endl;
        }
    }output.close();

}

int main(int argc, char const *argv[])
{
    string fileOutName = "match.txt";
    vector<string> remLetters;
    vector<string> corrWords;


if (argc < 2){

string letters="aadekmmnortww";
int c=8;
string fileName = "enable1.txt";

    remLetters = firstWord(fileName, letters, c, corrWords);
    secondWord(fileName, remLetters, corrWords);
    //display(fileOutName);
}


if (argc==4){

string fileName = argv[0];
string letters=argv[1];
string b=argv[2];
int c=stoi(b,nullptr,10);


    remLetters = firstWord(fileName, letters, c, corrWords);
    secondWord(fileName, remLetters, corrWords);
    //display(fileOutName);

}





    return 0;
}
