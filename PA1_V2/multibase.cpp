//Submitted by Nick Salvador
#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int pal;
    int num;
    int dig;
    vector<int> palin;
    int counter=0;;

    cout << "Enter the number to test for palindromicity: " << endl;
    cin >> pal;

    for (int i=2; i<=pal; i++) {

//putting digits of new base in a vector
        while(pal>0) {
            dig = pal%i;
            pal/=i;
            palin.push_back(dig);
        }

       int high=palin.size();
       int low=0;


//want to test for palindromicity by comparing values equidistant from the middle value
       while (low<=high) {

            if (*(palin.begin()+low)==*(palin.begin()+high)){
                counter=+1;
            }
            high--;
            low++;
       }

       if (counter == low-1) {

        cout << i << endl;
        }




        //for(int j=0; j<=(palin.size()/2); j++){

       //     if (*(palin.end()-j)==*(palin.begin()+j)) {
       //     counter+=1;
      //      }

     //   }

    }






    return 0;
}

