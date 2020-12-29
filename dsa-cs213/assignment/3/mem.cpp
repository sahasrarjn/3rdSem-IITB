#include "190050102_3.h"
#include<bits/stdc++.h>
using namespace std;

int main(){
    quad_tree b = quad_tree(3);
    // quad_tree b(a);
    b.set(0, 0, 3, 3, 1);
    // cout << !(1&0) << endl;

    b.resize(5);
    b.set(1,3,2,4,1);
    b.resize(2);
    b.complement();
    b.resize(10);
    
    b.extract(1, 1, 2);

}