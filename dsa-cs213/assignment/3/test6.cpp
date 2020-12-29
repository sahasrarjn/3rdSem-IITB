#include<bits/stdc++.h>
#include<random>
using namespace std;

typedef long long int ll;
#define MOD 1000000007

int main(int argc, char *argv[]) {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n,t;
    stringstream(argv[1]) >> n;
    stringstream(argv[2]) >> t;

    random_device rd;
    mt19937 random_engine(rd());
    uniform_int_distribution<int> bit (0,1);
    uniform_int_distribution<int> type(0,6);
    uniform_int_distribution<int> sz (0,n);

    cout << n << endl;
    cout << t << endl;
    int current_size = n;
    for(int i=0;i<t;++i) {
        switch(type(rd)) {
            case 0:
            {
                uniform_int_distribution<int> pos (0,(1<<current_size)-1);
                cout << 'S' << " " << bit(rd) << " ";
                int x1 = pos(rd),x2 = pos(rd),y1 = pos(rd),y2 = pos(rd);
                cout << min(x1,x2) << " " << min(y1,y2) << " " << max(x1,x2) << " " << max(y1,y2) << " " << bit(rd) << endl;
                break;
            }
            case 1:
            {
                uniform_int_distribution<int> pos (0,(1<<current_size)-1);
                cout << 'G' << " " << bit(rd) << " ";
                for(int i=0;i<2;++i) {
                    cout << pos(rd) << " ";
                }
                cout << endl;
                break;
            }
            case 2:
            {
                cout << 'C' << " " << bit(rd) << endl;
                break;
            }
            case 3:
            {
                cout << 'O' << " " << bit(rd) << endl;
                break;
            }
            case 4:
            {
                cout << 'I' << " " << bit(rd) << endl;
                break;
            }
            case 5:
            {
                current_size = sz(rd);
                cout << 'R' << " " << current_size << endl;
                break;
            }
            case 6:
            {
                uniform_int_distribution<int> pos (0,(1<<current_size)-1);
                int x = pos(rd), y = pos(rd);
                int m;
                for(int i=0;i<n;++i) {
                    if((x+(1<<i)<=(1<<current_size))&&(y+(1<<i)<=(1<<current_size))) m = i;
                    else break;
                }
                cout << 'E' << " " << x << " " << y << " " <<  m << endl;
                current_size = m;
            }
        }
    }

    return 0;
}