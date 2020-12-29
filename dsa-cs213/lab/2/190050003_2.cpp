#include <iostream>
#include <vector>
using namespace std;

int main(){
    int n, k;
    cin >> n >> k;

    vector<int> bag(k);
    
    for(int i = 0; i < k; i++){
        cin >> bag[i];
    }
    
    bool pass = 0;
    int i = 1;
    while(true){

        cout << i << ' ';
        int q = bag[i]/k;
        int r = bag[i]%k;
        
        bag[i] = 0;
        for(int j = 1; j <= k; j++)
            bag[(i+j)%k] += q;
        for(int j = 1; j <= r; j++)
            bag[(i+j)%k]++;

        if(i == k-1)
            pass = 1;
            
        i = i%(k-1) + 1;

        if(bag[i] == 0 && pass)
            break;

        //for(int j = 0; j < k; j++)
        //    cout << bag[j] << ' ';
        // cout << '\n';

    }
    cout << "0\n";
    return 0;
}
