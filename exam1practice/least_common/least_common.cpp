//
// Write a function to find the
//   least common values in the array v
//
// Examples:

// Array                 Least Common Values
// {7,4,4,7,8,8,8}       {4,7}
// {3,1,5,3}             {1,5}
// {4,5,6,5,6}           {4}
// {3,3,3,5,5,5,6,6,6,6} {3,5}

// Write the function get_least_common_array()
//  OR the function get_least_common_vector()
//
// These functions return all the least common values
// in an array or a vector.

// NOTE: THIS PROGRAM REQUIRES THE FILE million_common.txt
// to be in the same directory.

#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
// You can include additional libraries here.



using namespace std;

const int SIZE=1000000;


// VECTOR people: finish this function

vector<unsigned int> get_least_common_vector(
	unsigned int * v,int const vsize){

sort(v,v+1000000);
int length=0;
int counter=0;
vector<int> loc;

for (int i=1; i<vsize; i++){

        if (v[i]==v[i-1]){
            counter++;
        }
        if (v[i]!=v[i-1]){
            if (counter>length){
                length=counter;
                loc.push_back(i-1);
                }
            counter=0;
        }

}
    vector<unsigned int> l;
    int temp=0, temp1=0;
    for (int j=0; j<loc.size(); j++){
        temp=loc[j];
        temp1=v[temp];
        l.push_back(temp1);
    }
    return l;
}


// ARRAY people: finish this function.
unsigned int * get_least_common_array(
	 unsigned int const * const v,
	 int const vsize,
	 int & lsize){

    //replace these lines with your code
    unsigned int * p=new unsigned int[2];
    p[0]=1;
    p[1]=4;
    lsize=2;


    return p;
}


// Do Not Change anything in main()

int main(){

    unsigned int v[SIZE];
    ifstream millints("million_common.txt");
    for (int i=0;i<SIZE;i++) {
    	millints >> v[i];
    	if (millints.fail()){
    		cout << "data file not found. reread instructions." << endl;
    		return 1;
    	}
    }

     vector<unsigned int> least_commons_v;
     least_commons_v =get_least_common_vector(v,SIZE);

     for (auto l: least_commons_v){
     	cout << l << endl;
     }

    unsigned int * least_commons_a;
    int least_size;
    least_commons_a=get_least_common_array(v,SIZE,least_size);
    for (int i=0;i<least_size;i++){
    	cout << least_commons_a[i] << endl;
    }

    delete[] least_commons_a;
	return 0;
}
