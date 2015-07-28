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
// You can include additional libraries here.



using namespace std;

const int SIZE=1000000;


// VECTOR people: finish this function

vector<unsigned int> get_least_common_vector(
	unsigned int const * const v,int const vsize){

vector<int> count (9,0);

  for (int i=0; i<vsize; i++){

    if (v[i]==1){
        count[0]++;}
    if (v[i]==2){
        count[1]++;}
    if (v[i]==3){
        count[2]++;}
    if (v[i]==4){
        count[3]++;}
    if (v[i]==5){
        count[4]++;}
    if (v[i]==6){
        count[5]++;}
    if (v[i]==7){
        count[6]++;}
    if (v[i]==8){
        count[7]++;}
    if (v[i]==9){
        count[8]++;}

  }

vector<int> low;
int least=count[0];
low.push_back(0);

  for (int k=1; k<count.size(); k++){

    if (count[k]==least){
        low.push_back(k);
    }

    if (count[k]<least){
        least=count[k];
        low.clear();
        low.push_back(k);

    }

  }
vector<int> nums= {1,2,3,4,5,6,7,8,9};
vector<unsigned int> l;
int temp=0;

for (int j=0; j<low.size(); j++){

    temp=low[j];
    l.push_back(nums[temp]);

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
