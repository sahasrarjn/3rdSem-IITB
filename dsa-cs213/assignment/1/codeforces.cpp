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
        bool visited[n];
        // memset(visited, false, s);
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
                // for(int t=0; t<temp.size(); t++) cout << temp[t]  <<  "h\t "; cout << endl;
                c.push_back(temp);
                temp.clear();
            }
        }

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
    
    // Error, Seg Fault
    // permutation const square_root() const{
    //     if(n == 1){
    //         return *this;
    //     }

    //     int *iden_arr = new int[n];
    //     for(int i=0; i<n; i++) iden_arr[i] = i;
    //     permutation identity(n, iden_arr);
    //     delete []iden_arr;

    //     std::vector<int> final;
    //     std::vector < std::vector<int> > left;

    //     bool visited[n];
    //     for(int i=0; i<n; i++){
    //         if(visited[i] == true) continue;

    //         std::vector<int> temp;
    //         int c = i, l = 1;
    //         visited[c] = true;
    //         temp.push_back(c);
    //         c = a[c];
            
    //         while(c != i){
    //             l++;
    //             temp.push_back(c);
    //             visited[c] = true;
    //             c = a[c];
    //         }

    //         // for(int i=0; i<temp.size(); i++) std::cout << temp[i] << "    "; std::cout << '\n';

    //         if(l%2 == 1){
    //             int t = 0;
    //             while(t<l/2){
    //                 final.push_back(temp[t]);
    //                 final.push_back(temp[t+l/2+1]);
    //                 t++;
    //             }
    //             final.push_back(temp[l/2]);
    //         }else{
    //             left.push_back(temp);
    //         }
    //         // for(int i=0; i<final.size(); i++) std::cout << final[i] << "    "; std::cout << '\n';

    //         temp.clear();
    //     }

    //     if((left.size() > 0) && (left.size()%2==0)) return identity;

    //     std::sort(left.begin(), left.end(), sortSize);

    //     for(int i=1; i<left.size(); i+=2){
    //         if(left[i].size() == left[i-1].size()){
    //             for(int j=0; j<left[i].size(); j++){
    //                 cout << left[i-1][j] << " " << left[i][j] << endl;
    //                 final.push_back(left[i-1][j]);
    //                 final.push_back(left[i][j]);
    //             }
    //         }else{
    //             return identity;
    //         }
    //     }

    //     for(int i=0; i<final.size(); i++) std::cout << final[i] << "     "; std::cout << '\n';


    //     int *final_arr = new int[n];

    //     for(int i=0; i<n-1; i++){
    //         final_arr[ final[i] ] = final[i+1];
    //     }final_arr[ final[n-1] ] = final[0];

    //     permutation *ans = new permutation(n, final_arr);
    //     delete []final_arr;
    //     left.clear();
    //     final.clear();

    //     return *ans;
    // }

    permutation const operator^(long long pwr) const{
        permutation *q = new permutation(*this);
        q->n = n;
        
        bool visited[n];
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
            // cout << rem[i] << " " << len[i] << endl;
            if(rem[i] == 0) continue;
            lcm_curr = lcm(lcm_curr, rem[i]) % 1000000009;
            gcd_curr = gcd(gcd_curr, len[i]) % 1000000009;
            
            ans = lcm_curr % 1000000009;
            // cout << ans << endl;
            if (ans%gcd_curr != rem[i]%gcd_curr){
                return false;
            }
        }

        return true;
    }
    int log(permutation const &q) const{
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
                    return 0;
                }
            }
            
        }

        int lcm_curr=rem[0], gcd_curr=len[0], ans;
        for(int i=0; i<rem.size(); i++){
            // cout << rem[i] << " " << len[i] << endl;
            if(rem[i] == 0) continue;

            lcm_curr = lcm(lcm_curr, rem[i]) % 1000000009;
            gcd_curr = gcd(gcd_curr, len[i]) % 1000000009;
            
            ans = lcm_curr % 1000000009;
            // cout << ans << endl;
            if (ans%gcd_curr != rem[i]%gcd_curr){
                return 0;
            }
        }

        return ans%1000000009;
    }

    void printperm(){
        for(int i=0; i<n; i++) std::cout << a[i]+1 << " "; std::cout << '\n';
        return;
    }

    
};

int main(){
    int n;
    cin >> n;

    int a[n];
    for(int i=0; i<n; i++){
        cin >> a[i];
        a[i]--;
    }

    permutation p(n, a);
    permutation q = p.square_root();
    q.printperm();
}