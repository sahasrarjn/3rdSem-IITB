#include<bits/stdc++.h>

#include<numeric>
using namespace std;

typedef long long ll;
// #define ll long long
#define pmod 1000000009
#define it(m) for(auto it=m.begin(); it!=m.end(); it++)
#define fori(i, n) for(int i=0; i<n; i++)
#define print(x) cout << x << endl;

bool sortBySize(vector<int> &a, vector<int> &b){
	return a.size() > b.size();
}

ll gcd(ll a, ll b){ 
    if (a == 0) 
        return b;  
    return gcd(b % a, a);  
} 

ll lcm(ll a, ll b)  
{  
    return (a*b)/gcd(a, b);  
}


class permutation{
    int s, *arr;
    vector< vector<int> > c;

    void makeCycles();

    // void decompose(long long i);
public:
    // Constructors and Destructors
    permutation(int n, int *a);
    permutation(permutation const &q); 
    permutation const operator=(permutation const &q);
    ~permutation();

    // Public functions
    int size() const;
    int* to_array() const;
    permutation const operator-() const;
    permutation const operator*(permutation const &q) const;
    permutation const square_root() const;
    permutation const operator^(long long i) const;
    bool is_power(permutation const &q) const;
    int log(permutation const &q) const;

    void printperm(){
        fori(i, s){
            cout << arr[i] << " ";
        }
        cout << endl;
        return;
    }
};


void permutation::makeCycles(){
    bool visited[s];
    memset(visited, false, s);

    for(int i=0; i<s; i++){
        if(!visited[i]){
            vector<int> temp;

            int j=arr[i];
            temp.push_back(i);
            visited[i]=true;

            while(j!=i){
                visited[j] = true;
                temp.push_back(j);
                j=arr[j];
            }       
            // for(int t=0; t<temp.size(); t++) cout << temp[t]  <<  "h\t "; cout << endl;
            c.push_back(temp);
            temp.clear();
        }
    }

    sort(c.begin(), c.end(), sortBySize);
    return;
}

permutation::permutation(int n, int a[]){
    s = n;
    arr = new int[n];

    for(int i=0; i<n; i++){
        arr[i] = a[i];
    }

    makeCycles();
}


permutation::permutation(permutation const &q){
    s = q.s;

    arr = new int [s];
    for(int i=0; i<s; i++){
        arr[i]=q.arr[i];
    }

    makeCycles();
}

permutation const permutation::operator=(permutation const &q){
    permutation ans(q);
    return q;
}

permutation::~permutation(){
    delete []arr;
    c.clear();
}

int permutation::size() const{
    return s;
}

permutation const permutation::operator-() const{
    int rev[s];

    for(int i=0; i<s; i++){
        rev[arr[i]] = i;
    }

    return permutation(s, rev);
}

int* permutation::to_array() const{
    return arr;
}

permutation const permutation::operator*(permutation const &q) const{
    int temp[s];

    fori(i, s){
        temp[i] = arr[q.arr[i]];
    }

    permutation r(s, temp);

    return r;
}

permutation const permutation::square_root() const{
    if(s==1){
        permutation finalPerm(1, arr);
		return finalPerm;
	}

	vector<int> ans;
	int finalAns[s];

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
            int iden[s];
            for(int i=0; i<s; i++){
                iden[i] = i;
            }
            permutation finalPerm(s,iden);
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

    permutation finalPerm(s, finalAns);

	return finalPerm;
}

// permutation const permutation::operator^(long long i) const{
//     // permutation temp(s, to_array());
//     // permutation ans = *this;
//     // permutation temp = *this;

//     // for(int j=0; j<i; j++){
//     //     ans = ans*temp;
//     // }
//     // permutation tem

//     // return ;
//     return *this;
// }

permutation const permutation::operator^(long long f) const{
    int aray[s];

    // decompose(long long f);

    for(int i=0; i<c.size(); i++){
        int rem = f%c[i].size();
        vector<int> fnl;

        if(rem == c[i].size()){
            for(int j=0; j<c[i].size(); j++){
                cout << c[i][j] << " ";
                fnl.push_back(c[i][j]);
            }
            cout << endl;

            for(int j=0; j<c[i].size()-1; j++){
                aray[ fnl[j] ] = fnl[j+1];
            }
            aray[ fnl[ fnl.size()-1 ] ]= fnl[0];
            continue;
        }

        vector<int> temp;

        int step = c[i].size();

        int post=0;
        temp.push_back(c[i][post]);
        while(step--){
            if(post + rem >= c[i].size()) post -= c[i].size();
            temp.push_back(post + rem);
        }

        for(int j=0; j<c[i].size(); j++){
            cout << c[i][j] << " ";
            fnl.push_back(c[i][j]);
        }
        cout << endl;

        for(int j=0; j<c[i].size()-1; j++){
            aray[ fnl[j] ] = fnl[j+1];
        }
        aray[ fnl[ fnl.size()-1 ] ]= fnl[0];

        fnl.clear();
    }
    return *this;
}
//     return *this;
// }


// We'll have to store indices and then cyclic method
bool permutation::is_power (permutation const &q) const{
    ll diff = 0;
    vector <ll> rem;
    vector <ll> len;


    ll pi=0;
    for(ll i=0; i<q.c.size(); i++){
        // for(ll j=0; j<q.c[i].size(); j++) cout << q.c[i][j] <<  " ";
        ll s = q.c[i][0];
        ll to_find = arr[s];
        // cout << "arr: " << to_find << endl;

        for(ll j=0; j<q.c[i].size(); j++){
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

    ll lcm_curr=rem[0], gcd_curr=len[0], ans;
    for(ll i=0; i<rem.size(); i++){
        // cout << rem[i] << " " << len[i] << endl;
        if(rem[i] == 0) continue;
        lcm_curr = lcm(lcm_curr, rem[i]) % pmod;
        gcd_curr = gcd(gcd_curr, len[i]) % pmod;
        
        ans = lcm_curr % pmod;
        // cout << ans << endl;
        if (ans%gcd_curr != rem[i]%gcd_curr){
            return false;
        }
    }

    return true;
}

int permutation::log(permutation const &q) const{
    ll diff = 0;
    vector <ll> rem;
    vector <ll> len;


    ll pi=0;
    for(ll i=0; i<q.c.size(); i++){
        // for(ll j=0; j<q.c[i].size(); j++) cout << q.c[i][j] <<  " ";
        ll s = q.c[i][0];
        ll to_find = arr[s];
        // cout << "arr: " << to_find << endl;

        for(ll j=0; j<q.c[i].size(); j++){
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

    ll lcm_curr=rem[0], gcd_curr=len[0], ans;
    for(ll i=0; i<rem.size(); i++){
        // cout << rem[i] << " " << len[i] << endl;
        if(rem[i] == 0) continue;
        lcm_curr = lcm(lcm_curr, rem[i]) % pmod;
        gcd_curr = gcd(gcd_curr, len[i]) % pmod;
        
        ans = lcm_curr % pmod;
        // cout << ans << endl;
        if (ans%gcd_curr != rem[i]%gcd_curr){
            return 0;
        }
    }

    return ans%pmod;
}
