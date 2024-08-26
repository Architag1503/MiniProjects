#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main(){
    
    // it ensures that different random number generate every time
    srand(time(0));
    
    //Generate the number between 1 and 100;
    int random_num = rand() % 100 + 1;

    int gues_num;

    cout<<"Guess the number between 1 and 100"<<endl;
    do{

        cout<<"Guess the number: ";
        cin>>gues_num;

        if(gues_num < random_num)
        {
            cout<<"Guess number is too low. Try Agian!"<<endl;
        }
        else if(gues_num > random_num)
        {
            cout<<"Guess number is too high. Try Again!"<<endl;
        }
        else
        {
            cout<<"Congratulation! You guess the right number."<<endl;
        }
    }while(gues_num!=random_num);
    
    return 0;
}