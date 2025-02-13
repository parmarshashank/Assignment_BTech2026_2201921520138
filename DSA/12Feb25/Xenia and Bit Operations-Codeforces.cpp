#include <bits/stdc++.h>
using namespace std;
vector<int> seg;
int n;

void build(int ind, int low, int high, bool orr, vector<int> &a){
    if(low==high){
        seg[ind]= a[low];
        return;
    }
    int mid= (low+high)/2;
    build(2*ind+1, low, mid, !orr, a);  
    build(2*ind+2, mid+1, high, !orr, a);
    if(orr)
        seg[ind]= seg[2*ind+1] | seg[2*ind+2];
    else
        seg[ind]= seg[2*ind+1] ^ seg[2*ind+2];

}

void update(int ind, int low, int high, int index, int val, bool orr){
    if(low==high){
        seg[ind]= val;
        return;
    }
    int mid= (low+high)/2;
    if(index<=mid)
        update(2*ind+1, low, mid, index, val, !orr);
    else
        update(2*ind+2, mid+1, high, index, val, !orr);
    if(orr) 
        seg[ind]= seg[2*ind+1] | seg[2*ind+2];
    else
        seg[ind]= seg[2*ind+1] ^ seg[2*ind+2];
}
void solve(){
    int n, m;
    cin>> n >> m;
    vector<int> a(1<<n);
    for(int i=0; i<(1<<n); i++){
        cin>> a[i];
    }
    vector<vector<int>> queries;
    for(int i=0; i<m; i++){
        int p, b;
        cin>> p >> b;
        queries.push_back({p, b});
    }
    int size= 1<<n;
    seg.resize(4*size);
    build(0, 0, size-1, n%2!=0, a);
    for(auto q: queries){
        update(0, 0, size-1, q[0]-1, q[1], n%2!=0);
        cout<< seg[0]<< endl;
    }
}
int main(){
    solve();
    return 0;
}