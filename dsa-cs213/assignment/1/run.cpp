/// #include<bits/stdc++.h>
#include<random>
#include "assignment.h"
using namespace std;


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    n = 10;


    int a[n], b[n];
    // fori(i, n){
        // cin >> a[i];
        // a[i]--;
    // }

    // fori(i, n) cin >> b[i];
    for(int i=0; i<n; i++) a[i] = n-i-1;
    // for(int i=0; i<n; i++) a[i] = 99-i;
    // a[n-1] = 0;

    // cout << 134 << endl;


    // unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    // rand(time(0));
    // shuffle_array(a, n);

    // cout << "test1\n";
    permutation p(n, a);
    // p.printperm();
    // permutation e = p;
    // permutation e(p);


    // permutation q(p);
    permutation p3 = p^4;
    permutation p2 = (p*p);
    // permutation root = p2.square_root();

    // p2.printperm(); 
    // root.printperm();
    // cout << e.size() << '\n';

    // int *arr = p.to_array();
    // for(int i=0; i<n; i++) cout << arr[i] << " "; cout << '\n';

    // cout << "test2\n";
    // cout << "5\n";
    // permutation q = p^3; // Not working
    // permutation t = p.square_root();
    // permutation pinv = -p;
    // p.printperm();
    // permutation p2 = p^2;
    // p2.printperm();
    // permutation p3 = p*p;
    // p3.printperm();
    // p2.printperm();
    // cout << endl;
    // p.printperm();
    // permutation p4 = p*p;
    
    // permutation p5 = p4.square_root();
    // cout << endl;
    // p5.printperm();

    // p.printperm();
    // p2.printperm();
    // q.printperm();
    // t.printperm();
    // pinv.printperm();
    // p4.printperm();
    // cout << p.log(p) << endl;
    cout << p2.log(p) << endl;
    // cout << p3.log(p) << endl;
    // int out = p.log(q);
    // cout << out << endl;

}
