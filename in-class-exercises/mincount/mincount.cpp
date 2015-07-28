#include <iostream>

using namespace std;

// Write a function mincount() and a program main() to test that it works.

// Calculate the smallest value in the array list, size SIZE.
// Return the smallest value in smallest, and the number of occurences in smallcount
// If the array is empty, do not change either smallest or smallcount



// your code here

void mincount(const int * const list,const int SIZE,int& smallest,int& smallcount) {

int temp=0;
smallcount=1;

if (SIZE>0){
temp=list[0];
	for (int i=1; i<SIZE; i++){

        if(list[i]==temp){
            smallcount++;
        }

        if(list[i]<temp){
            temp=list[i];
            smallcount=1;
        }

	}
	smallest=temp;
}
}

int main(){

 int list[14]={-1,3,-2,5,3,6,-2,7,1,2,1,3,1,1};
 int SIZE=sizeof(list);
 int smallest, smallcount;

 mincount (list,SIZE,smallest,smallcount);
 cout<<"The smallest number was "<<smallest<<" and the number of times it occured was "<<smallcount<<"."<<endl;

}
