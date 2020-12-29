#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

bool sortSize(vector<int> &a, vector<int> &b){
	return a.size() > b.size();
}

class permutation{
    int n, *a;
    std::vector< std::vector<int> > c;


    void makeCycles(){
        bool *visited = new bool[n];
        for(int i=0; i<n; i++) visited[i] = false;

        for(int i=0; i<n; i++){
            if(!visited[i]){
                vector<int> temp;

                int j=a[i];
                temp.push_back(i);
                visited[i]=true;

                while(j!=i){
                    visited[j] = true;
                    temp.push_back(j);
                    j=a[j];
                }       
                for(int t=0; t<temp.size(); t++) cout << temp[t]  <<  "\t"; cout << endl;
                c.push_back(temp);
                temp.clear();
            }
        }
        delete []visited;

        sort(c.begin(), c.end(), sortSize);
        return;
    }

    int gcd(int a, int b) const {
        if(a == 0) return b;
        return gcd(b%a, a);
    }

    int lcm(int a, int b) const {
        return (a*b)/gcd(a, b);
    }


public:
    // Constructors and Destructors
    // Working
    permutation(int m, int in[]){
        n = m;
        a = new int [n];
        for(int i=0; i<n; i++) a[i] = in[i];
        makeCycles();
    };

    // Working
    permutation(permutation const &q){
        n = q.n;
        a = new int [n];

        for(int i=0; i<n; i++){
            a[i] = q.a[i];
        }
        makeCycles();
    }

    // Not Working
    permutation const & operator=(permutation const &q){
        if(&q ==  this) return *this;
        delete []a;

        permutation ans(q);
        return q;
    }
    
    ~permutation(){
        delete []a;
        c.clear();
    }

    // Public functions
    
    int size() const{
        int size = n;
        return size;
    }


    int* to_array() const{
        int *q = new int[n];
        for(int i=0; i<n; i++){
            q[i] = a[i];
        }
        
        return q;
    }

    permutation const operator-() const{
        permutation *q = new permutation(*this);
        q->n = n;
        for(int i=0; i<n; i++) q->a[a[i]] = i;
        return *q;
    }

    permutation const operator*(permutation const &in) const{
        int *arr = new int[n];
        for(int i=0; i<n; i++) arr[i] = a[in.a[i]];
        permutation *temp = new permutation(n, arr);
        return *temp;
    }

    permutation const square_root() const{
        if(n==1){
            permutation finalPerm(1, a);
            return finalPerm;
        }

        vector<int> ans;
        // int finalAns[n];
        int *finalAns = new int[n];

        for(int i=0; i<c.size(); i++){
            
            if(c[i].size()==c[i+1].size() && i!=c.size()-1){
                for(int j=0; j<c[i].size(); j++){
                    ans.push_back(c[i][j]);
                    ans.push_back(c[i+1][j]);
                }
                i++;
            }
            else if(c[i].size()%2==0){
                // cout << "-1\n";
                int iden[n];
                for(int i=0; i<n; i++){
                    iden[i] = i;
                }
                permutation finalPerm(n,iden);
                return finalPerm;
            }else{
                vector<int> temp(c[i].size());

                int t=0;
                for(int j=0; j<c[i].size(); j++){
                    temp[t] = c[i][j];
                    t+=2;
                    if(t>=c[i].size()) t=1;
                }
                for(int i=0; i<temp.size(); i++){
                    ans.push_back(temp[i]);
                }
                temp.clear();
            }

            for(int t=0; t<ans.size()-1; t++){
                finalAns[ans[t]] = ans[t+1];
            }
            finalAns[ans[ans.size()-1]] = ans[0];
            
            ans.clear();
        }

        permutation finalPerm(n, finalAns);
        delete []finalAns;

        return finalPerm;
    }
    
    permutation const operator^(long long pwr) const{
        permutation *q = new permutation(*this);
        q->n = n;
        
        // bool visited[n];
        bool *visited = new bool[n];
        for(int i=0; i<n; i++) visited[i] = false;

        for(int i=0; i<n; i++){
            if(visited[i] == true) continue;

            int l=1, c=i;
            visited[c] = true;
            c = a[c];
            while(c != i){
                visited[c] = true;
                c = a[c];
                l++;
            }

            int m = pwr%l;
            int pk = i;

            for(int j=0; j<m; j++){
                pk = a[pk];
            }

            c = i;
            q->a[i] = pk;
            c = a[c];
            int b = pk;
            while(c != i){
                b = a[b];
                q->a[c] = b;
                c = a[c];
            }
        }

        return *q;
    }

    bool is_power(permutation const &q) const{
        int diff = 0;
        vector <int> rem;
        vector <int> len;


        int pi=0;
        for(int i=0; i<q.c.size(); i++){
            // for(int j=0; j<q.c[i].size(); j++) cout << q.c[i][j] <<  " ";
            int s = q.c[i][0];
            int to_find = a[s];
            // cout << "arr: " << to_find << endl;

            for(int j=0; j<q.c[i].size(); j++){
                if(q.c[i][j] == to_find){
                    if(j==0) break;
                    rem.push_back(j);
                    len.push_back(q.c[i].size());
                    break;
                }
                if(j == q.c[i].size()-1){
                    return false;
                }
            }
            
        }

        int lcm_curr=rem[0], gcd_curr=len[0], ans;
        for(int i=0; i<rem.size(); i++){
            cout << rem[i] << " " << len[i] << endl;
            if(rem[i] == 0) continue;
            lcm_curr = lcm(lcm_curr, rem[i]) % 1000000009;
            gcd_curr = gcd(gcd_curr, len[i]) % 1000000009;
            
            ans = lcm_curr % 1000000009;
            // cout << ans << endl;
            if (ans%gcd_curr != rem[i]%gcd_curr){
                return false;
            }
        }

        rem.clear();
        len.clear();
        return true;
    }
    int log(permutation const &q) const{
        int diff = 0;
        vector <int> rem;
        vector <int> len;

        int pi=0;

        for(int i=0; i<q.c.size(); i++){
            int s = q.c[i][0], tc = q.a[s];
            int b = a[s], r=0;
            while(s != b){
                b = a[b];
                r++;
            }

            rem.push_back(r % c[i].size());
            len.push_back(c[i].size());
        }

        // for(int i=0; i<q.c.size(); i++){
        //     // for(int j=0; j<q.c[i].size(); j++) cout << q.c[i][j] <<  " ";
        //     int s = q.c[i][0];
        //     int to_find = a[s];
        //     // cout << "arr: " << to_find << endl;

        //     for(int j=0; j<q.c[i].size(); j++){
        //         if(q.c[i][j] == to_find){
        //             if(j==0) break;
        //             rem.push_back(j);
        //             len.push_back(q.c[i].size());
        //             break;
        //         }
        //         if(j == q.c[i].size()-1){
        //             return 0;
        //         }
        //     }
            
        // }
        // cout << "ahudhausdh\n";

        int lcm_curr=rem[0], gcd_curr=len[0], ans=1;
        for(int i=0; i<rem.size(); i++){
            cout << rem[i] << " " << len[i] << endl;
            if(rem[i] == 0) continue;

            lcm_curr = lcm(lcm_curr, rem[i]);
            gcd_curr = gcd(gcd_curr, len[i]);
            
            ans = lcm_curr;
            // cout << ans << endl;
            if (ans%gcd_curr != rem[i]%gcd_curr){
                return 0;
            }
        }

        rem.clear();
        len.clear();
        return ans%1000000009;
    }

    void printperm(){
        for(int i=0; i<n; i++) std::cout << a[i] << " "; std::cout << '\n';
        return;
    }
};