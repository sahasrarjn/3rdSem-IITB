#include<iostream>
#include<vector>
#include "190050097_3.h"
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<quad_tree> Q (2,quad_tree(n));
    int t;
    cin >> t;
    while(t--) {
        char c;
        cin >> c;
        switch(c) {
            case 'S':
            {   
                int id;
                int x1,y1,x2,y2;
                bool b;
                cin >> id >> x1 >> y1 >> x2 >> y2 >> b;
                Q[id].set(x1,y1,x2,y2,b);
                break;
            }
            case 'G':
            {
                int x,y,id;
                cin >> id >> x >> y;
                cout << Q[id].get(x,y) << endl;
                break;
            }
            case 'O':
            {
                int id;
                cin >> id;
                Q[id].overlap(Q[(id+1)%2]);
                break;
            }
            case 'I':
            {
                int id;
                cin >> id;
                Q[id].intersect(Q[(id+1)%2]);
                break;
            }
            case 'C':
            {
                int id;
                cin >> id;
                Q[id].complement();
                break;
            }
            case 'R':
            {
                int m;
                cin >> m;
                Q[0].resize(m);
                Q[1].resize(m);
                break;
            }
            case 'E':
            {
                int x,y,m;
                cin >> x >> y >> m;
                Q[0].extract(x,y,m);
                Q[1].extract(x,y,m);
                break;
            }
        }
    }
    cout << "Completion";
}