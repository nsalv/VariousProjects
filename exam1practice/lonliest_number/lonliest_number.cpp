// Your assignment is to find and print the "loneliest number"
// in an array of integers v

//  Vector           Loneliest Value
//  1,2,4             4
//  8,9,10            8 (could have been 9 or 10)
//  9,0,8,10          0
//  2,2,5,6,8,12,13   8

// The loneliest value of an array is the element of the array
// whose array-distance is greatest.
//
// The array-distance of an element v_i is defined as the
// minimum of distance(v_i,v_j) for i not equal to j.

// For example, if v was {4,9,5,6,13,14,5} then the
// loneliest number is 9 because its distance to any
// other number is at least 3.
// 4,6,13,14 have array-distance 1 and 5 has array-distance 0
//
// The distance between two numbers x and y is the Euclidean
// distance |x-y|
//
// In the case of ties, the loneliest value can be reported as any
// of the equally lonely numbers.
//
// NOTE: THIS PROGRAM REQUIRES THE FILE million_ints.txt
// to be in the same directory as the running program.

#include <iostream>
#include <fstream>

//Program compiles and I believe the code is correct but the two for loops through a million entries takes forever.

using namespace std;

const int SIZE=1000000;

int lone(int v[], int SIZE){
    int lonely = v[0];
    int temp=0;
    int distance=0;

//nested for loop to compare each numbers distance from the rest.
    for (int j=0; j<SIZE; j++){
        for (int l=0; l<SIZE; l++){

            temp=v[j]-v[l];

            if (temp<0){
                temp=temp*-1;
            }

            if (temp>distance){
                distance=temp;
                lonely = v[j];
            }


        }

    }
    return lonely;
}

int main(){

    int v[SIZE];
    ifstream millints("million_ints.txt");
    for (int i=0;i<SIZE;i++){
        millints >> v[i];
        if (millints.fail()){
            cout << "data file not found. reread instructions." << endl;
            return 1;
        }


    int lonely = lone(v, SIZE);
    cout<<v[lonely]<<endl;
    // Add your code here, or use a function if you want.


}
	return 0;
}
