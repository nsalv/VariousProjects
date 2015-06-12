//Submitted by Nick Salvador
#include <iostream>
#include <vector>

using namespace std;

int main()
{
int num;
int sum;
int counter=0;
vector<int> happy;

for (int i=0; i=1000000; i++) {
    num=i;
    int success = 1;
    counter=0;

    do{
        //loop used to square digits of number
        while(num>0) {
            sum += num%10 * num%10;
            num/=10;
            }
    //resetting loop to square digits of new sum
        if (sum!=1) {
            num=sum;
            }

        else if (sum==1) {
        happy.push_back(i);
        }

//break when 100,000 happy numbers are found.
        if (happy.size()==100000)
        {break;}
//break do/while loop if it is run through 100 times.
        counter++;
        if (counter==100) {
        sum=1;
        }


        }while(sum!=1);
}

for (int j=1; j<100000; j+=10){
    cout << happy[j] << happy[j+1] << happy[j+2] << happy[j+3] << happy[j+4] <<
    happy[j+5] << happy[j+6] << happy[j+7] << happy[j+8] << happy[j+9]<< endl;


}






    return 0;
}

