#include<iostream>
using namespace std;

int main(){
    int a , b;
    cout << "enter value of a" << endl;
    cin >> a;
    cout << "enter value of b" << endl;
    cin >> b;
    char op;
    cout << "enter the operation +,-,/,*,%" << endl;
    cin >> op;

    switch(op){
        case '+': cout<<(a+b) <<endl;
                  break;
        case '-': cout<<(a-b) <<endl;
                  break;
        case '/': cout<<(a/b) <<endl;
                  break;
        case '*': cout<<(a*b) <<endl;
                  break;
        case '%': cout<<(a%b) <<endl;
                  break; 
        default : cout << "please enter valid operation" << endl;                                                 
    }

    return 0;
}