#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define MOD 1000000007

int main(int argc, char *argv[]) {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n,m;
    stringstream(argv[1]) >> n;
    stringstream(argv[2]) >> m;

    random_device rd;
    mt19937 random_engine(rd());
    uniform_int_distribution<int> v (0,n-1);

    cout << n << endl;
    cout << m << endl;
 
    for(int i=0;i<m;++i) {
        cout << v(rd) << " " << v(rd) << endl;
    }

    return 0;
}
