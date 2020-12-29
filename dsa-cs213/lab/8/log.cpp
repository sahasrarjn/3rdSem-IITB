#include<iostream>
using namespace std;

int logbase(int a, int b){
    int i=1, prod=1;
    if(b == 1) return 1;
    if(a == 1) return 0;
    while(prod*b < a){
        prod = b*prod;
        i++;
    }
    return i;
}

int main(){
    // for(int i=1; i<10; i++)
    cout << logbase(7,2) << endl; 
}