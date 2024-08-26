#include<iostream>
using namespace std;

int main(){

    cout<<"--------Calculator-----------"<<endl;;
    double a;
    cout<<"Enter the first number: ";
    cin>>a;

    double b;
    cout<<"Enter the second number: ";
    cin>>b;
    
    cout<<endl;

    cout<<"1. For Division -> /"<<endl;
    cout<<"2. For Multiplication -> *"<<endl;
    cout<<"3. For Addition -> +"<<endl;
    cout<<"4. For Subtraction -> -"<<endl;
    
    cout<<endl;
    
    char choice;
    cout<<"Enter the operator: ";
    cin>>choice;
    
    double result;
    switch(choice)
    {
        case '/':
        if(b!=0)
        {
            result = a/b;
            cout<<a<<"/"<<b<<" = "<<result<<endl;;
        }
        else
        {
            cout<<"Division is not possible"<<endl;
        }

        break;

        case '*':
        result = a*b;
        cout<<a<<"*"<<b<<" = "<<result<<endl;
        break;

        case '+':
        result = a + b;
        cout<<a<<"+"<<b<<" = "<<result<<endl;
        break;

        case '-':
        result = a - b;
        cout<<a<<"-"<<b<<" = "<<result<<endl;
        break;
    }

    return 0;
}