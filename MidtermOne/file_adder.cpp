#include <iostream>
#include <fstream>
#include <vector>

//seems to start reading files and summing numbers but freezes for some reason.

using namespace std;

//function that reads file names from foodsum_file.txt
vector<string> filereader (string fileName){
    string ss;
    vector<string> names;

    ifstream files;
    files.open(fileName);
    if (files.is_open()){
        while (!files.eof()){
            getline(files,ss);
            names.push_back(ss);
        }

    }files.close();


    return names;


}
//unused function. Attempted to determine the size of each file so that I could quickly read in each value to a vector.
vector<int> filesize(vector<string> names){
ifstream files;
int counter=0;
vector<int> sizes;

    for(int i=0; i<names.size();i++){

        files.open(names[i]);
        if (files.is_open()){

            while(!files.eof()){
            counter++;
            }
            sizes.push_back(counter);

        if(!files.is_open()){
            cout<<"not found"<<endl;
            sizes.push_back(0);
        }

    }files.close();

}
}

//main takes the file name, opens the file, and converts each line to numbers that are summed.
int main()
{
    vector<string> names;
    string ss;
    int count=0, counter=0;
    int sum=0, length=0;
    ifstream files;

    string fileName="foodsum_files.txt";
    names = filereader (fileName);
    //sizes = filesize(names);


    for(int i=0; i<names.size();i++){

        files.open(names[i]);
        if (files.is_open()){

            while(!files.eof()){
                getline(files,ss);
                length=ss.size();
            }
        }files.close();
        files.open(names[i]);
        if (files.is_open()){

            int nums[length];
            for(int l=0; l<length; l++){
                files>>nums[l];
            }
            for(int k=0; k<length; k++){
                sum+=nums[k];
            }
        }

        cout<<names[i]<<' '<<sum<<endl;
        }files.close();

        if(!files.is_open()){
            cout<<"not found"<<endl;
        }



    return 0;
}
