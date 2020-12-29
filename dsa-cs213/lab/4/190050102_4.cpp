#include<bits/stdc++.h>
#include<unordered_map>
using namespace std;

bool isPrime(int n) 
{ 
    if (n <= 1) 
        return false; 
  
    for (int i = 2; i*i < n; i++) 
        if (n % i == 0) 
            return false; 
  
    return true; 
} 

int solve(string &s, int &k){
    int n = s.length();
    map <char, int> occur;
    int sum=0;
    
    for(int i=0; i<k; i++){
        occur.clear();
        map <char, int> :: iterator it;

        for(int j=i; j<n; j+=k){
            occur[s[j]]++;
        }

        int max_count=0;
        char res;
        for(it = occur.begin(); it!=occur.end(); it++){
            // cout << it->first << " " << it->second << endl;
            if(max_count < it->second){
                max_count = it->second;
                res = it->first;
            }
        }
        if(n%k == 0) sum += n/k - max_count;
        else sum += (n+k)/k - max_count;

        // cout << endl;

    }

    return sum;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string s;
    int k;
    
    cin >> s;
    cin >> k;
    
    int bs = s.length()/k;
    cout << solve(s, bs) << endl;

    int mini = 20000, res;
    int count = s.length();
    if(count > 1000) count = count / 100;
    for(int i=1; i<count; i++){
        int temp = solve(s, i);
        if(mini > temp){
            mini = temp;
            res = i;
        } 
    }   

    if(s.length() % res == 0){
        res = s.length()/res;
    }else{
        res = s.length()/res + 1;
    }
 
    cout << mini << " " << res << endl;
}
