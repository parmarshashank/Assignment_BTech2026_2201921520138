#include<bits/stdc++.h>
using namespace std;

class info{
    public:
    int open, close, full;
    info(){
        open= close= 0;
        full= 0;
    }
    info(int o, int c, int f){
        open= o;
        close= c;
        full= f;
    }
};

info merge(info left, info right){
    info ans;
    ans.full= left.full+ right.full+ min(left.open, right.close);
    ans.open= left.open+ right.open- min(left.open, right.close);
    ans.close= left.close+ right.close- min(left.open, right.close);
    return ans;
}
void build(int i, int low, int high, string &s, vector<info> &seg){
    if(low==high){
        seg[i]= info(s[low]=='(', s[low]==')', 0);
        return;
    }
    int mid= (low+high)/2;
    build(2*i+1, low, mid, s, seg);
    build(2*i+2, mid+1, high, s, seg);
    seg[i]=merge(seg[2*i+1], seg[2*i+2]);
}

info query(int i, int low, int high, vector<info>&seg, int l, int r){
    if(low>=l && high<=r)
        return seg[i];
    if(high<l || low>r)
        return info(0, 0, 0);
    int mid= (low+high)/2;
    info left= query(2*i+1, low, mid, seg, l, r);
    info right= query(2*i+2, mid+1, high, seg, l, r);
    return merge(left, right);
}

void solve(){
    string s;
    cin>> s;
    int n= s.size();
    int m;
    cin>> m;
    vector<info> seg(4*n);
    build(0, 0, n-1, s, seg);

    while(m--){
        int l, r;
        cin>> l >> r;
        cout<< 2*query(0, 0, n-1, seg, l-1, r-1).full<< endl;
    }
}
int main(){
    solve();
    return 0;
}