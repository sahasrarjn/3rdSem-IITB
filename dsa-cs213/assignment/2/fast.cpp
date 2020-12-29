#include<bits/stdc++.h>
typedef unsigned long long ll;
using namespace std;

struct thueStr{
    string a;
    string b;
};

ll KMP(string &X, string &Y)
{
	ll m = X.length();
	ll n = Y.length();

	if (n == 0) return 0;
	
	if (m < n)  return -1;

	ll next[n + 1];
	for (ll i = 0; i < n + 1; i++)
		next[i] = 0;

	for (ll i = 1; i < n; i++)
	{
		ll j = next[i + 1];

		while (j > 0 && Y[j] != Y[i])
			j = next[j];

		if (j > 0 || Y[j] == Y[i])
			next[i + 1] = j + 1;
	}

	for (ll i = 0, j = 0; i < m; i++)
	{
		if (X[i] == Y[j])
		{
			if (++j == n)
				return i - j + 1;
		}
		else if (j > 0) {
			j = next[j];
			i--;
		}
	}
    return -1;
} 

int SubSequence(string a, string b){
	int j = 0;
	int alen = a.length();
	int blen = b.length();
	
	for(int i=0; i<a.length(); i++){
		if(a[i] == b[j]){
			j++;
		}

		if(j == blen) return i+1;
	}
	return -1;
}


class morphism{
    int k;
    string *f;
    int *baselen;
    ll mlen;
    vector<ll> *memoLen;
    string Fibo;
    string Thue;
    string *memoFibo;
    thueStr *memoThue;                                                              

public:
    morphism(int k_in, string *f_in, int *baselen_in){
        k = k_in;
        mlen = 120;                                                // Check this for optimising
        
        f = new string[k];
        memoFibo = new string[20];
        for(int i=0; i<20; i++) memoFibo[i] = "$";

        memoThue = new thueStr[20];
        for(int i=0; i<20; i++) memoThue[i].a = "$", memoThue[i].b = "$";

        baselen = new int[k];
        memoLen = new vector<ll> [k];

        for(int i=0; i<k; i++){
            for(ll j=0; j<mlen; j++){                                         
                memoLen[i].push_back(-1);
            }
        }

        for(int i=0; i<k; i++){
            f[i] = f_in[i];
            baselen[i] = baselen_in[i];
        }
    }

    ~morphism(){
        delete []f;
        delete []baselen;
        delete []memoFibo;
        delete []memoThue;
        delete []memoLen;
    }

    ll len(int n, int c){
        // cout << "test\n";
        return lenUtil(n, c);
    }

    ll lenUtil(int n, int c){
        if(memoLen[c][n] != -1) return memoLen[c][n];
        if(n==0){
            memoLen[c][n] = 1;
            return 1;
        }

        ll ans=0;
        for(int i=0; i<baselen[c]; i++){
            ans += this->lenUtil(n-1, int(f[c][i]-'a'));
        }
        memoLen[c][n] = ans;
        return ans;
    }

    char post(ll p, ll c, ll n_max){
        // cout << p << "\ttest\n";
        if(n_max == 0){
            return char('a'+c);
        }

        for(int i=0; i<baselen[c]; i++){
            ll tempLen = memoLen[ int(f[c][i]-'a') ][n_max-1];

            if(p > tempLen){
                p -= tempLen;
            }else{
                return post(p, int(f[c][i]-'a'), n_max-1);
            }
        }

        return '#';
    }

    int get_n_max(ll p, ll c){                  // May use memorization
        int n_max;
        for(int i=0; i<mlen; i++){
            if(len(i,c) >= p){
                n_max = i;
                break;
            }
        }
        // cout << p << endl;
        return n_max;
    }

    string generateFibo(int n_gen){
        if(n_gen == 0){
            memoFibo[0] = "a";
            return "a";
        }
        if(n_gen == 1){
            memoFibo[1] = "ab";
            return "ab";
        } 
        memoFibo[n_gen] = generateFibo(n_gen-1) + generateFibo(n_gen-2);
        return memoFibo[n_gen];
    }

    thueStr generateThue(int n_gen){
        if(memoThue[n_gen].a != "$") return memoThue[n_gen];
        if(n_gen == 0){
            thueStr temp;
            temp.a = "a";
            temp.b = "b";
            memoThue[0] = temp;
            return temp;
        }

        thueStr temp, temp_last;
        temp_last = generateThue(n_gen-1);
        temp.a = temp_last.a + temp_last.b;
        temp.b = temp_last.b + temp_last.a;
        memoThue[n_gen] = temp;
        return temp;
    }

    
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int k;
    cin >> k;

    string f[k];
    int baselen[k];
    for(int i=0; i<k; i++){
        cin >> f[i];
        baselen[i] = f[i].size();
    }
    morphism m = morphism(k, f, baselen);

    bool isThue=false, isFibo=false;
    if(k==2){
        if(f[0] == "ab" && f[1] == "a") isFibo = true;
        if(f[0] == "ab" && f[1] == "ba") isThue = true;
    }

    string fiboSeq, thueSeq;
    if(isFibo){
        int n_gen = 19;
        fiboSeq = m.generateFibo(n_gen);
        // cout << fiboSeq << endl;
    }

    if(isThue){
        int n_gen = 19;
        thueSeq = m.generateThue(n_gen).a;
        // cout << thueSeq << endl;
    }
    ll fiboLen = fiboSeq.length(), thueLen = thueSeq.length();


    ll t;
    cin >> t;

    int a;
    string w;
    while(t--){
        cin >> a;
        
        ll n;
        switch(a){
            case 0:
                cin >> n;
                if(n >= 120) cout << -1 << '\n';
                else cout << m.len(n, 0) << '\n';
                break;
            case 1:
                cin >> n;
                n++;
                cout << m.post(n, 0, m.get_n_max(n, 0)) << '\n';
                break;
            case 2:
                cin >> w;
                if(isFibo){
                    ll index = KMP(fiboSeq, w);
                    if(index == -1) cout << -1 << '\n';
                    else cout << m.get_n_max(index+w.length(), 0) << " " << index << '\n';
                }else if(isThue){
                    ll index = KMP(thueSeq, w);
                    if(index == -1) cout << -1 << '\n';
                    else  cout << m.get_n_max(index+w.length(), 0) << " " << index << '\n';
                }else{
                    cout << "0 0\n";
                }
                break;
            case 3:
                cin >> w;
                if(isFibo){
                    int index = SubSequence(fiboSeq, w);
                    if(index == -1) cout << "-1\n";
                    else cout << m.get_n_max(index, 0) << " " << index << '\n';
                }else if(isThue){
                    int index = SubSequence(thueSeq, w);
                    if(index == -1) cout << "-1\n";
                    else cout << m.get_n_max(index, 0) << " " << index << '\n';
                }else{
                    cout << "0 0\n";
                }
                break;
            default:
                cout << 0 << '\n';
        }
    }
}
