#include<bits/stdc++.h>
typedef long long ll;
using namespace std;

struct node{
    char data;
    node *left, *right;
};

node *newNode(int data){
    node *n = new node();
    n->data = data;
    n->left = NULL;
    n->right = NULL;
    return n;
}

int step(node* root){
    if(root->data == 'e') return 0;
    int ans=0;

    if(root->left->data != 'e'){
        ans += step(root->left);
        if(root->left->data != root->data) ans++;
    } 
    if(root->right->data != 'e'){
        ans += step(root->right);
        if(root->right->data != root->data) ans++;
    }
    return ans;
}

int time(node *root){
    if(root->data == 'e') return 0;
    int ans=0;
    int a = time(root->left), b = time(root->right);

    if(root->left->data != 'e'){
        if(root->left->data != root->data) a += 1;
    }
    if(root->right->data != 'e'){
        if(root->right->data != root->data) b += 1;
    }

    return max(a,b);
}

int step2(node *root, int k){
    int zero, ans, left, right;

    if(root->data == 'e') return 0;
    int d = root->data, dl = root->left->data, dr = root->right->data;

    left = step2(root->left, k);
    right = step2(root->right, k);

    if(dl == 'e'){
        return right + 1;
    }else if(dr == 'e'){
        return left + 1;
    }

    if(d == dl && d == dr){
        if(right + left + 1 < k){
            return left+right+1;
        }else{
            if(left < right){
                return right + 1; // Check this
            }else{
                return left + 1;
            }
        }
    }else if(dl==dr){
        return left+right+1;
    }else{
        if(d == dl){
            if(left+1 < k) return right + 1;
            else return left + right + 1;
        }else if(d == dr){
            if(right+1 < k) return left + 1;
            else return left + right + 1;
        }
    }
    return left + right + 1;
}

/*
stp step2(node *root, int k){
    stp zero, ans, left, right;
    zero.a=0, zero.b=0;

    if(root->data == 'e') return zero;

    int d=root->data, dl=root->left->data, dr=root->right->data;

    if(dl == 'e' && dr == 'e'){
        stp temp = zero;
        temp.b = 1;
        return temp;
    }

    if(d == dl){
        left = step2(root->left, k);
        left.b++;
        // left.a = logbase(left.b, k);
    }else{
        if(dl == 'e'){
            left = zero;
        }else{
            left = step2(root->left, k);
            left.a++;
            left.b = 1;
        }
    }

    if(d == dr){
        right = step2(root->right, k);
        right.b++;
        // right.a = logbase(right.b, k);
    }else{
        if(dr == 'e'){
            right = zero;
        }else{
            right = step2(root->right, k);
            right.a++;
            right.b = 1;
        }
    }

    if(dl != 'e' && dr != 'e'){
        if(d == dl && d == dr){
            // All same
            // cout << left.b << " " << right.b << endl;
            ans.b = left.b + right.b - 1;
            ans.a = left.a + left.a + 1;
            if(ans.b >= k){
                ans.a++;
                ans.b -= k;
            }
        }else if(dl == dr){
            // children same but not with root
            ans.a = left.a + right.a-2;
            // cout << left.a << "\ttest\n";
            ans.b = 1;
        }else{
            if(left.a > right.a){
                ans = left;
            }else{
                ans = right;
            }
        }
    }else{
        if(dl == 'e'){
            ans = right;
            if(ans.b >= k){
                ans.a++;
                ans.b-=k;
            }
        }
        else{
            ans = left;
            if(ans.b >= k){
                ans.a++;
                ans.b-=k;
            }
        }
    }

    cout << ans.a << " " << ans.b << endl;
    return ans;
}
*/

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string s;
    cin >> s;

    stack <node*> st;
    node *root;

    for(int i=0; i<s.length(); i++){
        if(s[i]=='e'){
            node *temp = newNode(s[i]);
            st.push(temp);
        }
        else if(s[i]=='*' || s[i]=='+'){
            node *temp = newNode(s[i]);
            temp->right = st.top();
            st.pop();
            temp->left = st.top();
            st.pop();
            st.push(temp);
            if(i == s.length()-1) root = temp;
        }
    }
    
    if(s == "e"){
        cout << "0 0" << endl;
    }else{
        cout << step(root)+1 << " " << time(root)+1 << endl;
    }
    
    
    int t, k;
    cin >> t;
    while(t--){
        cin >> k;
        cout << step2(root, k) << endl;
        // cout << "0 0" << endl;
    }
}