//checks for second word
        if (ss.size()==calc){
            counter=0;

            for (int i=0; i<ss.size(); i++){

                for (int j=0; j<letters.size(); j++){
                    if (ss[i]==letters[j]){
                        letters.erase(letters.begin()+j);
                        counter++;
                    }
                    if (counter==calc){
                        if (sol.size()!=0){
                        sol = sol + " " + ss;
                        if (sol.size()==letters.size()){
                            cout<<sol<<endl;
                            sol="";}
                        }
                        if (sol.size()==0){
                        sol= ss;
                            if (sol.size()==letters.size()){
                            cout<<sol<<endl;
                            sol="";}
                            }
                    }
                }
            }
        }


        }




        if (sol.size()==letters.size() + 1){
        cout<<sol<<endl;
        sol="";}





    }

}
words.close();
