#include<iostream>
using namespace std;

//how many 100rs , 50rs, 20rs, 1rs present in an amount?

int main(){
    int amt;
    cout<<"enter the amount"<<endl;
    cin>>amt;
    int hunderdRs , fiftyRs , twentyRs , oneRs  ;
    switch(1){
        case 1 : hunderdRs=(amt/100);
                 amt=(amt%100);
                 cout << "total 100 rs notes are:" <<hunderdRs<<endl;

        case 2 : fiftyRs=(amt/50);
                 amt=(amt%50);
                 cout << "total 50 rs notes are:" <<fiftyRs<<endl;

        case 3 : twentyRs=(amt/20);
                 amt=(amt%20);
                 cout << "total 20 rs notes are:" <<twentyRs<<endl;

        case 4 : oneRs=(amt/1);
                 amt=(amt%1);
                 cout << "total 1 rs notes are:" <<oneRs<<endl;       
    }
    
    return 0;
}