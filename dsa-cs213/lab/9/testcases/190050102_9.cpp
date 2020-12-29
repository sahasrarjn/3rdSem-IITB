// References: https://github.com/SnapDragon64/ACMFinalsSolutions/blob/master/finals2019/azulejosDK.cc

#include <algorithm>
#include <iostream>
#include <set>
#include <vector>
using namespace std;

struct Tile {
  int P, S, Idx;
  bool operator<(const Tile& t) const { return S < t.S; }
};

// struct T{
//     int a, b, c;
// };

// struct compare{
//     bool operator()(T const &t1, T const &t2){
//         if(t1.a == t2.a){
//             return t1.b < t2.b;
//         }
//         return t1.a < t2.a;
//     }
// };

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

    // int n;
    // cin >> n;
    // map<int, multiset<T,compare> > S1, S2;
    // vector<int> p,q;

    // T x;
    // int arr[4][n];
    // for(int i=0; i<4; i++){
    //     for(int j=0; j<n; j++){
    //         cin >> arr[i][j];
    //     }
    // }

    // vector<int> sorta, sortc;
    // for(int i=0; i<n; i++){
    //     x.a = arr[0][i];
    //     x.b = arr[1][i]+1;
    //     x.c = i+1;
    //     S1[x.a].insert(x);

    //     x.a = arr[2][i];
    //     x.b = arr[3][i];
    //     x.c = i+1;
    //     S2[x.a].insert(x);
    // }

    // vector< multiset<T,compare> > s1, s2;

    // for(auto it=S1.begin(); it != S1.end(); it++){
    //     s1.push_back(it->second);
    // }
    // for(auto it=S2.begin(); it != S2.end(); it++){
    //     s2.push_back(it->second);
    // }

    // for(int i=0; i<s1.size(); i++){
    //     for(auto it = s1[i].begin(); it!=s1[i].end(); it++){
    //         cout << it->a << " " <<it->b << " " << it->c << endl;
    //     }
    // }
    // for(int i=0; i<s2.size(); i++){
    //     for(auto it = s2[i].begin(); it!=s2[i].end(); it++){
    //         cout << it->a << " " <<it->b << " " << it->c << endl;
    //     }
    // }

    // for(int i1=0, i2=0; q.size()<n;){
    //     // cout << s1[i1].size() << " " << s2[i2].size() << endl; 
    //     if(s1[i1].size() < s2[i2].size()){
    //         for(auto t = s1[i1].begin(); t != s1[i1].end(); t++){
    //             T temp = *t;
    //             temp.b--;
    //             auto it = s2[i2].upper_bound(temp);
    //             if(it == s2[i2].begin()){
    //                 cout << "impossible" << endl;
    //                 return 0;
    //             }
    //             --it;
    //             p.push_back(t->c);
    //             q.push_back(it->c);
    //             s2[i2].erase(it);
    //         }
    //         i1++;
    //     }else{
    //         for(auto t = s2[i2].begin(); t!=s2[i2].end(); t++){
    //             auto it = s1[i1].upper_bound(*t);
    //             if(it == s1[i1].end()){
    //                 cout << "impossible" << endl;
    //                 return 0;
    //             }
    //             q.push_back(t->c);
    //             p.push_back(it->c);
    //             s1[i1].erase(it);
    //         }
    //         i2++;
    //         if(s1[i1].size() == 0) i1++;
    //     }
    // }

  int N;
  cin >> N;
  int arr1[2][N], arr2[2][N];
    vector<multiset<Tile>> v[2];
    for (int row = 0; row < 2; row++) {
      vector<Tile> T(N);
      for (int i = 0; i < N; i++){
        cin >> T[i].P;
        arr1[row][i] = T[i].P;
      } 
      for (int i = 0; i < N; i++){
        cin >> T[i].S;
        if(row == 0) T[i].S++;
        arr2[row][i] = T[i].S;
      } 
      for (int i = 0; i < N; i++) T[i].Idx = i+1;
      sort(T.begin(), T.end(), [] (const Tile& a, const Tile& b) -> bool { return a.P < b.P; });
      for (int i = 0; i < N; i++) {
        if (i == 0 || T[i-1].P != T[i].P) v[row].emplace_back();
        v[row].back().insert(T[i]);
      }
    }

    vector<int> ret[2];
    for (int i0 = 0, i1 = 0; ret[0].size() < N; ) {
      if (v[0][i0].size() < v[1][i1].size()) {
        for (auto const& t : v[0][i0]) {
          auto it = v[1][i1].upper_bound(Tile{t.P, t.S-1, t.Idx});
          if (it == v[1][i1].begin()){
            cout << "impossible" << endl;
            return 0;
          }
          --it;
          ret[0].push_back(t.Idx);
          ret[1].push_back(it->Idx);
          v[1][i1].erase(it);
        }
        i0++;
      } else {
        for (auto const& t : v[1][i1]) {
          auto it = v[0][i0].upper_bound(t);
          if (it == v[0][i0].end()){
            cout << "impossible" << endl;
            return 0;
          }
          ret[1].push_back(t.Idx);
          ret[0].push_back(it->Idx);
          v[0][i0].erase(it);
        }
        i1++;
        if (v[0][i0].size() == 0) i0++;
      }
    }

    for (int row = 0; row < 2; row++) {
      for (int i = 0; i < ret[row].size(); i++) {
        if (i) cout << ' ';
        cout << ret[row][i];
      }
      cout << endl;
    }


    bool unique=true;

    for(int i=1; i<N; i++){
      int p = ret[0][i]-1;
      int q = ret[1][i]-1;
      int lp = ret[0][i-1]-1;
      int lq = ret[1][i-1]-1;
      // cout << arr1[0][p] << arr2[0][p] << arr1[1][q] << arr2[1][q] << endl;

      if(arr1[0][p]==arr1[0][lp] && arr1[1][q]==arr1[1][lq]){
        if(arr2[0][lp] > arr2[1][q]){
          unique = false;
          break;
        }
      }else if(arr1[0][p]==arr1[0][lp] || arr1[1][q]==arr1[1][lq]){
        if(arr2[0][p] > arr2[1][lq] && arr2[0][lp] > arr2[1][q]){
          unique = false;
          break;
        }
      }else{
        continue;
      }
    }

    if(unique){
      cout << "unique" << endl;
    }else{
      cout << "not unique" << endl;
    }
  
}