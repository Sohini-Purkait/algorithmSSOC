#include<iostream>
using namespace std;
int main(){
    cout<<"enter no of rows:";
    int n;
    cin>>n;
    int i=1;
    while(i<=n){
        int j=1;
        while(j<=n-i+1){
            
            cout<<j<<" ";
            
            j++;
        }
        j=1;
        while(j<=(i-1)*2){
            cout<<"*"<<" ";
            j++;

        }
        j=n-i+1;
        while(j>=1){
            cout<<j<<" ";
            j--;
        }
        i++;
        cout<<endl;

    }
    return 0;
}
